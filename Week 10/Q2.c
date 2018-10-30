#include <stdio.h>
#include <stdlib.h>
#include <string.h>

////////TREE TEMPLATE////////////

typedef struct node{
	char data;
	struct node* left;
	struct node* right;
}node;

/************************************************************************
//////////////////////////STACK FN///////////////////////////////////////
************************************************************************/

#define MAX 100
typedef struct{
	node* list[MAX];
	int top;
}stack;

int isFull(stack c){
	return (c.top>=MAX);
}

int isEmpty(stack c){
	return (c.top==-1);
}

void push(stack* c, node* ele){
	if(isFull(*c)){
		return;
	}
	c->list[++(c->top)] = ele; 
}

node* pop(stack* c){
	if(isEmpty(*c)){
		return NULL;
	}
	return c->list[(c->top)--];
}

/////////////DISPLAY STACK/////////////////

void display(stack c){
	for(int i=c.top; i>=0; i--){
		printf("%c ",(c.list[i])->data);
	}
	printf("\n");
}


/************************************************************************
//////////////////////////PROGRAM BEGINS HERE////////////////////////////
************************************************************************/

////////////////////Returns newly created node//////////////////////////
node* getNode(char x){
	node* t = (node*)malloc(sizeof(node));
	t->data = x;
	t->left = t->right = NULL;
	return t;
}

///////////////////Inserts new node to required position////////////////

node* insert(node* root, char x, char dir[]){
	node* t = getNode(x);
	if(root==NULL){
		return t;
	}
	node* parent = NULL; node* child = root; int i;
	for(i=0; strlen(dir)!=0&&child!=NULL;i++){
		parent = child;
		if(dir[i]=='L') child = child->left;
		else child = child -> right;
	}
	if(child!=NULL || i!=strlen(dir)){
		printf("Insertion not possible\n");
		return root;
	}
	if(dir[i-1]=='R') parent->right = t;
	else parent->left = t;
	return root;
}

/////////////////Postorder Traversal & Display//////////////////////////

void postorder(node* root){
	stack s1, s2; s1.top = -1; s2.top = -1;
	push(&s1,root);
	while(s1.top!=-1){
		root = pop(&s1);
		push(&s2,root);
		if(root->left){push(&s1,root->left);}
		if(root->right){push(&s1,root->right);}
	}
	display(s2);
}

/////////////////Preorder Traversal & Display///////////////////////////

void preorder(node* root){
	stack s; s.top = -1;
	if(root==NULL)
		return;
	for(;;){
		for(;root!=NULL;root=root->left){
			printf("%c ", root->data);
			push(&s,root);
		}
		root = pop(&s);
		if(root==NULL){
			return;
		}
		root = root->right;
	}
}

//////////////////Inorder Traversal & Display///////////////////////////

void inorder(node* root){
	if(root == NULL) return;
	inorder(root->left);
	printf("%c ",root->data);
	inorder(root->right);
}

/////////////////Main Function - Driver/////////////////////////////////

void main(){
	node* root = NULL;
	char ele; char path[100];
	printf("CHOICES: \n1.Insert \n-------------\nDisplay: \n2.PostOrder \n3.PreOrder \n4.InOrder \n------------\n5.Exit\n");
	do{	getchar();
		printf("Choice: "); int ch; scanf("%d",&ch);
		switch(ch){
			case 1: printf("Element: ");
					getchar();
					scanf("%c",&ele);
					printf("Path: "); scanf("%s",path);
					root = insert(root,ele,path);
					break;
			case 2: printf("DISPLAY Postorder\n");
					postorder(root); printf("\n");
					break;
			case 3: printf("DISPLAY Preorder\n");
					preorder(root); printf("\n");
					break;
			case 4: printf("DISPLAY InOrder\n");
					inorder(root); printf("\n");
					break;
			case 5: exit(0); break;
			default: printf("Invalid Choice\n");
		}
	}while(1);
}

/*****************************************************

Script Created on: 18-10-18 14:51 - Verified Working
Script Written by: RAJAT SHENOY
Github: https://www.github.com/raj4tshenoy/DSL.git

*****************************************************/