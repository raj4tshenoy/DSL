#include <stdio.h>
#include "stackfn.c"
#include <string.h>

void main(){
	stack s; s.top = -1;
	char a[100]; int junk;
	printf("Enter expression: ");
	scanf("%s",a);
	int len = strlen(a);
	for(int i=0; i<len; i++){
		if(a[i]=='('){
			push(&s,(int)a[i]);
		}
		if(a[i]==')'){
			junk = pop(&s);
		}
	}
	if(s.top>-1){
		printf("\nExpression invalid.\n");
	}
	else{
		printf("\nExpression is valid!\n");
	}
}