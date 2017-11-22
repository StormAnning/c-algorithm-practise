#define QUEUESIZE 10


#define TRUE    1
#define FALSE   0

typedef int bool;

typedef struct queue{
	int queue[QUEUESIZE+1];
	int first; 
    int last; 
    int count;
} queue;

int dequeue(queue* q);
void queue_init(queue* q);
void enqueue(queue* q, int data);
void print_queue(queue* q);
int empty_queue(queue *q);
