#include <stdio.h>
 
 /////////////////////MERGE SORT///////////////////
 void mergeSort(int a[], int n){
 	/********************************************
	Variable Explanation:
	a - main array.
	i, j - sub array (imaginary) counters
	k - auxillary counter
	u1,l1,u2,l2 - upper and lower bounds of i & j
	size - size of imaginary sub array
	aux - auxillary array
 	********************************************/

 	int i,j,k,u1,l1,u2,l2,size=1,aux[100];
 	while(size<n){ //run until the imaginary array size is same as main array. (until a single imaginary array is obtained)
 		l1=0; k=0; //initializing lowerbound 1 & aux counter.
 		while(l1+size<n){ //for each set
 			l2 = l1+size;
 			u1 = l2-1;
 			u2 = (l2+size-1<n)?l2+size-1:n-1;

 			//general transfer
 			for(i=l1, j=l2; i<=u1&&j<=u2;k++){
 				
 				if(a[i]<=a[j]) aux[k] = a[i++];
 				else aux[k] = a[j++];
 			}
 			//if i exhausts, copy contents of j to aux
 			for(;j<=u2;k++) aux[k] = a[j++];

 			//if j exhausts, copy contents of i to aux
 			for(;i<=u1;k++) aux[k] = a[i++];
 			l1=u2+1;
 		}
 		
 		//copy remaining elements without pair to aux
 		for(i=l1;k<n;) aux[k++] = a[i++];

 		//copy aux to a;
 		for(i=0; i<n; i++) a[i] = aux[i];

 		//update size
 		size*=2;
 	}
 }

//////////////MAIN FN/////////////
 void main(){
 	int a[100], n;
 	printf("n: "); scanf("%d",&n);
 	printf("Enter elements:\n");

 	//Inputs
 	for(int l=0; l<n; l++){
 		scanf("%d",&a[l]);
 	}

 	printf("UNSORTED ARRAY:\n");
 	for(int l=0; l<n; l++){
 		printf("%d ",a[l] );
 	}

 	//sort call
 	mergeSort(a,n);

 	printf("\nSORTED ARRAY:\n");
	for(int l=0; l<n; l++){
 		printf("%d ",a[l] );
 	} 	
 }

 /*****************************************************

Script Created on: 2018/10/30 - Verified Working
Script Written by: RAJAT SHENOY
Github: https://www.github.com/raj4tshenoy/DSL.git

*****************************************************/