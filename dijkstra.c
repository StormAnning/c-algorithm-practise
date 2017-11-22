#include <stdlib.h>
#include <stdio.h>
#include "priority_queue.h"
#include "graph.h"

#define MAXINT 10007

int parent[1000]; 
void dijkstra(graph *g, int start);

int main(int argc, char const *argv[])
{
	bool isDirected = FALSE;
	graph* g = malloc(sizeof(graph));
	initGraph(g,TRUE);
	g->nNodes = 7;

	insertEdge(g, 0, 1, 4, isDirected);
	insertEdge(g, 0, 4, 7, isDirected);
	insertEdge(g, 0, 2, 3, isDirected);

	insertEdge(g, 1, 3, 5, isDirected);
	insertEdge(g, 1, 2,6, isDirected);

	insertEdge(g, 2, 3, 11, isDirected);
	insertEdge(g, 2, 4, 8, isDirected);

	insertEdge(g, 3, 4, 2, isDirected);
	insertEdge(g, 3, 5, 2, isDirected);
	insertEdge(g, 3, 6, 10, isDirected);

	insertEdge(g, 4, 6, 5, isDirected);

	insertEdge(g, 5, 6, 3, isDirected);

	int array[10] = {11, 54,23,11,66,88,14,300,21,83};
	priority_queue* q = malloc(sizeof(priority_queue));
	pq_init(q);
	make_heap(q, array, 10);

	dijkstra(g, 0);

	return 0;
}
//use a heap more effective!
void dijkstra(graph *g, int start){ //O(n^2)
	adjNode* p;
	bool discovered[MAXV];
	bool distance[MAXV];
	int v; //current vertex
	int candidateNextVertex;
	int weight;
	int dist; //best current distance from start

	for(int i = 1; i <= g->nNodes; i++){
		discovered[i] = FALSE;
		distance[i] = MAXINT;
		parent[i] = -1;
	}


	distance[start] = 0;
	v = start;
	while(discovered[v] == FALSE){ //better to use a HEAP!!
		discovered[v] = TRUE;
		p = g->nodes[v];
		while(p != NULL){
			candidateNextVertex = p->nodeIndex;
			weight = p->weight;
			if(distance[candidateNextVertex] > (distance[v] + weight)){
				distance[candidateNextVertex] =  (distance[v] + weight);
				parent[candidateNextVertex] = v;
			}
			p = p->next;
		}

		//get next min node to move to
		v = 1;
		dist = MAXINT;
		for(int i = 1; i < g->nNodes; i++){
			if((discovered[i] == FALSE) && (dist > distance[i])){
				dist = distance[i];
				v = i;
			}
		}
	}


	for(int i=0; i < g->nNodes; i++){
		printf("%d - %d\n", i, distance[i]);
	}
}



