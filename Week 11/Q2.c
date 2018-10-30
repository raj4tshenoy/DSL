#include <stdio.h>
#include <stdlib.h>
#include <math.h>

///////////////NODE TEMPLATE//////////////////////////
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

////////////////////PROGRAM STARTS HERE/////////////

/***************************************************
Getnode fn - Allocates memory to a node and returns 
the created node.
***************************************************/

node* getNode(char x){
	node* t = (node*)malloc(sizeof(node));
	t->data = x;
	t->left = t->right = NULL;
	return t;
}

node* createETree(char postfix[]){
	stack s; s.top = -1; 
	int i; char ch; node* tree;
	for(i=0; (ch=postfix[i])!='\0';i++){
		if(isalnum(ch)){
			node* t = getNode(ch);
			push(&s,t);
		}
		else{
			tree = getNode(ch);
			tree->right = pop(&s);
			tree->left = pop(&s);
			push(&s,tree);
		}
	}
	return tree;
}

float evalExpression(node* root){
	float res;
	if(root==NULL){
		return 0;
	}
	switch(root->data){
		case '+': return (evalExpression(root->left)+evalExpression(root->right)); break;
		case '-': return (evalExpression(root->left)-evalExpression(root->right)); break;
		case '*': return (evalExpression(root->left)*evalExpression(root->right)); break;
		case '/': return (evalExpression(root->left)/evalExpression(root->right)); break;
		case '^': return pow(evalExpression(root->left),evalExpression(root->right)); break;
		default: if(isalnum(root->data)){
			float num;
			printf("Value for %c: ",root->data);
			scanf("%f",&num);
			return num;
		}
	}
}

void main(){
	node* root = NULL;
	char postfix[50];
	printf("postfix expression: ");
	scanf("%s",postfix);
	root = createETree(postfix);
	float result = evalExpression(root);
	printf("Result: %f\n",result);
}

/*****************************************************

Script Created on: 2018/10/29 - Verified Working
Script Written by: RAJAT SHENOY
Github: https://www.github.com/raj4tshenoy/DSL.git

*****************************************************/