#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define getNode (node*)malloc(sizeof(node))

typedef struct node{
	char data[32];
	struct node* right;
	struct node* left;
}node;


/******************************************************************************
insert FUNCTION: appends new node to the last node in the list. ie, appends to 
******************************************************************************/
void insert(node** f, char ele[]){
	node* t = getNode;
	strcpy(t->data,ele);
	t->right = NULL;
	t->left = NULL;
	if(*f==NULL){
		*f = t;
		return;
	}
	node* i = *f;
	while(i->right!=NULL){
		i=i->right;
	}	
	i->right = t;
	t->left = i;
}

/******************************************************************************
Delete FUNCTION - Deletes last node of doubly linked list
******************************************************************************/
void delete(node** f){
	node* t = *f;
	if(*f==NULL) return;
	if((*f)->right==NULL){
		*f = NULL; free(t);
		return;
	}
	while(t->right!=NULL) t = t->right;
	t->left->right = NULL;
	free(t);
}

/******************************************************************************
display FUNCTION: displays doubly linked list.
******************************************************************************/
void display(node* f){
	if(f==NULL)
		{return;}
	printf("DISPLAY:\n");
	while(f){
		printf("%s ",f->data);
		f=f->right;
	}
}

/******************************************************************************
Reverse Function reverses doubly linked list.
******************************************************************************/
void reverse(node** f){
	node* t = *f; node* temp;
	while(t){
		temp = t->right;
		t->right = t->left;
		t->left = temp;
		temp = t;
		t = t->left;
	}
	*f = temp;
}

/******************************************************************************
main FUNCTION - Driver Function
******************************************************************************/
void main(){
	node* doublylinkedlist = NULL;
	printf("CHOICES: 1.Insert 2.Delete 3.Display 4.Reverse 5.Exit\n");
	do{
		printf("CHOICE: "); int ch; scanf("%d",&ch);
		switch(ch){
			case 1: printf("Element: "); char ele[32]; scanf("%s",ele);
					insert(&doublylinkedlist,ele); break;
			case 2: delete(&doublylinkedlist); printf("Element Deleted.\n"); break;
			case 3: display(doublylinkedlist); break;
			case 4: reverse(&doublylinkedlist); printf("List Reversed.\n"); break;
			case 5: exit(0);
			default: printf("Invalid Choice.\n");
		}
	}while(1);
}

/*****************************************************

Script Created on: 2018-10-18 : 13:06 - Verified Working
Script Written by: RAJAT SHENOY
Github: https://www.github.com/raj4tshenoy/DSL.git

*****************************************************/