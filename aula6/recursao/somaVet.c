#include <stdio.h>
#include <stdlib.h>

int somaVet(int tamV, int *vet);
int somaVet2(int tamV, int index, int *vet);

int main(){
	int *vet=NULL;
	int tamanhoVet,i;
	scanf("%d",&tamanhoVet);
	vet = (int *) malloc(sizeof(int)*tamanhoVet);
	for(i=0;i< tamanhoVet;i++){
		vet[i] = random()%10;
		printf("Vetor%d, ",vet[i]);
	}
	
	//int resultado = somaVet((tamanhoVet-1),vet);
	int resultado = somaVet2((tamanhoVet-1),0,vet);
	printf("\n resultado %d", resultado);
	return 0;
}

int somaVet(int tamV, int *vet){
	printf("chamada recursiva para o calculo da posicao %d\n",tamV);
	if(tamV == 0){
		return vet[0];
	}
	else{
		int resultado = (vet[tamV]+somaVet((tamV-1), vet));
		printf("resultado soma com subvetor %d\n", resultado);
		return resultado;
	}
}


int somaVet2(int tamV, int index, int *vet){
	printf("chamada recursiva para o calculo da posicao %d\n",indexw);
	if(tamV == index){
		return vet[index];
	}
	else{
		
		int resultado = vet[index];
		index++;
		resultado = resultado + somaVet2(tamV,index, vet);
		printf("resultado soma com subvetor %d\n", resultado);
		return resultado;
	}
}

