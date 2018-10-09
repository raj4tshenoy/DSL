#include <stdio.h>

int sum(int a[], int n){ //sum finder
	int total=0;
	for(int i=0; i<n; i++){ //n time iteration
		total += a[i];
	}
	return total;
}

void main(){
	int n;
	printf("Enter the number of elements: \n"); //input
	scanf("%d",&n);
	int aray[n];
	for(int i=0; i<n; i++){ //n time iteration
		printf("Enter element %d: ", i+1);
		scanf("%d",&aray[i]);
	}
	printf("The sum of elements in the array = %d \n", sum(aray, n)); //output
}