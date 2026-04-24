//UNIPAMPA - Laboratório de Programação I 
//Prof. Julio Saraçol
#include <stdio.h>
#include <stdlib.h>

int main(){

FILE *arquivoEntrada;
FILE *arquivoSaida;

//criando um arquivo de entrada e um arquivo de saida
arquivoEntrada = fopen("entrada.txt","r");
arquivoSaida   = fopen("saida.txt","w");
//testa se tudo ocorreu direito
if(arquivoEntrada == NULL){
	printf("Erro ao criar arquivo entrada\n");
	exit(-1);
}
if(arquivoSaida == NULL){
	printf("Erro ao criar arquivo de saida\n");
	exit(-1);
}

//FGETC - lendo o arquivo caractere a caractere
char c;
while( (c = fgetc(arquivoEntrada)) != EOF){
	printf("%c",c);
	//FPUTC escrevendo caractere a caractere no arquivo de saída
	fputc(c,arquivoSaida);
}

//fecha o arquivo de entrada
fclose(arquivoEntrada);
fclose(arquivoSaida);





return 0;
}
