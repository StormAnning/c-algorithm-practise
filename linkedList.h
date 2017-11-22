typedef struct node{
    int data;
    struct node* next;
} node;

node* create(int data, node* next);
node* prepend(node* head, int data);
node* append(node* head, int data);
node* remove_back(node* head);
node* remove_front(node* head);
node* search(node *head, int data);
void print_linked_list(node* head);