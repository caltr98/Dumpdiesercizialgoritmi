#include<stdio.h>
#include<stdlib.h>

typedef struct _node{
	int info;
	struct _node* next;
}node;
typedef struct _coda{
	node* head;
	node* tail;
}coda;

void push(coda*q,int value);
void init(coda*q);
int pop(coda*q);
int codavuota(coda*q);

int main(){
	coda p;




	init(&p);	
	push(&p,999);
	push(&p,3);
	push(&p,4);

	while(!codavuota(&p)){
		printf("%d\n",pop(&p));
	}
	return 0;
}

void push(coda*q,int value){
	node* new=malloc(sizeof(node));
	new->info=value;
	new->next=NULL;
	if(q->head==NULL && q->tail==NULL){
		q->head=new;
		q->tail=new;
	}
	else{
		q->tail->next=new;
		q->tail=new;
	}
}
void init(coda*q){
	q->head=NULL;
	q->tail=NULL;
}
int pop(coda*q){
	if(q->head==NULL && q->tail==NULL){
		return -1;
	}
	int tr=q->head->info;
	if(q->head==q->tail){
		q->tail=NULL;
		free(q->head);
		q->head=NULL;
	}
	else{
		q->head=q->head->next;
	}
	return tr;
}
int codavuota(coda*q){
	if(q->head==NULL && q->tail==NULL){
		return 1;
	}
	return 0;
}
