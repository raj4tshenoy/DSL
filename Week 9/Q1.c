#include <stdio.h>
#include <stdlib.h>
#define getNode (node*)malloc(sizeof(node*))

struct NODE{
	int data;
	struct NODE* next;
};

typedef struct NODE node;

node* insert(node* first, int x){ //takes in pointer to last element in list. Inserts node to rear and returns pointer to rear node.
	if(first == NULL){ //if new list
		node* t = getNode;
		t->data = x;
		t->next = t;
		first = t;
		return first;
	}
	node* t = getNode;
	t->data = x;
	t->next = first->next;
	first->next = t;
	return t;
}

node* delete(node* first){ //takes in pointer to last element of list.
	if(first==NULL){
		return NULL;
	}
	node* t = first->next;
	while(t->next!=first){ //moves t to point to node previous to node first.
		t=t->next;
	}
	t->next = first->next;
	free(first);
	return t;
}

void display(node* first){ //takes in pointer to last element of list;
	printf("DISPLAY LIST:\n");
	if(first == NULL){
		printf("List is Empty\n");
	}
	node* t = first->next; //t points to first element of list;
	while(t!=first){
		printf("%d ",t->data);
		t = t->next;
	}
	printf("%d\n",t->data);
}

int isin(node* n, int ele){
	
}

node* unin(node* l1, node* l2){
	if(l1==NULL&&l2==NULL){
		return NULL;
	}
	else if(l1==NULL){
		return l2;
	}
	else if(l2 == NULL){
		return l1;
	}
	node* n = NULL;

}

node* ints(node* l1, node* l2){
	if(l1==NULL||l2==NULL){
		return NULL;
	}
	node* n = NULL;
	node* t = l1->next;
	node* q = l2->next;
	while(t!=l1){
		while(q!=l2){
			if(t->data==q->data){
				n = insert(n,t->data);
			}
			q = q->next;
		}
		if(t->data==q->data){
			n = insert(n, t->data); //to check last element of l2.
		}
		q = q->next;
		t = t->next;
	}
	while(q!=l2){ //check last element of l1
		if(t->data==q->data){
				n = insert(n,t->data);
			}
			q = q->next;
	}
	if(t->data==q->data){
		n = insert(n, t->data); //to check last element of l2 with l1.
	}
	return n;
}

node* newlist(node* rear){
	printf("Choices: 1.Insert 2.Delete 3.Display 4.End\n");
	while(1){
		printf("Choice: "); int ch;
		scanf("%d",&ch);
		switch(ch){
			case 1: printf("Element: "); int ele; scanf("%d",&ele); rear = insert(rear,ele); break;
			case 2: rear = delete(rear); break;
			case 3:	display(rear); break;
			default: return rear;
		}
	}
}

void main(){
	node* l1 = NULL;
	node* l2 = NULL;
	printf("List 1\n");
	l1 = newlist(l1);
	printf("List 2\n");
	l2 = newlist(l2);
	node* uni = unin(l1,l2);
	printf("List 1 Union List 2\n");
	display(uni);
	node* ins = ints(l1,l2);
	printf("List 1 Intersection List 2\n");
	display(ins);
}
