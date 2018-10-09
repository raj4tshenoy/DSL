#include <stdio.h>
#include "stackfn.c"

int ispal(char a[]){
	stack s; s.top=-1; int i=0;
	while(a[i]!='\0'){
		push(&s,(int)a[i]);
		i++;
	} i=0;
	while(!isEmpty(s)){
		if((pop(&s)!=(int)a[i])){ 
			return 0;
		} i++;
	}
	return 1;
}

void main(){
	char str[100];
	printf("Enter string: ");
	gets(str);
	if(ispal(str)){
		printf("%s is a palindrome.",str);
	}
	else{
		printf("%s is not a palindrome.",str);
	}
}