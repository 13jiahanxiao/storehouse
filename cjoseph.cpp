#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node*next;
}qlink;
typedef struct {
	qlink*front ;
	qlink*rear;
}linkqueue;
void intlist(linkqueue*l,int n){
	int i;
	l->front=l->rear=(qlink*)malloc(sizeof(qlink));
	qlink *p=(qlink*)malloc(sizeof(qlink));
	l->front->next=p;
	scanf("%d",&l->front->data);
	scanf("%d",&p->data);
	for(i=0;i<n-2;i++){
		qlink *s=(qlink*)malloc(sizeof(qlink));
		scanf("%d",&s->data);
		p->next=s;
		p=s;
	}
	p->next=l->front;
	l->rear=p;
}
void joseph(linkqueue *l,int m){
	int i;
	qlink*p=(qlink*)malloc(sizeof(qlink));
	qlink*s=(qlink*)malloc(sizeof(qlink));
	p=l->front;
	for(i=0;i<m;i++){
		if(l->front==l->rear)
		break;
		if(i==m-2){
			s=p;
		}
		if(i==m-1){
			printf("%d",p->data);
			if(p==l->rear){
				s->next=l->rear->next;
				l->rear=s;
				p=s->next;
			}
			else if(p==l->front){
				l->front=l->front->next;
				l->rear->next=l->front;
				p=l->front;
			}
			else {
				s->next=p->next;
				p=s->next;
			}
			i=0;
		}
		p=p->next;
	}
}

int main(){
	linkqueue*l=(linkqueue*)malloc(sizeof(linkqueue));
	int m,n,i=0;
	scanf("%d",&n);
	scanf("%d",&m);
	intlist(l,n);
	joseph(l,m);
	printf("%d",l->front->data);
}
		

