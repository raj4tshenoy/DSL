#include <stdio.h>
#include <string.h>
#define MAX 30

typedef struct 
{
	char ch[MAX];
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

void addLeft(PQ *P,char letter)
{
	if(isEmpty(*P))
	{
		P->r=0;
		P->f=0;
		P->ch[0]=letter;
	}

	else
	{
		P->f=(P->f-1+MAX)%MAX;
		P->ch[P->f]=letter;
	}
}

void addRight(PQ *P, char letter)
{
	if(isEmpty(*P))
	{
		P->r=0;
		P->f=0;
		P->ch[0]=letter;
	}

	else
	{
		P->r=(P->r+1)%MAX;
		P->ch[P->r]=letter;
	}	
}

char deleteLeft(PQ *P)
{
	char letter;

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

char deleteRight(PQ *P)
{
	char letter;

	letter = P->ch[P->r];

	if(P->r == P->f)
	{
		P->f=-1;
		P->r=-1;
	}
	else
	{
		P->r=(P->r-1+MAX)%MAX;
	}

	return letter;
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
		printf("\t%c",P->ch[i]);
		i=(i+1)%MAX;
	}

	printf("\t%c",P->ch[P->r]);
}

void main()
{
	char palin[80];
	PQ Q;
	PQ *P=&Q;
	P->f=-1;
	P->r=-1;


	printf("\nEnter String:");

	scanf("%s",palin);

	for(int i=0; palin[i]!='\0'; ++i)
	{
		addLeft(P,palin[i]);
	}

	printf("Entered string:");
	display(P);

	char l,r;
	int len = strlen(palin);
	printf("\nLength: %d",len);
	int flag=1;
	if(len%2 ==0)
	{
		while(!isEmpty(*P))
		{
			r=deleteRight(P);
			l=deleteLeft(P);
			if(l!=r)
			{
				flag=0;
				break;
			}
		}

		if(flag == 1)
		{
			printf("\nPalindrome.\n");
			return;
		}
		else
		{
			printf("\nNot Palindrome.\n");
			return;
		}
	}

	else
	{
		
		for(int j=1; j<=len/2; ++j)
		{
			r=deleteRight(P);
			l=deleteLeft(P);
			if(l!=r)
			{
				flag=0;
				break;
			}
		}

		if(flag == 1)
		{
			printf("\nPalindrome.\n");
			return;
		}
		else
		{
			printf("\nNot Palindrome.\n");
			return;
		}

	}

}