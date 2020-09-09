#include <stdio.h>
#include <math.h>

int check (int n);
double 	sqrt (double x);
int main (){
	int n=0;
	scanf("%d",&n);
	printf("%d\n",check(n));
	return 0;
}

int check (int n){
	int lim=sqrt(n);
	int corr=2;
	while(corr<=lim){
		if(n%corr==0)
			return 0;
		corr++;
	}
	return 1;
}
