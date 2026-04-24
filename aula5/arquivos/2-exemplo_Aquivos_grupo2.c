//UNIPAMPA - Laboratório de Programação I 
//Prof. Julio Saraçol
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

FILE *arquivoEntrada;
FILE *arquivoSaida;

//criando um arquivo de entrada e um arquivo de saida
arquivoEntrada = fopen("entrada2.txt","r");
arquivoSaida   = fopen("saida2.txt","w");
//testa se tudo ocorreu direito
if(arquivoEntrada == NULL){
	printf("Erro ao criar arquivo entrada\n");
	exit(-1);
}
if(arquivoSaida == NULL){
	printf("Erro ao criar arquivo de saida\n");
	exit(-1);
}

//FGETs - lendo o arquivo em porções de caracteres
char frase[256];
int tamanho = 0;
do{
	frase[0]='\0';
	fgets(frase,255,arquivoEntrada);
	tamanho = (int)strlen(frase);
	printf("%s",frase);
	//FPUTS - escrevendo porções de caracteres no arquivo de saída
	fputs(frase,arquivoSaida);
	fprintf(arquivoSaida," %d\n",tamanho);
}while(tamanho > 1);

//fecha o arquivo de entrada
fclose(arquivoEntrada);
fclose(arquivoSaida);
return 0;
}
