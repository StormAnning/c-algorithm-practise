#include <stdio.h>
#include <stdlib.h>
#include "graph.h"



void hardCodedGraph(graph* g, bool isDirected){
	initGraph(g,isDirected);
	g->nNodes = 4;

	insertEdge(g, 0, 2, 3, isDirected);
	insertEdge(g, 0, 1, 3, isDirected);
	insertEdge(g, 1, 2, 3, isDirected);
	insertEdge(g, 2, 0, 3, isDirected);
	insertEdge(g, 2, 3, 3, isDirected);
	insertEdge(g, 3, 3, 3, isDirected);
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
	int source, destination, weight;
	initGraph(g, isDirected);
	printf("%s\n","please enter: #nodes #edges");
	scanf("%d %d", &(g->nNodes), &nEdges);
	printf("%s\n","please enter: #source #destination #weight");
	for(int i=0; i <= nEdges; i++){
		scanf("%d %d %d", &source, &destination, &weight);
		insertEdge(g, source, destination, weight, isDirected);
	}
}

void insertEdge(graph* g, int source, int destination, int weight, bool isDirected){
	adjNode* newAdjacencyNode = malloc(sizeof(adjNode));
	newAdjacencyNode->weight = weight;
	newAdjacencyNode->nodeIndex = destination;
	//place into linked-list
	newAdjacencyNode->next = g->nodes[source]; //point to old head of list
	g->nodes[source] = newAdjacencyNode; //point head to new node

	g->nodeDegree[source]++;

	if(isDirected)
	{
		insertEdge(g, destination, source, weight, isDirected);
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











