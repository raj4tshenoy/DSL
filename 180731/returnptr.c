#include <stdio.h>

int* smaller(int *p1, int *p2){
	if(*p1<*p2)
		return p1;
	else
		return p2;
}

void main(){
	int a, b;
	printf("Enter 2 values: ");
	scanf("%d%d",&a, &b);
	printf("Value of pointer returned: %p \n Value at address: %d \n",smaller(&a, &b), *smaller(&a, &b));
}