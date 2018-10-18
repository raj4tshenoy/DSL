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

/////////////////////////CHECK IF BST FUNCTION///////////////////////////
/************************************************************************
This function takes in a root node and checks if the root and its sub 
trees qualify to be a binary tree using recursion.
************************************************************************/	

int isBST(node* root){
	if(root->left==NULL&&root->right==NULL){ //no children exist
		return 1;
	}
	if((root->left==NULL)&&root->right){ //right child exists, left doesnt.
		if(root->right->data >= root->data) return isBST(root->right);
		else return 0;
	}
	if((root->right==NULL)&&root->left){ //left child exists right doesnt.
		if(root->left->data < root->data) return isBST(root->left);
		else return 0;
	}
	if(root->left->data < root->data && root->right->data >= root->data){ //both children exist
		return isBST(root->left) * isBST(root->right);
	}
	else return 0;
}

/////////////////Main Function - Driver/////////////////////////////////

void main(){
	node* root = NULL;
	int ele; char path[100];
	printf("CHOICES: \n1.Insert \n2.Display InOrder \n3.Check_if_BST \n4.EXIT\n");
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
			case 3: if(isBST(root)){printf("Tree is a Binary Search Tree.\n"); break;}
					printf("Tree is not a BST.\n"); break;
			case 4: exit(0);
			default: printf("Invalid Choice\n");
		}
	}while(1);
}

/*****************************************************

Script Created on: 18-10-18 17:53 - Verified Working
Script Written by: RAJAT SHENOY
Github: https://www.github.com/raj4tshenoy/DSL.git

*****************************************************/