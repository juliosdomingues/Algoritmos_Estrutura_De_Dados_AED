#include <stdio.h>
#include <stdlib.h>
int main (void){
	int *p;
	int a;
	int i;
	a = 30;
	p=(int *)malloc(a*sizeof(int));		/* Aloca a números inteiros p pode agora ser tratado como um vetor com a posicoes*/
	if (!p){
        	printf ("** Erro: Memoria Insuficiente **");
        	exit (-1);
    }
	for (i=0; i<a ; i++){		/* p pode ser tratado como um vetor com a posicoes */
		p[i] = i*i;
		printf("p[%d]= %d ",i,p[i]);
	}
	printf("\n====================\n");
	/* O tamanho de p deve ser modificado, por algum motivo ... */
	a = 100;
	p = realloc (p, a*sizeof(int));
	for (i=0; i<a ; i++){		/* p pode ser tratado como um vetor com a posicoes */
		printf("p[%d]= %d ",i,p[i]);
		//p[i] = a*i*(i-6);
	}
	printf("\n====================\n");
	for (i=0; i<a ; i++){		/* p pode ser tratado como um vetor com a posicoes */		
		if(i>29)
			p[i] = a*i;
		printf("p[%d]= %d ",i,p[i]);
	}
	return 0;
}
