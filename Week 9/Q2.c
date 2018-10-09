#include <stdio.h>
#define getNode (node*)malloc(sizeof(node*))

struct NODE{
	int data;
	struct NODE* left;
	struct NODE* right;
};

typedef struct NODE node;

//inserting to front of dll with header

node* ins_front(node* first, int x){
	node* t = getNode;
	t->data = x; t->right = first -> right;
	first->right = t;
	t->left = first;
	t->right->left = t; 
	return first;
}

node* ins_rear(node* first, int x){
	node* t = getNode;
	t->data = x;
	t->left = first->left;
	t->right = first;
	first->left->right = t;
	first->left = t;
	return first;
}

node* del_front(node* first){
	if(first->right = first){ //if empty, return node.
		printf("No nodes to delete.\n");
		return first;
	}
	node* t = first->next;
	first->right = t->right;
	t->right->left = first;
	free(t);
}

node* del_rear(node* first){
	if(first->right = first){ //if empty, return node.
		printf("No nodes to delete.\n");
		return first;
	}
	node* t = first;
	while(t->next!=first){
		t = t->next;
	}
	t->left->right = t->right;
	free(t);
}

void display(){
	
}

void main(){
	node* head=getNode;
	head->data = 0;
	head->next = NULL;
	node* rear = NULL;

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