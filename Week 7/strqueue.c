#include <stdio.h>
#include <string.h>
#define MAX 10

typedef struct 
{
	char ch[MAX][80];
	int f,r;
	
}PQ;


int isFull(PQ P)
{
	if((P.r+1)%MAX==P.f)
		return 1;
	else
		return 0;
}

int isEmpty(PQ P)
{
	if(P.r==-1)
		return 1;
	else 
		return 0;
}

void addLeft(PQ *P,char str[80])
{
	if(isEmpty(*P))
	{
		P->r=0;
		P->f=0;
		strcpy(P->ch[0],str);
	}

	else
	{
		P->f=(P->f-1+MAX)%MAX;
		strcpy(P->ch[P->f],str);
	}
}

void addRight(PQ *P, char str[80])
{
	if(isEmpty(*P))
	{
		P->r=0;
		P->f=0;
		strcpy(P->ch[0],str);
	}

	else
	{
		P->r=(P->r+1)%MAX;
		strcpy(P->ch[P->r],str);
	}	
}

void deleteLeft(PQ *P)
{
	char temp[80];

	strcpy(temp,P->ch[P->f]);
	if(P->r==P->f)
	{
		P->r=-1;P->f=-1;
	}
	else
	{
		P->f=(P->f+1)%MAX;
	}
	printf("DELETED STRING : %s",temp);
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
		printf("\n%s",P->ch[i]);
		i=(i+1)%MAX;
	}

	printf("\n%s",P->ch[P->r]);
}

void main()
{
	int c;
	char temp[80];
	PQ Q;
	PQ* P=&Q;

	while(1)
	{
		printf("\n1.AddLeft 2.AddRight 3.Delete: 4.Display 5.Exit:");
		scanf("%d",&c);

		switch(c)
		{
			case 1: printf("Enter string:");
					gets();
					gets(temp);
					addLeft(P,temp);
					break;

			case 2: printf("Enter string:");
					gets();
					gets(temp);
					addRight(P,temp);
					break;

			case 3: deleteLeft(P);
					break;

			case 4: display(P);
					break;

			case 5: printf("\nExiting\n");
					exit(0);

			default: printf("\nTry again.\n");	 
		}
	}

}