#include <stdio.h>
#define DIM 10
void minmax(int a[],int dim,int *max,int *min);

int main (){
	int a[DIM];
	int max;
	int min;
	for(int i=0;i<DIM;i++)
		scanf("%d",&a[i]);
	minmax(a,DIM,&max,&min);
	printf("%d\n%d\n%d\n%d\n",min,a[min],max,a[max]);
	return 0;
}

void minmax(int a[],int dim,int *max,int *min){
	*max=*min=0;
	for(int i=1;i<dim;i++){
		if((a[i])>(a[*max]))
			*max=i;
		else if(a[i]<a[*min])
			*min=i;
	}
}

