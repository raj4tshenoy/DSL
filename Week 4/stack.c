#include <stdio.h>

#define MAXSIZE 10

struct STACK{
	char list[100];
	int top;
};

int isEmpty(int top){
	return (top<0);
}

int isFull(int top, int size){
	return (top>=size-1);
}

void push(struct STACK* c, int size){
	if(isFull(c->top, size)){
		printf("Stack Overflow\n");
		return;
	}
	printf("Enter element to push: ");
	scanf("%c",&c->list[++(c->top)]);
}

void pop(struct STACK* c){
	if(isEmpty(c->top)){
		printf("Stack underflow\n");
		return;
	}
	printf("Popped Element: %c", c->list[(c->top)--]);
}

void display(struct STACK c, int n){
	for(int i=0; i<n; i++){
		printf("%c\t", c.list[i]);
	}
}

void main(){
	struct STACK s;
	s.top = -1;
	int k, size;
	printf("\nEnter size of stack: ");
	scanf("%d",&size);
	do{
		printf("\n\nChoose: \n1.PUSH \n2.POP \n3.DISPLAY \n:");
		scanf("%d",&k); getchar();
		switch(k){
			case 1: push(&s, size); break;
			case 2: pop(&s); break;
			case 3: display(s, size); break;
			default: printf("\nEXIT\n");
		}
	}while(k>=1&&k<=3);
}