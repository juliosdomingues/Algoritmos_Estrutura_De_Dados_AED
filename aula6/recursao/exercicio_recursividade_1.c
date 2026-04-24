#include <stdlib.h>
#include <stdio.h>


int somaRecursiva(int vetor[], int tamanho);
float media(int vetor[],int tamanho);
void imprimeDescrecente(int numero);
int exponencial(int k,int n);

int main(){

int n,i;

printf("digite o tamanho do vetor\n");
scanf("%d",&n);
int vetor[n];
for(i=0;i<n;i++)
	scanf("%d",&vetor[i]);
printf("resultado %d\n",somaRecursiva(vetor,n));
printf("resultado %f\n",media(vetor,n));
imprimeDescrecente(n);
printf("exp: %d\n",exponencial(n,n));
return 0;
}

int somaRecursiva(int vetor[], int tamanho){
	if(tamanho == 1)
		return vetor[0];
	else
		return (vetor[tamanho-1]+somaRecursiva(vetor,(tamanho-1)));
}

float media(int vetor[],int tamanho){
	float soma = ((float) somaRecursiva(vetor,tamanho))/tamanho;
	return soma;
}

void imprimeDescrecente(int n){
	if(n==0)
		return;
	if(n%2==0){
		printf("numero par %d",n);
	}
	imprimeDescrecente(n-1);
}

int exponencial(int k,int n){
	if(n==1)
		return k;
	else
		return k*exponencial(k,n-1);
	
}
