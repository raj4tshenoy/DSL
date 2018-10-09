#include <stdio.h>
#include <string.h>
#include "stackchr.c"

int prec(char ch){ //returns precedence of operator
  switch(ch){
    case '#': return -1; break;
    case ')': return 1; break;
    case '+': return 2; break;
    case '-': return 2; break;
    case '*': return 3; break;
    case '/': return 3; break;
    case '^': return 4; break;
  }
}

int isOperand(char ch){ //returns if input is operand
  return (ch>='A'&&ch<='Z'||ch>='a'&&ch<='z');
}

int isOperator(char ch){ //returns if input is operator
  return (ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='^');
}

void main(){
  stack s; s.top=-1;
  char inf[100];
  printf("Enter the infix expression: ");
  scanf("%s",inf);
  push(&s,'#');
  int len = strlen(inf);
  char pre[len+1];
  pre[len]='\0';
  int j=len-1;
  for(int i=len-1; i<=0; i--){
    if(isOperand(inf[i])){
      pre[i] = inf[i];
    }
  }
}
