#include <stdio.h>
#define DIM 4

int sum(int a[],int sx,int dx);

int main (){
	int a[DIM];
	int i=0;
	for(i=	0;i<DIM;i++)
		scanf("%d",&a[i]);
	printf("somma :%d\n",sum(a,0,DIM-1));
	return 0;
}

int sum(int a[],int sx,int dx){
	if(sx==dx)
		return a[sx];
	else {
		int cx=(sx+dx)/2;
		int a1=sum(a,sx,cx);
		int a2=sum(a,sx,cx);
		int a3=sum(a,cx+1,dx);
		int a4=sum(a,cx+1,dx);
		return ((a1+a2)/2)+((a3+a4)/2);
	}
	return 0;
}
