#include <stdio.h>
#include <stdlib.h>

int somaVet(int v[],int tamanho);

int main(){
	int i,n =5;
	int vet[n];
	for(i=0;i<n;i++)
		scanf("%d",&vet[i]);
	int soma = somaVet(vet,(n-1));
	printf("soma eh %d", soma);
	return 0;
}
int somaVet(int v[],int tamanho){
	if(tamanho == 0)
		return v[tamanho];
	else
		return v[tamanho] + somaVet(v,tamanho-1);	
	
}

