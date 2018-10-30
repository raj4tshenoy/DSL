#include <stdio.h>
#include <stdlib.h>
#define getNode (node*)malloc(sizeof(node))

typedef struct node{
	int c; //coefficient
	int e; //exponent
	struct node* next;
}node;

node* insert(node* head, int c, int e){
	node* first = head->next;
	node* t = getNode; node* i = first; //i for traversal, t to hold new node.
	t->c = c; t->e = e;
	if(first==NULL){
		head->next = t;
		t->next = t;
		return head;
	}
	else{
		while(i->next!=first){
			i=i->next;
		}
		i->next = t;
		t->next = first;
		return head;
	}
}

void display(node* head){
	node* first = head->next;
	while(first->next!=head->next){ //for n-1 nodes
		if(first->next->c > 0){
			printf("%dx^%d +",first->c,first->e);
			first=first->next;
		}
		else{
			printf("%dx^%d ",first->c,first->e);
			first=first->next;
		}
	} //for nth node
	printf("%dx^%d\n",first->c,first->e);
}

/******************************************
				CONTAIN FN

Checks if the passed exponent value of a list (1)
exists in the passed list (2) and if it exists,
the corresponding node in list(2) is stored in pos. 
*****************************************/

void contains(node* head, int x, node** pos){
	node*t = head->next; int i=0; 
	do{ 
		if(t->e==x){ 
			*pos = t;
			return;
		} 
		t=t->next; 
	}while(t!=head->next);
	*pos = NULL;
}

/*********************************************************************************
								SUBTRACT FN
This function subtracts 2 polynomials. By checking if the exponent in list(1) exists
in list(2). If yes - it subtracts and stores in new list. If no - it appends term of
list(1) to the difference. Then it appends the remaining terms in list(2). Returns 
linked list of polynomials having the difference.
*********************************************************************************/


node* sub(node* head1, node* head2){
	node* dif = getNode, *t1 = head1->next, *t2 = head2->next, *pos; dif->next = NULL;
	do{ //for list 2.
		contains(head1,t2->e,&pos);
		if(pos){
			int diff = pos->c - t2->c;
			dif = insert(dif,diff,t2->e);
			t2 = t2->next;
		} 
		else{
			dif = insert(dif,-t2->c,t2->e);
			t2 = t2->next;
		}
	}while(t2!=head2->next);
	do{ //for remaining items in list 1
		contains(head2,t1->e,&pos);
		if(pos!=NULL){
			t1=t1->next;
		}
		else{
			dif = insert(dif,t1->c,t1->e);
			t1 = t1->next;
		}
	}while(t1!=head1->next);
	return dif;
}

/*********************************************************************************
								MULTIPLY FN
multiplies every term of list(1) with every term in list(2) and returns product 
polynomial linked list.
*********************************************************************************/

node* mult(node* head1, node* head2){

	node* mul = getNode, *t1 = head1->next, *t2; mul->next = NULL;
	do{ t2 = head2->next;
		do{
			int c, e;
			c = t1->c * t2 -> c; e = t1->e + t2->e;
			mul = insert(mul,c,e);
			t2 = t2->next;
		}while(t2!=head2->next);
		t1 = t1->next;
	}while(t1!=head1->next); 	
	return mul;
}

void main(){
	
	////////////DECLARATION////////////////////

	node* head1 = getNode; //poly1
	head1->next = NULL; head1->e = head1->c = 0;
	node* head2 = getNode; //poly2
	head2->next = NULL; head2->e = head2->c = 0;
	node* dif = getNode; //sub
	dif->next = NULL; dif->e = dif->c = 0;
	node* mul = getNode; //mult
	mul->next = NULL; mul->e = mul->c = 0;
	
	///////////////////INPUT/////////////////////

	printf("CHOICES: 1.Insert 2.Display 3.EXIT\n");
	printf("LIST 1:\n");
	int k;
	do{k=0; int ch, c, e;
		printf("CHOICE: "); scanf("%d",&ch);
		switch(ch){
			case 1: printf("c x^ e: "); scanf("%d %d",&c,&e);
					head1 = insert(head1,c,e); break;
			case 2: display(head1); break;
		}
		printf("k: "); scanf("%d",&k);
	}while(k);
	printf("LIST 2:\n");
	do{k=0; int ch, c, e;
		printf("CHOICE: "); scanf("%d",&ch);
		switch(ch){
			case 1: printf("c x^ e: "); scanf("%d %d",&c,&e);
					head2 = insert(head2,c,e); break;
			case 2: display(head2); break;
		}
		printf("k: "); scanf("%d",&k);
	}while(k);

	////////////////OPERATION/////////////////////////

	printf("CHOICES: 1.Subtract 2.Multiply 3.EXIT\n");
	do{k=0; int ch, c, e;
		printf("CHOICE: "); scanf("%d",&ch);
		switch(ch){
			case 1: dif = sub(head1,head2); 
					printf("DISPLAY SUBTRACTED POLYNOMIAL: \n");
					display(dif); break;
					
			case 2: mul = mult(head1,head2);
					printf("DISPLAY MULTIPLIED POLYNOMIAL: \n");
					display(mul); break;
		}
		printf("k: "); scanf("%d",&k);
	}while(k);


	////////////////////END PROGRAM/////////////////////////
}

/*****************************************************

Script Created on: 2018-10-17 : 00:37 - Verified Working
Script Written by: RAJAT SHENOY
Github: https://www.github.com/raj4tshenoy/DSL.git

*****************************************************/













