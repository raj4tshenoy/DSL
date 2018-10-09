#include <stdio.h>

void rev(char a[], char b[], int n){
	static int i=0;
	if(a[i]!='\0'){
		b[i] = a[n];
		i++;
		rev(a,b,--n);
	}
	return;
}

int len(char a[]){ //finds length of array recursively and returns position of last element.
	static int n=0;
	if(a[n]!='\0'){
		n++; len(a);
	}
	return n-1;
}

void main(){
	char a[50],b[50];
	printf("Enter a string: ");
	gets(a);
	rev(a,b, len(a));
	printf("Reverse: %s\n", b);
}