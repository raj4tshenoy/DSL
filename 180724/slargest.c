#include <stdio.h>

int slarge(int a[], int n){
	int large=-32768, secondlarge=-32768, i;
	for(i=0; i<n; i++){ //finding largest
		if(a[i]>large)
			large = a[i];
	}
	for(i=0; i<n; i++){ //finding secong largest
		if((a[i]>secondlarge)&&(a[i]<large))
			secondlarge = a[i];
	}
	return secondlarge;
}

void main(){
	int n;
	printf("Enter the number of elements: "); //input
	scanf("%d",&n);
	int aray[n];
	for(int i=0; i<n; i++){ //n time iteration
		printf("Enter element %d: ", i+1);
		scanf("%d",&aray[i]);
	}
	printf("Second largest number in the array = %d \n", slarge(aray, n));	//BTW I LOVE JAVA and Python too
}