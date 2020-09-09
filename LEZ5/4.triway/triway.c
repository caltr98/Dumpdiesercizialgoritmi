#include <stdlib.h>
#include <stdio.h>


void swap(int *p,int *q){
	int tmp=*p;
	*p=*q;
	*q=tmp;
}
void distribuzione(int a[], int sx, int px, int dx,int *left,int *right) {
	int i,j,k;
	swap(&a[px],&a[sx]);
	k=sx;
	j=dx;
	for(i=sx;i<=j;i++){
		if(a[i]<a[k]){
			swap(&a[i],&a[k]);
			k++;	
		}
		else if (a[i]>a[k]){
			swap(&a[i],&a[j]);
			j--;
			i--;
		}
	}
	*left=k;
	*right=j;
}
void quicksort( int a[], int sx, int dx) {
  
  int pivot;
	int tiny,big;
  if( sx < dx ) {

    pivot = (rand() % (dx-sx+1) )+sx;

    distribuzione(a, sx, pivot, dx,&tiny,&big); // separa gli elementi minori di a[pivot] 
					     // da quelli maggiori o uguali e mi restituisce gli indici delle porzioni non uguali al pivot
    /* Ordina ricorsivamente le due metà */
    quicksort(a, sx, tiny-1);
    quicksort(a, big+1, dx);
    
  }

}

/* Lettura di un array di interi da input. 
Il primo elemento è la lunghezza dell'array */
int legge(int **a, int *len) {

  int i;
  scanf("%d", len);
  if(*len <= 0) return 1;

  *a = (int *) malloc(*len * sizeof(int));
  if(*a == NULL) return 1;

  for( i = 0; i < *len; i++ ) 
	  scanf("%d", (*a)+i);
  
  return 0;

}

int main() {
  
  int i, n, *A;

  if( legge(&A, &n)) return 1;


  quicksort(A, 0, n-1);
  
  /* Stampa l'array ordinato */
  for( i = 0; i < n; i++ ) 
    printf("%d ", A[i]);
	
  return 0;
}

