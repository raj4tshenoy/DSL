#include <stdio.h>
#include "stackfn.c"
#include <math.h>

int tobinary(int n){
	long bin = 0; int i=0;
	stack s; s.top=-1;
	while(n !=0){
		push(&s, n%2);
		n=n/2;
	}
	display(s);
	while(!isEmpty(s)){
		bin=bin*10+pop(&s);
		i++;
	}
	return bin;
}

void main(){
	int dec, k;
	do{ k=0;
		printf("Enter number: ");
		scanf("%d",&dec);
		printf("Binary equivalent = %d", tobinary(dec));
		printf("\nPress 1 to redo.\n");
		scanf("%d", &k);
	}while(k==1);
}