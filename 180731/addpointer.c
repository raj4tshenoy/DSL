#include <stdio.h>

void main(){
	int* a, *b, n1, n2;
	printf("Enter 2 numbers: ");
	scanf("%d%d",&n1,&n2);
	a = &n1;
	b = &n2;
	printf("Sum of numbers by variables: %d \n",n1+n2);
	printf("Sum of numbers by pointers: %d \n",*a+*b);
}