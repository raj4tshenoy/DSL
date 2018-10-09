#include <stdio.h>
#define MAX 100
typedef struct{
	char list[MAX];
	int top;
}stack;

int isFull(stack c){
	return (c.top>=MAX);
}

int isEmpty(stack c){
	return (c.top==-1);
}

void push(stack* c, char ele){
	if(isFull(*c)){
		printf("\nStack Overflow\n");
		return;
	}
	c->list[++(c->top)] = ele;
}

char pop(stack* c){
	if(isEmpty(*c)){
		printf("\nStack Underflow\n");
		return 0;
	}
	return c->list[(c->top)--];
}

void display(stack c){
	for(int i=0; i<=c.top; i++){
		printf("%c\t",c.list[i]);
	}
	printf("\n");
}
