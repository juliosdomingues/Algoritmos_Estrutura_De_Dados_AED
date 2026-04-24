#include <stdio.h>
#include <stdlib.h>
int main (void){
	int *p,*p2;
	int a;
	int i;
	a = 30;
	p=(int *)malloc(a*sizeof(int));		/* Aloca a números inteiros p pode agora ser tratado como um vetor com a posicoes e inicializa*/
	if (!p){
        	printf ("** Erro: Memoria Insuficiente **");
        	exit (-1);
    }
	for (i=0; i<a ; i++){		/* p pode ser tratado como um vetor com a posicoes */
		printf("p[%d]= %d ",i,p[i]);
	}
	printf("\n====================\n");
	p2 = calloc(a, sizeof(int));
	for (i=0; i<a ; i++){		/* p pode ser tratado como um vetor com a posicoes */
		printf("p[%d]= %d ",i,p2[i]);
	}
	return 0;
}
