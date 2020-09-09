#include <stdio.h>
int main(){
	int n=0;
	int somma=0;
	scanf("%d",&n);
	while(n!=0){
		somma+=n;
		scanf("%d",&n);
	}
	printf("%d\n",somma);
	return 0;
}
