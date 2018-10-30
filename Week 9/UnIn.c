#include <stdio.h>
#include <stdlib.h>
#define getNode (Node*)malloc(sizeof(Node))

struct Node{
	int data;
	struct Node *next;
};

typedef struct Node Node;

void insert(Node **first, int elem){
	Node *t = getNode;
	t->data = elem;

	if((*first) == NULL)
	{
		t->next = t;
		*first = t;
		return;
	}

	Node *temp = *first;
	while(temp->next != *first){
		temp = temp->next;
	}
	temp->next = t;
	t->next = *first;
}

void disp(Node *lol){
	Node *l = lol;
	while(l->next != lol){
		printf("%d\t", l->data);
		l = l->next;
	}
	printf("%d\n", l->data);
}

int Contains(Node *k, int n){
	Node* t = k;
	while(t->next!=k){
		if(t->data == n)
			return 1;
		t=t->next;
	}
	if(t->data == n)
			return 1;
	return 0;
}
void intersection(Node *a, Node *b, Node **c){
	Node* t1 = a;
	Node* t2 = b;
	while(t2->next!=b){ 
		if(Contains(t1,t2->data)){
			insert(c,t2->data);
		}
		t2 = t2->next;
	}
	if(Contains(t1,t2->data)){
			insert(c,t2->data);
	}
}

void Union(Node *a, Node *b, Node **c){
	Node* t1 = a;
	Node* t2 = b;
	while(t1->next!=a){
		insert(c,t1->data);
		t1=t1->next;
	}
	insert(c,t1->data);
		t1=t1->next;
	t1 = a;
	while(t2->next!=b){
		if(!Contains(t1,t2->data)){
			insert(c,t2->data);
	}
		t2=t2->next;
	}
	if(!Contains(t1,t2->data)){
			insert(c,t2->data);
	}
}

int main(){
	Node *A = NULL;
	Node *B = NULL;
	Node *C = NULL;
	Node *D = NULL;
	int in = 0;
	printf("Enter elements in A and enter -1 to end\n");
	while(in!=-1){

		scanf("%d", &in);
		if(in != -1)
			insert(&A, in);
	}
	in = 0;
	printf("Enter elements in B and enter -1 to end\n");
	while(in!=-1){

		scanf("%d", &in);
		if(in != -1)
			insert(&B, in);
	}
	printf("DISPLAY A, B :: intersection & Union\n");
	disp(A);
	disp(B);
	intersection(A, B, &C);
	Union(A,B, &D);
	disp(C);
	disp(D);
}