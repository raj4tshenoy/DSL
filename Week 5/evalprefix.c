#include <stdio.h>
#include <string.h>
#include <math.h>
#include "stackfn.c"

int isdig(char ch){
	return (ch>='0'&&ch<='9');
}

int process(int a, int b, char ch){
	switch(ch){
		case '+': return a+b; break;
		case '-': return a-b; break;
		case '*': return a*b; break;
		case '/': return a/b; break;
		case '^': return pow(a,b); break;
	}
}

void main(){
	stack s; s.top = -1; int val=0, op1, op2;
	char a[100];
	printf("Enter prefix expression: ");
	scanf("%s",a);
	for(int i=strlen(a)-1; i>=0; i--){
		if(isdig(a[i])){
			push(&s,(int)a[i]-'0');
		}
		else{
			op1 = pop(&s);
			op2 = pop(&s);
			val = process(op1,op2,a[i]);
			push(&s,val);
		}
	}
	val = pop(&s);
	printf("Value of expression = %d\n", val);
}