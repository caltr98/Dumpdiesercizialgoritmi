#include <stdio.h>

void swap(int*p,int *q,int *z);

int main (){
	int x;
	int y;
	int z;

	scanf("%d",&x);
	scanf("%d",&y);
	scanf("%d",&z);
	swap(&x,&y,&z);
	printf("%d\n",x);
	printf("%d\n",y);
	printf("%d\n",z);
	return 0;
}

void swap(int *p,int *q,int *z){
	int tmp;
	tmp=*p;
	*p=*z;
	*z=*q;
	*q=tmp;
}

