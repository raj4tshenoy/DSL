#include <stdio.h>
#include <stdlib.h>
#define getNode (node*)malloc(sizeof(node))

typedef struct node{
	int data;
	struct node* left;
	struct node* right;
}node;

/*********************************************************************
insertF FUNCTION - inserts new node to the front of the list.
New node is inserted between head and existing list.
*********************************************************************/

void insertF(node** head, int ele){
	node* t = getNode;
	node* f = (*head)->right;
	t->data = ele;
	if(f==NULL){ //first term
		t->left = t;
		t->right = t;
		(*head)->right = t;
		return;
	}
	f->left->right = t;
	t->left = f->left;
	f->left = t;
	t->right = f;
	(*head)->right = t;
}

/*********************************************************************
DISPLAY FUNCTION: Displays doubly linked list.
*********************************************************************/

void display(node* head){
	node* t = head->right;
	if(t==NULL){
		printf("Empty List\n");
		return;
	} 
	do{
		printf("%d",t->data);
		t = t->right;
	}while(t!=head->right);
}

/*********************************************************************
ADD FUNCTION - contents of 2 linked lists. (Each data field has a value
between 0-9.);
*********************************************************************/

node* add(node* head1, node* head2){
	node* t1 = head1->right->left; //points at least significant digit
	node* t2 = head2->right->left; 
	node* sum = getNode; sum->right = NULL;
	int s = 0, c = 0;
	
	//for all the digits in t1&t2 until one of them goes out of bounds.
	do{
		s = t1->data + t2->data + c;
		c = s/10;
		insertF(&sum, s%10);
		t1=t1->left; t2=t2->left;
	}while(t1!=head1->right->left&&t2!=head2->right->left);

	
	//if t1 list is unfinished:
	while(t1!=head1->right->left){
		insertF(&sum,t1->data);
		t1=t1->left;
	}


	//if t2 list is unfinished:
	while(t2!=head2->right->left){
		insertF(&sum,t2->data);
		t2=t2->left;
	}

	return sum;
}





void main(){
	node* head1 = getNode;
	head1->right = head1->left=NULL;
	node* head2 = getNode;
	head2->right = head2->left=NULL;
	unsigned long int d;
	
	//To Input long in to linked list/////
	printf("Enter num1: ");
	scanf("%ld",&d);
	while(d){
		insertF(&head1,d%10);
		d/=10;
	}
	printf("Enter num2: ");
	scanf("%ld",&d);
	while(d){
		insertF(&head2,d%10);
		d/=10;
	}

	///////SUM OF 2 LISTS ////////
	node* sum = getNode;
	sum->right = sum->left = NULL;
	sum = add(head1,head2);


	////////////DISPLAY SUM//////
	printf("\nSum is: ");
	display(sum);
	printf("\n");



	////////////////////Input Testing////////////////////////////////
	/*int k;
	printf("CHOICES: 1.Insert 2.Display 3.EXIT \n");
	do{ k=0; int ch;
		printf("CHOICE: "); scanf("%d",&ch);
		switch(ch){
			case 1: printf("Element: \n"); int ele; scanf("%d",&ele);
					insertF(&head,ele);
					break;
			case 2: display(head);
		}
		printf("K: "); scanf("%d",&k);
	}while(k);*/
}

/*****************************************************

Script Created on: 2018-10-18 : 12:11 - Verified Working
Script Written by: RAJAT SHENOY
Github: https://www.github.com/raj4tshenoy/DSL.git

*****************************************************/