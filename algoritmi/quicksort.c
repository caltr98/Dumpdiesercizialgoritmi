#include <stdio.h>
#include <stdlib.h>

void quicksort(int a[],int q,int r);
int partizione(int a[],int q,int r);

int main(){
	int *a;
	int n;
	scanf("%d",&n);
	a=(int*)malloc(n*sizeof(int));
	for(int i=0;i<n;i++){
		scanf("%d",(a+i));
	}
	quicksort(a,0,n);
	for(int i=0;i<n;i++)
		printf("%d\n",a[i]);
	free(a);
	return 0;
}
void quicksort(int a[],int q,int r){
	if(q<r){
		int p=partizione(a,q,r);
		quicksort(a,q,p-1);
		quicksort(a,p+1,q);
	}
}
int partizione(int a[],int q,int r){
	int pivot=r-1;
	int j=0;
	int i=q-1;
	int temp=0;
	for(j=q;j<r-1;j++){
		if (a[j]<=a[pivot]){
			temp=a[++i];
			a[i]=a[j];
			a[j]=temp;
		}			
		else j++;
	}
	temp=a[i++];
	a[i]=a[j+1];
	a[j+1]=temp;
	return i;
}

