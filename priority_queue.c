#include <stdio.h>
#include <stdlib.h>
#include "priority_queue.h"



void pq_init(priority_queue *q)
{
	q->n = 0;
}

int pq_parent(int n)
{
	if(n ==1) return -1;
	return ((int)n/2);
}

int pq_left_child(int n)
{
	return n*2;
}

int pq_right_child(int n)
{
	return n*2+1;
}


void bubble_up(priority_queue* q, int p)
{
	if(pq_parent(p) == -1){return;} //at root
	if(q->q[pq_parent(p)] > q->q[p])
	{
		pq_swap(q, p, pq_parent(p));
		bubble_up(q, pq_parent(p));
	}
}


void bubble_down(priority_queue* q, int p) //min heapify
{
	int lightestIndex;
	if(pq_right_child(p) >= q->n){ //MAKE SURE ACTUALLY HAS A RIGHT CHILD
		return;
	}
	if(q->q[pq_left_child(p)] < q->q[pq_right_child(p)]){
		lightestIndex = pq_left_child(p);
	}else{
		lightestIndex = pq_right_child(p);
	}
	
	if(q->q[lightestIndex] < q->q[p])
	{
		pq_swap(q, lightestIndex, p);
		bubble_down(q, lightestIndex);
	}
}

//increment size of the queue and insert element at the end!
void pq_insert(priority_queue* q, int p){ //O(lg(n))
	if(q->n >= PQ_SIZE)
		printf("PQ FULL");
	else{
		q->n = q->n+1;
		q->q[q->n] = p;
		bubble_up(q, q->n);
	}
}

//return top of heap
//replace removed item with last and bubble down to restore heap
int extract_min(priority_queue* q) //O(lg(n))
{
	int item = -1;
	if(q->n <= 0)
		printf("PQ is empty");
	else{
		item = q->q[1];
		q->q[1] = q->q[q->n];
		q->n = q->n - 1; //clips off old element
		bubble_down(q, 1);
	}
	return item;
}

void make_heap(priority_queue* q, int array[], int n){  //O(n.lg(n)) use less calls than n though...
	q->n = n;
	for(int i = 0; i < n; i++){
		q->q[i+1] = array[i];
	}
	for(int i = q->n; i >= 1; i--){
		bubble_down(q, i);
	}
}

void pq_swap(priority_queue* q, int a, int b)
{
	int tmp = q->q[a];
	q->q[a] = q->q[b];
	q->q[b] = tmp;
}