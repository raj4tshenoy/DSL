#include <stdio.h>


void insert(int a[], int e, int i){
	while(e<a[i] && i>=0){
		a[i+1] = a[i];
		i--;
	} a[i+1] = e;
}

void insertionSort(int a[], int n){
	int i;
	for(i=1; i<n; i++){
		insert(a,a[i],i-1);
	}
}

void main(){
	int n, a[100];
	printf("n: "); scanf("%d",&n);
	printf("Enter Elements:\n");
	for(int i=0; i<n; i++)
		scanf("%d",&a[i]);
	insertionSort(a,n);
	printf("DISPLAY SORTED ARRAY:\n");
	for(int i=0; i<n; i++){
		printf("%d ",a[i]);
	}
	printf("\n");
}

/*****************************************************

Script Created on: 2018/10/30 - Verified Working
Script Written by: RAJAT SHENOY
Github: https://www.github.com/raj4tshenoy/DSL.git

*****************************************************/