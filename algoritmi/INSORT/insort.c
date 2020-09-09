#include <stdio.h>
#define DIM 10

void insort(int a[],int dim);

int main(){
	int a[DIM];
	for(int i=0;i<DIM;i++)
		scanf("%d",&a[i]);
	insort(a,DIM);
	printf("\n");
	for(int i=0;i<DIM;i++)
		printf("%d\n",a[i]);
	return 0;
}

void insort (int a[],int dim){
	int i;
	int j;
	int key;
	for(i=1;i<dim;i++){	
		key=a[i];
		j=i-1;
		while(j>=0 && a[j]>key){
			a[(j+1)]=a[j];
			j=j-1;
		}
		a[j+1]=key;
	}
}
