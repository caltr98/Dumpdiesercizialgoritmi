#include <stdio.h>
#include <stdlib.h>

typedef struct s{
	int key;
	struct s* next;
}node;

void insert(int x,node **T);
int hash(int x,int a,int b,int n);
void print_list(node *T);
int lenght(node* T);
void delete(node** list,int el);
void removal(int x,int a,int b,int n,node **T);
int main(){
	int n,a,b,i,x;
	node **T;
	int indice;
	int maxlen=0;
	int currlen=0;
	int len=0;
	scanf("%d",&n);
	scanf("%d",&a);
	scanf("%d",&b);
	T=(node**)malloc(2*n*sizeof(node*));
	for(i=0;i<2*n;i++){
		T[i]=NULL;
	}
	for(i=0;i<n;i++){
		scanf("%d",&x);
		indice=hash(x,a,b,n);
		insert(x,&T[indice]);
	}
	for(i=0;i<2*n;i++){
		print_list(T[i]);
		printf("NULL \n");
	}/*
	for(i=0;i<2*n;i++){
		currlen=lenght(T[i]);
		if(currlen>0)
			len+=(currlen-1);
		if(currlen>maxlen)
			maxlen=currlen;
	}*/
	printf("inserisci gli elementi da eliminare\n");
	scanf("%d",&x);
	while(x!=-1){
		removal(x,a,b,n,T);
		scanf("%d",&x);
	}
	for(i=0;i<2*n;i++){
		print_list(T[i]);
		printf("NULL \n");
	}

	

	return 0;
}


int hash(int x,int a,int b,int n){
	int p=999149;
	int y=(a*x+b)%p%(n*2);
	//printf("%d\n",y);
	return y;
}

void insert(int x,node **T){

	node *new=(node*)malloc(sizeof(node));
	new->key=x;
	new->next=*T;
	*T=new;
}
	
void removal(int x,int a,int b,int n,node **T){
	int index=hash(x,a,b,n);
	delete(&(T[index]),x);
}
void delete(node** list,int el){
	if(*list==NULL){
		return;
	}
		
	if((*list)->key==el){
		node* curr=(*list);
		*list=(*list)->next;
		delete(list,el);
		free(curr);
	}
	else{
		delete(&((*list)->next),el);
	}

}
	
void print_list(node *T	){
	if(T==NULL){
		return;
	}
	else{
		print_list(T->next);
		printf("%d,",T->key);
	}
}

int lenght(node* T){
	if(T==NULL)
		return 0;
	return 1+lenght(T->next);
}
