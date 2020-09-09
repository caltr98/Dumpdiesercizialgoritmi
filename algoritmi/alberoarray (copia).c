#include<stdio.h>
#include<stdlib.h>

typedef struct nodes {
	int key;
	struct nodes* left;
	struct nodes* right;
}node;


void insert(node **t,int k);
int altezza(node *t); 
void libera(node *t);
int dim(node*t);
int* arraytree(node*t);
int arraytree_aux(node *t,int *a,int i);
int max(int a,int b){
	if (a>b)
		return a;
	if(a<b)
		return b;
	return a;
}
int main(){
	node *T;
	T=NULL;
	int n;
	int i;
	int k;	

	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&k);
		insert(&T,k);
	}
	arraytree(T);
	//printf("%d\n",altezza(T));
	
}



void insert(node **t,int k){
	if(*t==NULL){
		node* new=malloc(sizeof(node));
		new->key=k;
		new->right=new->left=NULL;
		*t=new;
		return;
	}
	if((*t)->key<k)
		insert(&(*t)->right,k);
	else insert(&(*t)->left,k);
}

void libera(node *t){
	if(t!=NULL){
		libera(t->left);
		libera(t->right);
		free(t);
	}
}

int altezza(node*t){
	if(t==NULL){
		return 0;
	}
	else {
		int altsx=altezza(t->left);
		int altdx=altezza(t->right);
		int h=max(altsx,altdx);
		return 1+h;
	}
}
int dim(node*t){
	if(t!=NULL){
		return 1+dim(t->left)+dim(t->right);
	}
	return 0;
}	
int* arraytree(node*t){
	int n=dim(t);
	int i;
	int *a=malloc(n*sizeof(int));
	arraytree_aux(t,a,-1);
	for(i=0;i<n;i++){
		printf("%d\n",a[i]);
	}
	return a;
}
int arraytree_aux(node *t,int *a,int i){
	if(t==NULL){
		return i;
	}
	int index;
	index=arraytree_aux(t->left,a,i);
	++index;
	//printf("\n%d e il so index %d \n",t->key,index	);
	a[index]=t->key;
	index=arraytree_aux(t->right,a,index);
	return index;
}

	
