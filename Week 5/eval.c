#include <stdio.h>

void rLarge(int a[], int n, int* l){
	if(n<0){
		return;
	}
	if(*l<a[n]){
		*l=a[n];
	}
	rLarge(a, n-1, l);
}

void main(){
	int a[100], n, largest;
	printf("Enter number of elements: \n");
	scanf("%d",&n);
	printf("Enter the elements: \n");
	for(int i=0; i<n; i++){
		scanf("%d",&a[i]);
	}
	largest = a[0];
	rLarge(a, n-1, &largest);
	printf("Largest number is: %d \n", largest);
}