#define TRUE    1
#define FALSE   0

typedef int bool;


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
void insertEdge(graph* g, int source, int destination, int weight, bool isDirected);
void readGraph(graph* g, bool isDirected);
void hardCodedGraph(graph* g, bool isDirected);

