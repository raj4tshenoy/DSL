#include <stdio.h>

int fibo(int n){
	if(n<=1)
		return n;	
	else
		return fibo(n-1)+fibo(n-2);
}

void main(){
	int n;
	printf("Enter n:");
	scanf("%d",&n);
	for(int i=0; i<n; i++){
		printf("%d ", fibo(i));
	}
	printf("\nSeries generated.\n");
}