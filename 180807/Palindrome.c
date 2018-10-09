#include <stdio.h>
#include <string.h>

int ispal(char a[], int l, int h){
  if(l>=h)
    return 1;
  if(a[l]!=a[h])
    return 0;
  ispal(a,++l,--h);
}

void main(){
  char a[50];
  printf("Enter a string: ");
  scanf("%s",a);
  if(ispal(a, 0, strlen(a)-1)){
    printf("The string %s is a palindrome.\n", a);
  }
  else{
    printf("The string %s is not a palindrome.\n", a);
  }
}
