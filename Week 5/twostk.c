#include <stdio.h>
#include "stackfn.c"

void stackmove(stack *s1, stack *s2){
  while(!isEmpty(*s1)){
    push(s2,pop(s1));
  }
}

void main(){
  //declaration
  stack s1,s2;
  s1.top = -1; s2.top = -1;
  int n,in;

  //input
  printf("Enter no. of elements: ");
  scanf("%d",&n); //gets number of elements to n
  printf("Enter elements:\n");
  for(int i=0; i<n; i++){ //pushing elements to stack 1
    scanf("%d",&in);
    push(&s1,in);
  }

  //processing
  stackmove(&s1,&s2);
  int arr[100];
  for(int i=0; i<n; i++){ //transferring contents of stack 2 to array
    arr[i] = pop(&s2);
  }

  //output
  printf("\n\nElements in array are: \n");
  for(int i=0; i<n; i++){
    printf("%d ",arr[i]);
  }
  printf("\n");
}
