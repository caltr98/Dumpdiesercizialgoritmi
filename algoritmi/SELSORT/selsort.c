#include <stdio.h>
#define DIM 5

void selsort(int a[]);
void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 

int main(){
	int a[DIM]={1,3,4,1,2};
	int i;
	for(i=0;i<DIM;i++){
		scanf("%d",&a[i]);
	 }
	selsort(a);
    printf("\n");
	for(i=0;i<DIM;i++){
		printf("%d\n",a[i]);
	 }
	return 0;
}

void selsort (int a[]){
	int dim=DIM;	
	int i,j;
	int min;
	int tmp;    
	for(i=0;i<(dim-1);i++){
		min=i;
		for(j=i+1;j<DIM;j++){
			if(a[j]<a[min]){
				min=j;
			}
		}
        tmp=a[min];
        a[min]=a[i];
        a[i]=tmp;
        //swap(&a[min], &a[i]); 
	}
}
