#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

//size = 5
//0-4
//last = 4
//enqueue = 4+1 % 5 = 0

void queue_init(queue* q)
{
	q->first = 0;
	q->last = QUEUESIZE-1; //on enquque first call will place element in index 0
	q->count = 0;
}

void enqueue(queue* q, int data)
{
	if(q->count >= QUEUESIZE){
		printf("%s\n", "overflow on enqueue");
	}else{
		q->last = (q->last+1) % QUEUESIZE;
		q->queue[q->last] = data;
		q->count = q->count + 1;
	}
}

int dequeue(queue* q)
{
	int data;
	if(q->count<=0) printf("EMPTY");
	else{
		data = q->queue[q->first];
		q->first = (q->first + 1) % QUEUESIZE;
		q->count = q->count-1;
	}
	return data;
}

void print_queue(queue* q){
	int i = q->first;
	while(i != q->last){
		printf("%d ", q->queue[i]);
		i = (i + 1) % QUEUESIZE;
	}
	printf("%d ", q->queue[i]); //print last 
	printf("\n");
}

int empty_queue(queue *q)
{
        if (q->count <= 0) return (TRUE);
        else return (FALSE);
}

