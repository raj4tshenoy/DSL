#include <stdio.h>
#include <stdlib.h>
#define getNode (node*)malloc(sizeof(node))

struct NODE{
	int data;
	struct NODE* next;
};
typedef struct NODE node;

void insert(node** rear, int ele){
	node* t = getNode;
	t->data = ele;
	t->next = NULL;
	if(*rear == NULL){
		*rear = t;
		return;
	}
	else{
		(*rear)->next = t;
		*rear = t;
	}
}

int delete(node** head){
	node* todel = (*head)->next;
	if(todel==NULL){
		return 0;
	}
	int ele = todel->data;
	(*head)->next = (*head)->next->next;
	free(todel);
	return ele;
}

void display(node* current){
	printf("DISPLAY:\n");
	if(current==NULL){
		printf("Empty list\n");
		return;
	}
	while(current!=NULL){
		printf("%d ",current->data);
		current = current->next;
	}
	printf("\n");
}