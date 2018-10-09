#include <stdio.h>

int ispal(char a[], int l, int h){
	if(l>=h)
		return 1;
	if(a[l]!=a[h]){ 
		return 0;
	ispal(a, ++l, --h);
	}
}
int len(char a[]){ //finds length of array recursively and returns position of last element.
	static int n=0;
	if(a[n]!='\0'){
		n++; len(a);
	}
	return n-1;
}

void main(){
	char a[50];
	printf("Enter a string: ");
	gets(a);
	if(ispal(a,0,len(a)))
		printf("\nThe string %s is a palindrome.\n",a);
	else
		printf("\nThe string %s is not a palindrome.\n",a);
}