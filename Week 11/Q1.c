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

/*********************************************************
Delete fn - Deletes the node with data provided.
*********************************************************/

node* delete(node* root, int key){
	if(root==NULL){
		printf("Tree is empty.\n");
		return NULL;
	}
	node* parent = NULL, *cur = root;
	while(cur!=NULL){
		parent = cur;
		if(cur->data == key) break;
		if(key < cur->data) cur = cur->left;
		else cur = cur->right;
	}
	if(cur==NULL){printf("element doesn't exist.\n"); return root;} //Empty Tree
	node* temp;
	if(cur->left==NULL&&cur->right==NULL){temp = cur; free(temp); cur=NULL; return root;}
	if(cur->left == NULL){ //only RST
		temp = cur->right;
		parent->right = temp;
		free(cur);
	}

	if(cur->right == NULL){ //only LST
		temp = cur->left;
		parent->left = temp;
		free(cur);
	}
	if(cur->data < parent->data){ //if both LST & RST exist and key is on Left of parent
		if(cur->left){
			temp = cur->left;
			parent->left = temp;
			while(temp->left!=NULL){ //traverses to leaf node on left.
				temp = temp->left;
			}
			if(cur->right->data >= temp->data){
				temp -> right = cur->right;
			}
			else
				temp -> left = cur -> right;
		}
	}

	if(cur->data >= parent->data){ //if both LST & RST exist and key is on Right of parent
		if(cur->right){
			temp = cur->right;
			parent->right = temp;
			while(temp->right!=NULL){ //traverses to leaf node on right.
				temp = temp->right;
			}
			if(cur->left->data >= temp->data){
				temp -> right = cur->left;
			}
			else
				temp -> left = cur->left;
		}
	}
	printf("element deleted.\n");
	return root;
}

void inorder(node* root){
	if(root == NULL) return;
	inorder(root->left);
	printf("%d ",root->data);
	inorder(root->right);
}

void disp_LO(node* root){ 
	if(root == NULL){
		return;
	}
	printf("DISPLAY:\n");
	queue q; initq(&q);
	enqueue(&q,root);
	while(1){
		root = dequeue(&q);
		if(root==NULL) break;
		if(root!=NULL){ printf("%d ",root->data);}
		if(root->left){
			//printf("enqueue left\n");//debug 
			enqueue(&q,root->left); 
			//printf("Q:"); display(q);//debug
		}
		if(root->right){
			//printf("enqueue right\n");//debug 
			enqueue(&q, root->right);
			//printf("Q:"); display(q);//debug
		} 
		//else break;
	}
	printf("\n");
}

void main(){
	node* root = NULL;
	printf("CHOICES: 1.Insert 2.Delete 3.Display Level Order 4.EXIT\n");
	int k,ch;
	while(1){
		printf(": ");
		scanf("%d",&ch);
		switch(ch){
			case 1: printf("Enter element: "); scanf("%d",&k);
					root = insert(root, k); break;
			case 2: printf("Enter element to delete: "); scanf("%d",&k); 
					root = delete(root,k); break;
			case 3: disp_LO(root); break;
			case 4: exit(0);
			default: printf("Invalid Choice.\n");
		}
	}
}

/*****************************************************

Script Created on: 2018/10/23 - Verified Working Partially
Script Written by: RAJAT SHENOY
Github: https://www.github.com/raj4tshenoy/DSL.git

*****************************************************/