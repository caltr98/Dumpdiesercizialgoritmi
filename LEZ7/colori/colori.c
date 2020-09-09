#include <stdio.h>
#include <stdlib.h>
 
typedef struct colors{
	 int x;
	 int y;
	 int c;
} colori;

typedef struct interrogazione{
	int x1;
	int y1;
	int x2;
	int y2;
	int ris;
}query;
typedef struct interisultato{
	int occ;
	int colore;
}qures;

int cmp(const void *x,const void *y){
	colori *a=(colori*)x;
	colori *b=(colori*)y;
	return (a->c)-(b->	c);
}
int coloricalc(colori *a,int dim);
void trovacolori(colori *a,int n,query *qu,int m);
int main (){
	
	int N;
	int M;
	colori *a;
	query *qu;

	int i;

	scanf("%d",&N);
	scanf("%d",&M);
	a=malloc(N*sizeof(colori));
	for(i=0;i<N;i++){
		scanf("%d",&a[i].x);
		scanf("%d",&a[i].y);
		scanf("%d",&a[i].c);
	}
	qu=(query*)malloc(M*sizeof(query));
	for(i=0;i<M;i++){
		scanf("%d",&qu[i].x1);
		scanf("%d",&qu[i].y1);
		scanf("%d",&qu[i].x2);
		scanf("%d",&qu[i].y2);
	}
	qsort(a,N,sizeof(colori),cmp);


	trovacolori(a,N,qu,M);
	for(i=0;i<M;i++){
		printf("%d\n",qu[i].ris);
	}
	
	return 0;
}



void trovacolori(colori *a,int n,query *qu,int m){
	int i;
	int j;	
	int lastcolor;
	for(i=0;i<m;i++){
		lastcolor=-1;
		qu[i].ris=0;
		for(j=0;j<n;j++){
			if(qu[i].x1<=a[j].x && a[j].x<=qu[i].x2){
				if(qu[i].y1<=a[j].y && a[j].y<=qu[i].y2){
					if(lastcolor!=a[j].c){
						qu[i].ris++; // nel primo ciclo parte da 1 perchè c è sempre positivo(quindi sempre diverso da -1)
						lastcolor=a[j].c;//se incontro un colore diverso dall'ultimo aggiorno(gli uguali saranno sempre vicini)
					}
				}
			}
		}
	}
				 
}	
	
	


