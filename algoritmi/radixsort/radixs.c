#include <stdio.h>
#include <stdlib.h>
#include<string.h>

void radixsort(char **a,int n,int d);
int cmp(const void *x,const void *y);

int main(){
	int n;
	int d;
	char **a;
	int i;

	scanf("%d",&n);
	scanf("%d",&d);
	a=(char**)malloc(n*sizeof(char*));
	for(i=0;i<n;i++){
		a[i]=(char*)malloc((d+1)*sizeof(char));
		scanf("%s",(a[i]));
	}
    radixsort(a,n,d);
	for(i=0;i<n;i++){
		printf("%s",(a[i]));
		printf("\n");
	}
	return 0;
}

void radixsort(char **a,int n,int d){
       qsort(a,n,sizeof(char*),cmp);
}

int cmp(const void *x,const void *y){
    char *a=*(char**)x;
    char *b=*(char**)y;
    return strcmp(a,b);
}



