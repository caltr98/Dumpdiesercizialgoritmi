#include<stdio.h>
#include<stdlib.h>
//una anno dopo in data 30 Aprile 2020 con l'ausilio di elements che conta il numero di elementi l'ho fatta workare :))
typedef struct _coda{
	int dim;
	int*valori;
	int head;
	int tail;
	int elements;
}coda;

void accoda(coda*q,int value);
void init(coda*q,int dim);
int decoda(coda*q);
int codavuota(coda*q);
void deinit(coda *q);
int main(){
	int dim=5;
	coda q;
	init(&q,dim);
	accoda(&q,5);
	accoda(&q,4);
	accoda(&q,3);
	accoda(&q,2);
	accoda(&q,1);
	accoda(&q,0);
	decoda(&q);
	accoda(&q,0);
	accoda(&q,-1);
	decoda(&q);
	decoda(&q);
	decoda(&q);
	decoda(&q);
	decoda(&q);
	decoda(&q);
	printf("%d",codavuota(&q));
	printf("valore elements %d,valore head %d,valore tail %d\n",q.elements,q.head,q.tail);
	return 0;
}
void init(coda *q,int dim){
	q->valori=malloc(dim*sizeof(int));
	q->dim=dim;
	q->head=0;
	q->tail=0;
	q->elements=0;
}	
void accoda(coda*q,int value){
	if(q->elements==q->dim){
		printf("non posso accodare perchè è piena la cosa\n");
		fflush(stdout);
		return;
	}
	q->valori[q->tail]=value;
	q->tail=(q->tail+1)%(q->dim);
	q->elements++;
}

int decoda(coda*q){
	if(q->elements==0){
		printf("non posso decodare dato che non ci sono elementi\n");
		return -1;
	}
    int ret= q->valori[q->head];
	q->head=(q->head+1)%(q->dim);
	q->elements--;
	return ret;
}
int codavuota(coda*q){
	if(q->head==q->tail && q->elements==0)
		return 1;
	return 0;
}
int piena(coda*q){
	if(q->elements==q->dim){
		return 1;
	}
	return 0;

}
void deinit(coda *q){
    free(q->valori);
    q->dim=0;
    q->head=q->tail=0;
}
