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

void main(){
	node* head=getNode;
	head->data = 0;
	head->next = NULL;
	node* rear = NULL;

	printf("Choices: 1.Insert 2.Delete 3.Display 4.Display Head 5.Exit\n");
	while(1){
		printf("Choice: ");
		int ch; scanf("%d",&ch);
		switch(ch){
			case 1: printf("Enter Data: ");
					int ele; scanf("%d",&ele);
					insert(&rear,ele);
					if(!(head->data)){
						head->next=rear;
					}
					head->data++;
					break;
			case 2: ele = delete(&head);
					if(ele){
						printf("Dequeued: %d\n",ele);
					}
					break;
			case 3: display(head->next);
					break;
			case 4: printf("No. of elements: %d, next node: %p\n",head->data,head->next); break;
			default: exit(0);
		}
	}
}
