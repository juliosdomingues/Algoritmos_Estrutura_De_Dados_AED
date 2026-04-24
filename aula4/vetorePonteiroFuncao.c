#include <stdio.h>
#include <stdlib.h>

void impressao(int *meuVetor, int tamanho);

int main(){

	int vetor[10];
	int *vet;
	//cast casting
	vet = (int *) malloc(sizeof(int)*10);
	int i;
	for(i=0;i<10;i++){
		vet[i] = i;
		vetor[i] = 2*i;
	}
	impressao(vetor,10);
	impressao(vet,10);
	 return 0;
}
void impressao(int *meuVetor, int tamanho){
	int i;
	for(i=0;i<10;i++){
		printf("vet[%d]=%d\n",i,meuVetor[i]);
	}
}
