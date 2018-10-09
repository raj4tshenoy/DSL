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
  char inf[100], pre[100], out[100];
  printf("Enter the infix expression: ");
  scanf("%s",inf);
  push(&s,'#');
  int len = strlen(inf);
  int j=0;
  for(int i=len-1; i>=0; i--){ //loop begins
    if(inf[i]==')'){
      push(&s,inf[i]);
    }
    else if(isOperand(inf[i])){
      pre[j] = inf[i];
      j++;
    }
    else if(isOperator(inf[i])){
      while(1){
        if(prec(inf[i])>=prec(s.list[s.top])){
          push(&s,inf[i]);
          break;
        }
        else{
            pre[j] = pop(&s); //pops all elements in stack
            j++;
        }
      }
    }
    else if(inf[i]=='('){
      while(s.list[s.top]!=')'){
        pre[j] = pop(&s);
        j++;
      }
      pop(&s);
    }
  } //loop end
  while(s.top!=0){ //to pop all remaining elements in stack
    pre[j] = pop(&s);
    j++;
  }
  pre[j] = '\0'; j--;
  len = strlen(pre);
  for(int i=0; i<len; i++,j--){
    out[j] = pre[i];
  }
  out[len] = '\0';
  printf("\n\nPrefix Expression: %s\n",out);
}
