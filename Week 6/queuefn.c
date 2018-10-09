#include <stdio.h>

typedef struct{
    int *list;
    int r;
    int f;
    int MAX;
    int count; 
}queue;

int isFull(queue q){
    return (q.count == q.MAX);
}

int isEmpty(queue q){
    return (q.count==0);
}

void enqueue(queue *q, int ele){
    if(isFull(*q)){
    	q->r = (q->r)%q->MAX;
    }
    q->list[++(q->r)] = ele;
    if((q->count)<(q->MAX)){
    	q->count++;
    }
}

int dequeue(queue *q){
	if(isEmpty(*q)){
		q->f = ((q->f)+1)%q->MAX;
		return -999;
	}
	--q->count;
	return q->list[(q->f)++];
}

void display(queue q){
	if(isEmpty(q)){
		printf("\nQueue is empty.\n"); return;
	}
	for(int i=0, j=q.f; i<q.count; j=(j+1)%q.MAX, i++){
		printf("%d ",q.list[j]);
	}
}
