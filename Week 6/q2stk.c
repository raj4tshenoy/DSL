#include <stdio.h>
#include "stackfn.c"

void enqueue(stack *s1, stack *s2, ele){
	if(isFull(*s1)){
		if(isEmpty(*s2)){
			move(&s1,&s2);
		}
		
	}	
}

int dequeue(stack *s1, stack *s2){
	
}

void main(){
	stack s1,s2;
	int k;
	do{k=0;
	
	printf("Enter 0 to exit. ");
	scanf("%d",&k);
	}while(k!=0);
}
