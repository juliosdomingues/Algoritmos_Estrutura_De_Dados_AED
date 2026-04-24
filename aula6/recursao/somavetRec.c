#include <stdio.h>
#include <stdlib.h>

int somaVet(int *vet, int tam, int pos);
int somaVetIndex(int *vet, int pos);
int main(){
	int *vet, i, tam;
	setbuf(stdin, NULL);
	scanf("%d",&tam);
	vet = (int *) malloc (sizeof(int) *tam);
	for(i=0;i<tam;i++){
		setbuf(stdin, NULL);
		//scanf("%d",&vet[i]);
		vet[i]=i;
	}
	int soma = somaVet(vet,tam, (tam-1));
	printf("soma é %d", soma);
	soma = somaVetIndex(vet,(tam-1));
	printf("soma é %d", soma);
return 0;
}

int somaVet(int *vet, int tam, int pos){
	printf("somavet tam %d, pos %d\n",tam,pos);
	if(pos == 0){
		return vet[pos];
	}
	else{
     	printf("somavet tam %d, pos %d\n",tam,pos);
		return vet[pos]+somaVet(vet, tam, (pos-1));
	}
}
int somaVetIndex(int *vet, int pos){
	if(pos == 0){
		return vet[pos];
	}
	else{
		return vet[pos]+somaVetIndex(vet,(pos-1));
	}
}
