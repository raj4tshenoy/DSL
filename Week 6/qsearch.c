#include <stdio.h>
#include "queuefn.c"

int searchq(queue q, int ele){
	for(int i=0, j=q.f; i<q.count; j=(j+1)%q.MAX, i++){ //i is loop counter, j is array counter
		if(q.list[j] = ele){
			return 1;
		}
	}
	return 0;
}

void main(){
	queue q; q.f = 0; q.r=-1; q.count = 0;
	printf("Enter queue length: ");
	scanf("%d", &q.MAX);
	q.list = (int*)calloc(q.MAX, sizeof(int*));
	int k;
	do{k=0;
	int l;
	printf("\n\nCHOOSE\n1.enqueue\n2.dequeue\n3.display\n4.search\n:");
	scanf("%d",&l);
	int ele;
	switch(l){
		case 1: 
			printf("Enter element: ");
			scanf("%d",&ele);
			enqueue(&q,ele);
			break;
		case 2:
			dequeue(&q);
			break;
		case 3:
			printf("\n\nDISPLAY QUEUE:\n");
			display(q);
			break;
		case 4:
			printf("\n\nEnter element to search: ");
			scanf("%d",&ele);
			if(searchq(q,ele)){
				printf("Element exists\n");
			}
			else{
				printf("Element does not exist\n");
			}
			break;
		default: printf("\nInvalid Choice\n");
	}
	printf("Enter 0 to exit. ");
	scanf("%d",&k);
	}while(k!=0);
}
