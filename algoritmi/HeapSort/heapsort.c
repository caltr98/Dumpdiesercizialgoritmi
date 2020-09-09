#include <stdio.h>
#include <stdlib.h>

void maxheapify(int a[],int x,int heapsize);
void buildmaxheap(int a[],int dim);
void heapsort(int a[],int dim);

void swap(int *a,int *b){
	int tmp=*a;
	*a=*b;
	*b=tmp;
}

void maxheapify(int a[],int x,int heapsize){
	int left=(2*x)+1;
	int right=(2*x)+2;
	int largest;
	if(left<=heapsize && a[x]<a[left])
		largest=left;
	else 
		largest=x;
	if(left<=heapsize && a[largest]<a[right])
		largest=right;
	if(largest!=x){
		swap(&a[largest],&a[x]);
		maxheapify(a,largest,heapsize);
	}
}

void buildmaxheap(int a[],int heapsize){
	int i;
	for(i=((heapsize/2));i>=0;i--)
		maxheapify(a,i,heapsize);
}
void heapsort(int a[],int dim){	
	int heapsize=dim-1;
	int i;
	buildmaxheap(a,heapsize);
	for(i=dim-1;i>=1;i--){
		swap(&a[0],&a[i]);
		maxheapify(a,0,heapsize);
	}	
}

int main(){
	int *array;
	int n;
	int i;
	scanf("%d",&n);
	array=(int*)malloc(n*sizeof(int));

	for(i=0;i<n;i++)
		scanf("%d",&array[i]);
	heapsort(array,n);
	for(i=0;i<n;i++)
		printf("-> %d ",array[i]);
	printf("\n"); 
	
	return 0;
}
	

