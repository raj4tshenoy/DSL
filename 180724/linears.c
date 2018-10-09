#include <stdio.h>

int srch(int a[], int n, int target){ //find function
	int pos = 0;
	for(int i=0; i<n; i++){ //n time iteration
			if(a[i]==target){
				pos = i+1;
				break;
			}
	} 
	return pos;
}

void main(){
	int n, element, position;
	printf("Enter the number of elements: "); //input
	scanf("%d",&n);
	int aray[n];
	for(int i=0; i<n; i++){ //n time iteration
		printf("Enter element %d: ", i+1);
		scanf("%d",&aray[i]);
	}
	printf("Enter the number to find: ");
	scanf("%d", &element);
	position = srch(aray, n, element); //element position transfered to variable
	if(position){
		printf("The entered element is found in position: %d \n", position);
	}
	else
		printf("The entered element is not found \n");
}