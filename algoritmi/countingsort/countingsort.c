#include <stdio.h>
#include<stdlib.h>


int* countsort(int a[],int n,int k);

int main(){
	int n;
	int *a;
	int *b;
	int i;
	int k=0;
	scanf("%d",&n);
	printf("insert the interval from 0 to ...");
	scanf("%d",&k);
	a=(int*)malloc(n*sizeof(int));
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	b=countsort(a,n,k);
	printf("\n");
	for(i=0;i<n;i++){
		printf("%d\n",b[i]);
	}
	return 0;
}


int* countsort(int a[],int n,int k){
	int *c;
	int i;
	int *b;
	b=malloc(n*sizeof(int));
	c=(int*)malloc((k+1)*sizeof(int));
	for(i=0;i<k;i++)
		c[i]=0;
	for(i=0;i<n;i++)
		c[a[i]]++;
	for(i=1;i<=k;i++)
		c[i]+=c[i-1];
	
	for(i=(n-1);i>=0;i--){
		b[c[a[i]]-1]=a[i];
		c[a[i]]--;
	}
	return b;
}
	
	


