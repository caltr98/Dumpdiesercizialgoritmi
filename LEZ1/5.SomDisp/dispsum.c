#include <stdio.h>
int dispsum(int n);
int innerdisp(int n,int lastcall);

int main (){
	int n=0;
	scanf("%d",&n);
	printf("%d\n",dispsum(n));
	return 0;
}

int dispsum(int n){
	return innerdisp(n,-1);
}

int innerdisp(int n,int lastcall){
	if(n==0)
		return 0;
	if(lastcall==-1)
		return 1+innerdisp(n-1,1);
	int x=lastcall+2;
	return x+innerdisp(n-1,x);
}
