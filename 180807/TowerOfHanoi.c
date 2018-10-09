#include <stdio.h>

void toh(int n, int src, int temp, int dest){
  if(n==1)
    printf("\nMove disk %d from %d to %d", n, src, dest);
  else{
    toh(n-1, src, dest, temp);
    printf("\nMove disk %d from %d to %d", n, src, dest);
    toh(n-1, temp, src, dest);
  }
}

void main(){
  printf("Enter number of disks: ");
  int n;
  scanf("%d",&n);
  toh(n,1,2,3);
}
