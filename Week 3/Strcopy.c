#include <stdio.h>

void strcopy(char a[], char *p){
	static int i=0;
	if(a[i]=='\0')
		return;
	else{
		*(p+i)=a[i]; //copying contents in a to the address of contents in b;
		i++; strcopy(a, p);
	}
}

void main(){
	char a[50], b[50];
	printf("Enter a string: ");
	gets(a);
	strcopy(a,b);
	printf("\nThe copied string is: %s", b);
	printf("\nEnd Program.\n");
}