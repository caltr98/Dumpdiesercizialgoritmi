#include <stdlib.h>
#include <stdio.h>


void swap(int *p,int *q){
	int tmp=*p;
	*p=*q;
	*q=tmp;
}
int distribuzione(int a[], int sx, int px, int dx) {
	int i,j;
	swap(&a[px],&a[dx]);
	j=sx-1;
	for(i=sx;i<=(dx-1);i++){
		if(a[i]%2 == 0 ){
			if (a[dx]%2 == 0 && a[i]<=a[dx]){
				j++;
				swap(&a[j],&a[i]);
			}
			else if (a[dx]%2 != 0 ){
				j++;
				swap(&a[j],&a[i]);
			}
			
		}
		else{
			if(a[dx]%2 != 0 && a[i]<=a[dx]){
				j++;
				swap(&a[j],&a[i]);
			}
		}
	}

	
	swap(&a[j+1],&a[dx]);
	return j+1;
}

void quicksort( int a[], int sx, int dx ) {
  
  int perno, pivot;
  if( sx < dx ) {

    pivot = (rand() % (dx-sx+1) )+sx;
    perno = distribuzione(a, sx, pivot, dx); // separa gli elementi minori di a[pivot] 
					     // da quelli maggiori o uguali 
    /* Ordina ricorsivamente le due metà */
    quicksort(a, sx, perno-1);
    quicksort(a, perno+1, dx);
    
  }

}
q
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
