#include <stdio.h>

void multiply(int A[][10],int B[][10],int m,int n,int p,int q){
	int C[10][10];


	for(int i=0; i<m; i++){
		for(int j=0; j<q; j++){
		C[i][j]=0; 
			for(int k=0; k<n; k++){
				C[i][j] +=(A[i][k]*B[k][j]);
			}
		}
	}
	printf("\n\n\n Matrix A * Matrix B: \n\n");
	for(int i=0; i<m; i++){
		for(int j=0; j<q; j++){
			printf("%d \t", C[i][j]);
		}
		printf("\n");
	}
}

void main(){
	
	//inputn dimension
	int row1, row2, col1, col2;
	printf("Enter the number of rows and colums of matrix 1: ");
	scanf("%d %d", &row1, &col1);
	printf("Enter the number of rows and colums of matrix 2: ");
	scanf("%d %d", &row2, &col2);
	

	//CHECK MATRIX
	if(col1!=row2){
		printf("Matrices cannot be multiplied. Dimension error. \n");
		return;
	}
	int A[10][10], B[10][10];


	//input array
	for(int i=0; i<row1; i++){ //matrix A
		for(int j=0; j<col1; j++){
			printf("Enter value of A[%d][%d]: ",i+1 , j+1);
			scanf("%d", &A[i][j]);
		}
	}
	for(int i=0; i<row2; i++){ //matrix B
		for(int j=0; j<col2; j++){
			printf("Enter value of B[%d][%d]: ",i+1 , j+1);
			scanf("%d", &B[i][j]);
		}
	}


	//MULTIPLYING MATRIX A & B
	multiply(A, B, row1, col1, row2, col2);
}