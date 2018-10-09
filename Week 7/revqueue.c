#include <stdio.h>
#include <string.h>
#define MAX 30

typedef struct 
{
	int ch[MAX];
	int f,r;
	
}PQ;

int isEmpty(PQ P)
{
	if(P.r==-1)
		return 1;
	else 
		return 0;
}

void addRight(PQ *P, int ele)
{
	if(isEmpty(*P))
	{
		P->r=0;
		P->f=0;
		P->ch[0]=ele;
	}

	else
	{
		P->r=(P->r+1)%MAX;
		P->ch[P->r]=ele;
	}	
}

int deleteLeft(PQ *P)
{
	int letter;

	letter =P->ch[P->f];
	if(P->r==P->f)
	{
		P->r=-1;P->f=-1;
	}
	else
	{
		P->f=(P->f+1)%MAX;
	}
	return letter;
}

void revq(PQ *P)
{
	if(P->r==-1)
		return;
	int x = deleteLeft(P);
	revq(P);
	addRight(P,x);
}


void display(PQ *P)
{
	if(isEmpty(*P))
	{
		printf("\nQueue is Empty");
		return;
	}

	int i = P->f;
	while(i!=P->r)
	{
		printf("\t%d",P->ch[i]);
		i=(i+1)%MAX;
	}

	printf("\t%d",P->ch[P->r]);
}

void main()
{

	PQ Q,Q1;
	PQ *P=&Q;
	PQ *P1=&Q1;
	P->r=-1;
	P->f=-1;
	P1->r=-1;
	P1->f=-1;
	int c,temp;
	int count,n;

	while(1)
	{
		printf("\n1.Addright 2.Deleteleft: 3.Display 4.Reverse 5.Exit:");
		scanf("%d",&c);

		switch(c)
		{
			case 1: printf("Enter ele:");
					scanf("%d",&temp);
					addRight(P,temp);
					break;

			case 2: deleteLeft(P);
					break;

			case 3: display(P);
					break;

			case 4: revq(P);
					break;

			case 5: exit(0);
					break;		

			default: printf("\nTry again.\n");	 
		}
	}	
}