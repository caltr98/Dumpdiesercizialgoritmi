#include <stdio.h>
#include <stdlib.h>

typedef struct bs{
	int info;
	struct bs* right;
	struct bs* left;
}BST;
int findmax(int seq[],int n);
void buildBST(BST **head,int seq[]);
int cmp(const void *x,const void *y){
	int a=*(int*)x;
	int b=*(int*)y;
	return a-b;
}

int main(){
	int n;
	int *a;
	int i;
	BST *head;
	head=NULL;
	scanf("%d",&n);
	a=(int*)malloc(sizeof(int));
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	qsort(a,n,sizeof(int),cmp);
	/*for(i=0;i<n;i++)
		printf("%d",a[i]);
	*/
	return 0;
}
int findmax(int seq[],int n){
void buildBST(BST **head,int seq[],int n){
	int root=n/2;
	*head->info=seq[root];
	
