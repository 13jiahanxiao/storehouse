#include<stdio.h>
#include<stdlib.h>
typedef struct {
	int data;
	slink *next;
}slink;
slink *intlist(int n){
	slink *head,*p,*s;
	int i;
	p=head=(slink*)malloc(sizeof(slink));
	for(i-0;i<n;i++){
		s=(slink*)malloc(sizeof(slink));
		scanf("%d",&s->data);
		p->next=s;
		p=s;
	}
	p->next=NULL;
	return head;
}
typedef struct
{
	int top;
	int *base;
	int stacksize;
}sqstack;
void intsqstack(sqstack *s){
	s->base=(int*)malloc(100*sizeof(int));
	s->top=0;
	s->stacksize=100;
}
void nizhi(slink *head, sqstack*s, int n) {
	int i = 0;
	slink *head2 = (slink*)malloc(sizeof(slink));
	head = head->next;
	for (i = 0; i < n; i++) {
		s->base[s->top] = head->data;
		head = head->next;
		s->top++;
	}
	head2 = head2->next;
	for (i = 0; i < n; i++) {
		head2->data = s->base[s->top];
		head2 = head2->next;
		s->top--;
	}
}


