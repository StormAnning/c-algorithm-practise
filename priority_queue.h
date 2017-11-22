#define PQ_SIZE       1000

typedef struct priority_queue{
        int q[PQ_SIZE+1];		/* body of queue */
        int n;                      /* number of queue elements */
} priority_queue;


void pq_swap(priority_queue* q, int a, int b);
void pq_init(priority_queue* q);
int pq_parent(int n);
int pq_left_child(int n);
int pq_right_child(int n);
void bubble_up(priority_queue* q, int p);
void bubble_down(priority_queue* q, int p);
int extract_min(priority_queue* q);
void pq_insert(priority_queue* q, int p);
void make_heap(priority_queue* q, int array[], int n);