#include <stdio.h>
#include <stdlib.h>
#include "queue.h"



#define	MAXV		100		/* maximum number of vertices */

//array a of nodes 0-n
//each a[i] points to an adjacencyNode forming a linked-list of connected vertices.
typedef struct adjNode{
	int weight;
	int nodeIndex;
	struct adjNode* next;
} adjNode;

typedef struct graph{
	adjNode* nodes[MAXV+1];
	int nodeDegree[MAXV+1];
	int nNodes;
	bool isDirected;
}graph;

void initGraph(graph* g, bool isDirected);
void printGraph(graph* g);
void insertEdge(graph* g, int source, int destination, bool isDirected);
void readGraph(graph* g, bool isDirected);
void hardCodedGraph(graph* g, bool isDirected);
void bfs(graph* g, int startNode);
void dfs(graph* g, int startNode);

bool processed[MAXV+1];	/* which vertices have been processed */
bool discovered[MAXV+1];  /* which vertices have been found */



int main(int argc, char const *argv[])
{
	bool isDirected = FALSE;
	graph* g = malloc(sizeof(graph));
	hardCodedGraph(g,isDirected);
	//readGraph(g, isDirected);

	for(int i=0; i< g->nNodes; i++) processed[i] = FALSE;
	for(int i=0; i< g->nNodes; i++) discovered[i] = FALSE;

	bfs(g, 0);
	printf("\n");

	for(int i=0; i< g->nNodes; i++) processed[i] = FALSE;
	for(int i=0; i< g->nNodes; i++) discovered[i] = FALSE;

	dfs(g, 0);
	printf("\n");

	return 0;
}

void hardCodedGraph(graph* g, bool isDirected){
	initGraph(g,isDirected);
	g->nNodes = 4;

	insertEdge(g, 0, 2, isDirected);
	insertEdge(g, 0, 1, isDirected);
	insertEdge(g, 1, 2, isDirected);
	insertEdge(g, 2, 0, isDirected);
	insertEdge(g, 2, 3, isDirected);
	insertEdge(g, 3, 3, isDirected);
}


void initGraph(graph* g, bool isDirected)
{
	g->isDirected = isDirected;
	for(int i = 0; i<=MAXV; i++) g->nodes[i] = NULL;
	for(int i = 0; i<=MAXV; i++) g->nodeDegree[i] = 0;
}

void readGraph(graph* g, bool isDirected)
{
	int nEdges;
	int source, destination;
	initGraph(g, isDirected);
	printf("%s\n","please enter: #nodes #edges");
	scanf("%d %d", &(g->nNodes), &nEdges);
	printf("%s\n","please enter: #source #destination");
	for(int i=0; i <= nEdges; i++){
		scanf("%d %d", &source, &destination);
		insertEdge(g, source, destination, isDirected);
	}
}

void insertEdge(graph* g, int source, int destination, bool isDirected){
	adjNode* newAdjacencyNode = malloc(sizeof(adjNode));
	newAdjacencyNode->weight = 0;
	newAdjacencyNode->nodeIndex = destination;
	//place into linked-list
	newAdjacencyNode->next = g->nodes[source]; //point to old head of list
	g->nodes[source] = newAdjacencyNode; //point head to new node

	g->nodeDegree[source]++;

	if(isDirected)
	{
		insertEdge(g, destination, source, isDirected);
	}
}

void printGraph(graph* g){
	int i=0;
	adjNode* currentNode;

	for(int i =0; i< g->nNodes; i++){
		printf("%d:", i);
		currentNode = g->nodes[i];
		while(currentNode!= NULL){
			printf("%d ", currentNode->nodeIndex);
			currentNode = currentNode->next;
		}
		printf("\n");
	}
}



void bfs(graph* g, int startNode)
{
	int currentNode;
	int successorNode;
	adjNode* tmpNode;

	queue* q = malloc(sizeof(queue));
	queue_init(q);
	//add start node to queue
	enqueue(q, startNode);
	discovered[startNode] = 1;

	while(!empty_queue(q)){
		currentNode = dequeue(q);
		printf("%d ", currentNode);
		processed[currentNode] = TRUE;
		tmpNode = g->nodes[currentNode];
		//evaluate edges from current node, adding undiscovered nodes to the queue
		while(tmpNode != NULL)
		{
			successorNode = tmpNode->nodeIndex;
			if(!discovered[successorNode])
			{
				discovered[successorNode] = TRUE;
				enqueue(q, successorNode);
			}
			tmpNode = tmpNode->next;
		}
	}
}


void dfs(graph* g, int currentNode)
{
	discovered[currentNode] = TRUE;
	adjNode* tmpNode = g->nodes[currentNode];
	while(tmpNode!=NULL)
	{
		int successorNode = tmpNode->nodeIndex;
		if(!discovered[successorNode])
		{
			dfs(g,successorNode);
		}
		tmpNode = tmpNode->next;
	}
	processed[currentNode] = TRUE;
	printf("%d ", currentNode);
}










