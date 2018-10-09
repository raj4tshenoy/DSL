#include <stdio.h>
#include<string.h>

typedef struct{
    char list[10][50];
    int r, f, MAX, count; 
}queue;

int isFull(queue q){
    return (q.count == q.MAX);
}

int isEmpty(queue q){
    return (q.count==0);
}

void enqueue(queue *q, char ele[]){
    if(isFull(*q)){
    	q->r = ((q->r)+1)%q->MAX;
    }
    strcpy(q->list[++(q->r)],ele);
    q->count++;
    //printf("\ncount: %d\n",q->count); //debug
}

char* dequeue(queue *q){
	if(isEmpty(*q)){
		q->f = ((q->f)+1)%q->MAX;
		printf("\nQueue is empty\n");
		return "\0";
	}
	q->count--;
	//printf("\ncount: %d\n",q->count); //debug 
	return q->list[(q->f)++];
}

void display(queue q){
	if(isEmpty(q)){
		printf("\nQueue is empty.\n"); return;
	}
	for(int i=0, j=q.f; i<q.count; j=(j+1)%q.MAX, i++){ //i is loop counter, j is array counter
		printf("%d.%s ",i+1,q.list[j]);
	}
}

void main(){
	
    queue q; q.r=-1; q.f = 0; q.MAX = 10; q.count = 0; char in[50];
    int k;
    do{ k=0;
    int l;
    printf("\n\nCHOOSE:\n1.Enqueue\n2.Dequeue\n3.Display\n: ");
    scanf("%d",&l);
    switch(l){
        case 1: printf("Enter String: "); scanf("%s",in); enqueue(&q, in); break;
        case 2: printf("%s ",dequeue(&q)); break;
        case 3: printf("\n\nDISPLAY QUEUE:\n"); display(q); break;
        default: printf("Invalid Choice.\n");
    }
    printf("Enter 0 to exit. ");
    scanf("%d",&k);
    }while(k!=0);   
}
