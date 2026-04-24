#include <stdio.h>
#include <stdlib.h>

//int dec(int n);
int encmenor(int *vet, int tamV, int menor);


int main(){
/*	int n;
	scanf("%d",&n);
	dec(n);
	* */
		int *vet=NULL;
	int tamanhoVet,i;
	scanf("%d",&tamanhoVet);
	vet = (int *) malloc(sizeof(int)*tamanhoVet);
	for(i=0;i< tamanhoVet;i++){
		vet[i] = random()%10;
		printf("%d  ",vet[i]);
	}
	
	int resultado = encmenor(vet,tamanhoVet,0);
	printf ("posicao %d menor %d\n",resultado,vet[resultado]);
	return 0;
}
/*
int dec(int n){
	if(n==0)
		return 0;
	else{
		if(n%2!=0){
			printf("par %d\n",n);
		}
		dec(n-1);
	}
	
}
*/

int encmenor(int *vet, int tamV, int menor){
	if(tamV==0){
		if(vet[menor] > vet[tamV])
			menor = tamV;
		return menor;
	}
	else{
		menor = encmenor(vet, (tamV-1),menor);
		if(vet[menor] > vet[tamV])
			menor = tamV;
		return menor;
	}
}










