#include <stdio.h>

void main(){
	int n;
	int *pf, *pb;
	printf("Enter number of elements: ");
	scanf("%d",&n);
	int a[n];
	//INPUT ARRAY
	printf("Enter array elements: \n");
	for(int i=0; i<n; i++){
		scanf("%d", &a[i]); 
	}
	pf = a;
	pb = (a+(n-1));
	//printing forward:
	printf("Printing array in forward:\n");
	for(int i=0; i<n; i++){
		printf("%d\t",*(pf+i));
	}
	printf("\n\nPrinting array in backward:\n");
	for(int i=0; i<n; i++){
		printf("%d\t", *(pb-i));
	}
	printf("\n");
}