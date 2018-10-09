#include <stdio.h>

void main(){
	int a;
	int *justpointer;
	int **p2p;
	printf("Enter a number: ");
	scanf("%d",&a);
	justpointer = &a;
	p2p = &justpointer;
	printf("\n\nValue entered: \nfrom a: %d \nfrom pointer: %d \nfrom pointer to pointer: %d\n\n\n",a, *justpointer, **p2p);
	printf("Address of variable (through pointer): %p \n Address of pointer (through pointer to pointer): %p \n\n", justpointer, p2p);
}