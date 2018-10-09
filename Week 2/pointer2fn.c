#include <stdio.h>

void swap(int *p1, int *p2){
	int temp;
	temp = *p1;                                              
	*p1 = *p2;
	*p2 = temp;
}

void main(){
	int a, b;
	printf("Enter 2 numbers: ");
	scanf("%d%d",&a,&b);
	int *p1, *p2;
	p1 = &a; p2 = &b;
	swap(p1, p2);
	printf("Value of a & b after swapping using pointers: %d %d \n", a, b);
}