#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"


void print_linked_list(node* head){
	node* cursor = head;
	while(cursor != NULL){
		printf("%d\n", cursor->data);
		cursor = cursor->next;
	}
}

node* search(node* head, int data){
	node* cursor = head;
	while(cursor != NULL){
		if(cursor->data == data){
			return cursor;
		}
		cursor = cursor->next;
	}
	return NULL;
}

node* create(int data, node* next){
	node* new_node = (node*)malloc(sizeof(node));
	if(new_node == NULL){
		printf("Error creating node");
		exit(0);
	}
	new_node->data = data;
	new_node->next = next;
	return new_node;
}

node* prepend(node* head, int data){
	node* new_node = create(data,head);
	head = new_node;
	return head;
}

node* append(node* head,int data){
	node *cursor = head;
	while(cursor->next != NULL){
		cursor = cursor->next;
	}
	node* new_node = create(data, NULL);
	cursor->next = new_node;
	return head;
}

node* remove_front(node* head){
	if(head == NULL){
		return NULL;
	}
	node*  front = head;
	head = head->next;
	front->next = NULL;
	if(front == head){
		head = NULL;
	}
	free(front);
	return head;
}

node* remove_back(node* head){
	if(head == NULL){
		return NULL;
	}
	node* cursor;
	node* back = NULL;
	while(cursor->next != NULL){
		back = cursor;
		cursor = cursor->next;
	}
	if(back != NULL){
		back->next = NULL;
	}
	if(cursor == head){
		head = NULL;
	}
	free(cursor);
	return head;
}


