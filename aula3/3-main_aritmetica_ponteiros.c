#include <stdio.h>
#include <stdlib.h>

struct elementoVet{
	int valor;
	int *vetores;
};

void imprime(int *a,int tamanho);

int main(){
	struct elementoVet *vet;
	vet = (struct elementoVet*)malloc(10*sizeof(struct elementoVet));
	vet[0].valor = 3;
	
	int *vet3=NULL;
	vet3 = (int *) malloc(10*sizeof(int));

	vet[0].vetores=vet3;

	int vet2[10];	
	
	int i;
	for(i=0;i<10;i++){
		vet2[i]=i;
	}
	imprime(vet2,10);
	printf("vet2 = %d\n",vet2[0]);
	imprime(vet[0].vetores,10);
		
	return 0;
}

void imprime(int *a,int tamanho){
	int i=0;
	printf("imprimindo crescente\n");
	while(i<tamanho){
		printf("conteudo do vetor %d\n",*a);
		a++;
		i++;
	}
}













