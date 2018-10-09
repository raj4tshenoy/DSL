#include <stdio.h>

void firstuppercase(char a[], int i){
	if(a[i]=='\0'){
		printf("\nNo uppercase character in string.\n");
		return;
	}
	else if(((int)a[i]>=65)&&((int)a[i]<=90)){
		printf("\nFirst upprecase letter is %c\n",a[i]);
		return;
	}
	else{
		firstuppercase(a, i+1);
	}
}

void main(){
	char a[50];
	printf("\nEnter a string: ");
	gets(a);
	firstuppercase(a, 0);
}