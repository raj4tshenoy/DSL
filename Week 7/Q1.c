#include <stdio.h>
#include <stdlib.h>

typedef struct{ //queue structure
	int *list;
	int *pty;
	int f;
	int r;
	int max;
}queue;

int isEmpty(queue q){ //returns if queue is empty
	return (q.f>q.r);
}

int isFull(queue q){ //returns true if queue is full
	return (q.r==q.max-1);
}

void enqueue(queue *q, int ele, int pri){
	if(isFull(*q)){
		printf("Queue is full.\n");
		return;
	}
	q->list[++q->r] = ele;
	q->pty[q->r] = pri;
}
void display(queue q){
	printf("DISPLAY: \n");
	for(int i=q.f; i<=q.r; i++){
		printf("%d ",q.list[i]);
	}
}

int deqpri(queue* q){ //returns highest priority element
	if(isEmpty(*q)){
		printf("Queue is Empty.\n");
		return -999;
	}
	int pri = q->pty[0]; int pos;
	for(int i=q->f; i<=q->r; i++){ //finds position of highest priority element
		if(q->pty[i]<pri){
			pri = q->pty[i];
			pos = i;
		}
	}
	queue temp; temp.f=0; temp.r=-1; temp.max = q->max; //temp queue
	temp.list = (int*)calloc(temp.max+1,sizeof(int));
	temp.pty = (int*)calloc(temp.max+1,sizeof(int));
	int ret;
	printf("%d %d",q->f, q->r);
	for(int i=q->f; i<=q->r; i++){ //transfers all elements of queue except dequeue element
		printf("in loop %d",i);
		if(i!=pos){ 
			enqueue(&temp,q->list[i],q->pty[i]);
			continue;
		}
		ret = q->list[pos]; 
	}
	q->list = temp.list;
	q->pty = temp.pty;
	q->r--;
	return ret;
	}

void main(){
	queue q; q.f=0; q.r=-1;
	int ele, pri;
	printf("Enter size of queue: ");
	scanf("%d", &q.max);
	q.list = (int*)calloc(q.max+1,sizeof(int));
	q.pty = (int*)calloc(q.max+1,sizeof(int));
	printf("1.Enqueue 2.Dequeue 3.Display 4.Exit\n");
	while(1){
		int ch;
		printf("Choice: ");
		scanf("%d",&ch);
		switch(ch){
			case 1: printf("Element, Priority: ");
					scanf("%d%d",&ele,&pri);
					enqueue(&q,ele,pri); break;
			case 2: printf("Dequeue: %d", deqpri(&q)); 
			        break;
			case 3: display(q); break;
			default: exit(0);
		}
	}
}