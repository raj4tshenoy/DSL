#include <stdio.h>

int fibo(int n){ //computes n fibonacci number
  if(n <= 1)
		return n;
  return fibo(n-1) + fibo(n-2);
}

void main(){
  int n;
  printf("Enter n:");
  scanf("%d",&n);
  for(int i=0; i<n; i++){ //iteratively calls fibo to display series
    printf("%d ",fibo(i));
  }
  printf("\n");
}
