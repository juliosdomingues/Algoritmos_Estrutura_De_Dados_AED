#include <stdio.h>
#include <stdlib.h>
void swap(int a, int b);
void troca(int *a, int *b);
void vetor(int *vet, int *tamanho);
int main(){
	int a = 1;
	int b = 2;
	int *pa = &a;
	int *pb = &b;	
	printf("valor original antes da função a=%d valor de b=%d\n",a,b);
	swap(a,b);
	printf("valor depois da função a=%d valor de b=%d\n",a,b);
	troca(pa,pb);
	printf("valor depois da função a=%d valor de b=%d\n",a,b);
	/*int tamanho=10;
	int *vet =(int *) malloc(sizeof(int)*tamanho);
	int i;
	for(i=0;i<10;i++){
		vet[i]=1;
	}
	vetor(vet,&(tamanho));
	*/
	return 0;
}

void swap(int a, int b){
	int temp = b;
	b=a;
	a=temp;
	printf("dentro da função valor a %d valor de b %d\n",a,b);
}
void troca(int *a, int *b){
	int temp = *b;
	*b=*a;
	*a=temp;
	printf("dentro da função valor a %d valor de b %d\n",*a,*b);
}
void vetor(int *vet, int *tamanho){
	int i;
	for(i=0;i<*tamanho;i++){
		printf("%d - \n",vet[i]);
	}
}


