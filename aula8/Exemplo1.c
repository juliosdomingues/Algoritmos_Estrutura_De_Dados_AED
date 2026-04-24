#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int linha,coluna,i,j,contador;
	
	linha = 10;
	coluna = 10;
	contador = 0;
	int matrizPreAlocada[linha][coluna];

	
	for(i=0;i<10;i++){
		for(j=0;j<10;j++){
			matrizPreAlocada[i][j] = contador;
			contador++;
		}
	}
	
	for(i=0;i<10;i++){
		for(j=0;j<10;j++){
		  printf("(%d,%d=%d)",i,j,matrizPreAlocada[i][j]);
		}
		printf("\n");
	}
	return 0;
}
