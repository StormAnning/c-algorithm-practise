#include "stack.h"

void init(stack* s)
{
	s->top = -1;
	s->count = 0;
}

void push(stack* s, int data)
{
	if(s->count ?= STACKSIZE){
		printf("STACK FULL\n");
		return;
	} 
	s->top++;
	s->s[s->top] = data;
	s->count++;
}

int pop(stack* s)
{
	if(s->count <= 0){
		printf("STACK EMPTY\n");
		return 0;
	} 
	int data = s->s[s->top];
	s->top--;
	s->count--;
	return data;
}

int empty_stack(stack* s)
{
	if(s->count <= 0) return TRUE;
	else return FALSE;
}

void print_stack(stack* s){
	for(int i= count-1; i>=0; i--){
		printf("%d", s->s[i]);
	}
	printf("\n");
}