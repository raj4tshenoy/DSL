#include <stdio.h>

void copy(char a[], char *b){
  static int i=0;
  if(a[i]=='\0'){
    return;
  }
  else{
    *(b+i)=a[i];
    i++; copy(a, b);
  }
}

void main(){
  char a[50], b[50];
  printf("Enter String:");
  scanf("%s",a);
  copy(a,b);
  printf("Copied String is %s\n",b);
}
