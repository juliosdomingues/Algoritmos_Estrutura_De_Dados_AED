#include <stdio.h>
#include <stdlib.h>


int main (void){
	
int a[3][4];
int l = 1, c = 2;
//indices linha e coluna
int *p=NULL;

for(int i=0;i<3;i++){
	for(int j=0;j<4;j++){
		a[i][j] = rand()%100;
		printf("%d ",a[i][j]);
	}
	printf("\n");
}
p = &(a[0][0]);
//imprime o que está em A[0][0]
printf("conteudo de p = %d\n", *p);
//imprime onde 4 é nº de colunas
printf("%d é o elemento da posicao %d a partir do ponteiro inicial\n", *(p+(l*4)+c),((l*4)+c)); 

return 0;
}
