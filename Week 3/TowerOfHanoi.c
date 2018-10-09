#include <stdio.h>

void toh(int n, int src, int temp, int dest, int* c){
  if(n==1){
    printf("\nMove disk %d from pole %d to pole %d", n, src, dest); ++(*c);
  }
  else{
    toh(n-1, src, dest, temp, c);
    printf("\nMove disk %d from pole %d to pole %d", n, src, dest); ++(*c);
    toh(n-1, temp, src, dest, c);
  }
}

void main(){
  printf("Enter number of disks: ");
  int n, count=0;
  scanf("%d",&n);
  toh(n,1,2,3, &count);
  printf("\nNumber of moves = %d \n", count);
}
