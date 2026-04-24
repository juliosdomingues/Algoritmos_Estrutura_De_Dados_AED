#include <stdio.h>
#include <stdlib.h>


int encontraMenor(int *vet, int tamanho, int menor);
//int encontraMenor(int vet[], int tamanho);

int main(){

int tamanho =5;
int vet[5], i;
for(i=0;i<tamanho;i++){
	scanf("%d",&vet[i]);
}

for(i=0;i<tamanho;i++){
	printf("vet[%d]=%d\n",i,vet[i]);
}

int menor=0;
menor = encontraMenor(vet, tamanho, menor);
// 			encontraMenor(vet,5,0)
printf("o menor é %d e esta na posição %d\n", vet[menor], menor);

return 0;
}
int encontraMenor(int *vet, int tamanho, int menor){
	printf("encontra menor tamanho %d, menor %d\n", tamanho, menor);
	if(tamanho > 0){		
		menor = encontraMenor(vet,(tamanho-1), menor);
		if(vet[tamanho] < vet[menor])
			return tamanho;
		return menor;
	}
   	return menor;
}






