#define STACKSIZE       1000

typedef struct {
        int s[STACKSIZE+1];		/* body of queue */
        int top;                        /* position of top element */
        int count;                      /* number of stack elements */
} stack;

void print_stack(stack* s);
void init(stack* s);
void push(stack* s, int data);
int pop(stack* s);
int empty_stack(stack* s);