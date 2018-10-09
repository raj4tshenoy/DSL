#include <stdio.h>
#include "stackfn.c"
void main(){
  stack s1; stack s2;
  int n, k, ele;
  printf("\nEnter number of elements: " );
  scanf("%d",&n);
  int a[n];
  printf("Enter array elements: ");
  for(int i = 0; i<n; i++){ //input
    scanf("%d",&a[i]);
  }
  int o=0; //debug
  for(int i=n-1; i<=0; i--){
    o++; //debug
    push(&s1,a[i]);
    printf("to push %d\npushed %d %d",a[i], s1.list[o], i); //debug
  }
  printf("\nDISPLAY STACK:\n");
  display(s1);
  printf("Enter k: ");
  scanf("%d",&k);
  for(int i=0; i<k; i++){
    for(int j=s1.top; j>0; j--){
      if(s1.list[j] < s1.list[j-1]){
          ele = pop(&s1);
          break;
      }
      else{
        ele = pop(&s1);
        push(&s2,ele);
      }
    }
    if(s2.top>-1){
      for(int j=s2.top; j>-1; j--){
        ele = pop(&s2);
        push(&s1,ele);
      }
    }
  }
  printf("\n\nDISPLAY STACK: \n");
  display(s1);
}
