#include <stdio.h>
#include <stdlib.h>
#define getNode (node*)malloc(sizeof(node*))

struct NODE{
	int data;
	struct NODE* next;
};

typedef struct NODE node;

node* insert(node* rear, int x){
	node* t = getNode;
	t->data = x;
	t->next = NULL;
	if(rear == NULL){
		return t;
	}
	rear->next = t;
	return t;
}

void display(node* rear){
	printf("DISPLAY LIST\n");
	if(rear == NULL){
		printf("List is Empty.\n");
		return;
	}
	while(rear->next!=NULL){
		printf("%d ",rear->data);
		rear = rear->next;
	}
	printf("%d\n",rear->data);
}

node* delete(node* rear, int k){
	node* n = NULL;
	node* m = getNode; int g=1;
	while(rear!=NULL){
		if(rear->data >= k){
			n = insert(n,rear->data);
			if(g){
				m->next = n;
				g=0;
			}
		}
		rear = rear->next;
	}
	if(n==NULL){
		return NULL;
	}
	return m->next;
}

void main(){
	node* front = NULL;
	node* rear = NULL;
	printf("Choices: 1.Insert 2.Display 3.Exit\n");
	int i=1, g=1;
	while(i){
		printf("Choice: ");
		int ch; scanf("%d",&ch);
		switch(ch){
			case 1: printf("Element: "); int ele; scanf("%d",&ele);
					rear = insert(rear, ele);
					if(g){
						front = rear;
					}g=0; break;
			case 2: display(front); break;
			default: i=0;
		}
	}
	printf("Enter k: "); int k; scanf("%d",&k);
	front = delete(front,k);
	printf("Final List:\n");
	display(front);
}