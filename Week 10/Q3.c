#include <stdio.h>
#include <stdlib.h>
#include <string.h>

////////TREE TEMPLATE////////////

typedef struct node{
	int data;
	struct node* left;
	struct node* right;
}node;


/************************************************************************
//////////////////////////PROGRAM BEGINS HERE////////////////////////////
************************************************************************/

////////////////////Returns newly created node//////////////////////////
node* getNode(int x){
	node* t = (node*)malloc(sizeof(node));
	t->data = x;
	t->left = t->right = NULL;
	return t;
}

///////////////////Inserts new node to required position////////////////

node* insert(node* root, int x, char dir[]){
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

//////////////////Inorder Traversal & Display///////////////////////////

void inorder(node* root){
	if(root == NULL) return;
	inorder(root->left);
	printf("%d ",root->data);
	inorder(root->right);
}

////////////////////TOP VIEW DISPLAY////////////////////////////////////

void disp_lst(node* root){
	if(root == NULL) return;
	disp_lst(root->left);
	printf("%d ",root->data);
}

void disp_rst(node* root){
	if(root == NULL) return;
	printf("%d ",root->data);
	disp_rst(root->right);
}

void disp_tv(node* root){
	printf("Display TopView:\n");
	disp_lst(root);
	disp_rst(root->right);
	printf("\n");
}

/////////////////Main Function - Driver/////////////////////////////////

void main(){
	node* root = NULL;
	int ele; char path[100];
	printf("CHOICES: \n1.Insert \n2.Display InOrder \n3.Display TopView \n4.EXIT\n");
	do{	getchar();
		printf("Choice: "); int ch; scanf("%d",&ch);
		switch(ch){
			case 1: printf("Element: ");
					getchar();
					scanf("%d",&ele);
					printf("Path: "); scanf("%s",path);
					root = insert(root,ele,path);
					break;
			case 2: printf("DISPLAY InOrder\n");
					inorder(root); printf("\n");
					break;
			case 3: disp_tv(root); break;
			case 4: exit(0);
			default: printf("Invalid Choice\n");
		}
	}while(1);
}

/*****************************************************

Script Created on: 18-10-18 21:06 - Verified Working
Script Written by: RAJAT SHENOY
Github: https://www.github.com/raj4tshenoy/DSL.git

*****************************************************/