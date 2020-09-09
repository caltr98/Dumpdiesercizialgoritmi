#include <stdio.h>
#include <stdlib.h>
#define DIM 6
void merge(int a[],int p,int q,int r);
void mergesort(int a[],int p,int dim);

int main () {
	int a[DIM];
	for(int i=0;i<DIM;i++)
		scanf("%d",&a[i]);
	mergesort(a,0,DIM-1);
	printf("\n");	
	for(int i=0;i<DIM;i++)
		printf("%d\n",a[i]);	
	return 0;
}

void mergesort (int a[],int p,int dim){
	if(p<dim){
		int m = (p+dim)/2;
		mergesort(a,p,m);
		mergesort(a,m+1,dim);
		merge(a,p,m,dim);
	}
}
void merge(int a[],int p,int q,int r){
	int dim1=q-p+1;
	int dim2=r-q;
	
	int *sx;
	sx=(int*)malloc(dim1*sizeof(int));
	int *dx;
	dx=(int*)malloc(dim2*sizeof(int));
	int i,j,k;
	i=j=k=0;
	for(i=0;i<dim1;i++){
		sx[i]=a[p+i];
	}
	for(j=0;j<dim2;j++){
		dx[j]=a[q+j+1];
	}
	i=j=0;
	for(k=p;k<=r;k++){
		if(j>=dim2){
			a[k]=sx[i];
			i++;
		}
		else if(i>=dim1){
			a[k]=dx[j];
			j++;
		}
		else if(sx[i]<=dx[j]){
			a[k]=sx[i];
			i++;		
		}
		else {
			a[k]=dx[j];
			j++;
		}
	}
}



