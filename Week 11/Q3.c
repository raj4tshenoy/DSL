#include <stdio.h>
#include <stdlib.h>

///////////////NODE TEMPLATE//////////////////////////
typedef struct node{
	int data;
	struct node* left;
	struct node* right;
}node;

/*****************************************************
//////////////INLINE QUEUE FUNCTION///////////////////
*****************************************************/

typedef struct{
    node* list[100];
    int r, f, MAX, count; 
}queue;

void initq(queue* q){
	q->r = -1;q->f = q->count = 0;
	q->MAX = 100; 
}

int isFull(queue q){
    return (q.count == q.MAX);
}

int isEmpty(queue q){
    return (q.count==0);
}

void enqueue(queue *q, node* ele){
    if(isFull(*q)){
    	return;
    }
    q->list[++(q->r)] = ele;
    q->count++;
    //printf("\ncount: %d\n",q->count); //debug
}

node* dequeue(queue *q){
	if(isEmpty(*q)){
		return NULL;
	}
	q->count--;
	//printf("\ncount: %d\n",q->count); //debug 
	return q->list[(q->f)++];
}

void display(queue q){ //////////////////COMMENTED OUT/
	if(isEmpty(q)){
		printf("\nQueue is empty.\n"); return;
	}
	for(int i=0, j=q.f; i<q.count; j=(j+1)%q.MAX, i++){ //i is loop counter, j is array counter
		printf("%d.%d ",i+1,(q.list[j])->data);
	}
}

////////////////////PROGRAM STARTS HERE/////////////

/***************************************************
Getnode fn - Allocates memory to a node and returns 
the created node.
***************************************************/

node* getNode(int x){
	node* t = (node*)malloc(sizeof(node));
	t->data = x;
	t->left = t->right = NULL;
	return t;
}

node* insert(node* root, int x){ 
	node*t = getNode(x);
	if(root==NULL) return t;
	node* cur = root, *prev = NULL;
	while(cur!=NULL){
		prev = cur;
		if(cur->data==x){
			free(t); return root;
		}
		if(x >= cur->data){ 
			cur = cur->right; continue;
		}
		if(x < cur->data){
			cur = cur->left; continue;
		}
	}
	if(cur==NULL)
	{if(x >= prev->data){
			prev->right = t;
		}
		else{
			prev->left = t;
		}}
	return root;	
}

void inorder(node* root,int* a, int* n){
	if(root == NULL) return;
	inorder(root->left,a,n);
	printf("%d ",root->data);
	a[(*n)] = root->data; (*n)++;
	inorder(root->right,a,n);
}

int inorderSuccessor(int a[], int target,int n){
	for(int i=0; i<n; i++){
		if(a[i]==target){
			return a[i+1];
		}
	}
	return 0;
}


void main(){
	node* root = NULL;
	int in[50]; int n=0;
	int k, data;
	do{ k=0;
		printf("data: "); scanf("%d",&data);
		root = insert(root,data);
		printf("k: "); scanf("%d",&k);
	}while(k);
	printf("DISPLAY:\n");
	inorder(root,in, &n);
	printf("\nEnter val to find inorderSuccessorr: "); scanf("%d",&k);
	int is = inorderSuccessor(in, k, n);
	if(is)
		printf("inorderSuccessor is: %d\n",is );
	else
		printf("inorderSuccessor doesnt exist.\n");
}

/*****************************************************

Script Created on: 2018/10/29 - Verified Working
Script Written by: RAJAT SHENOY
Github: https://www.github.com/raj4tshenoy/DSL.git

*****************************************************/