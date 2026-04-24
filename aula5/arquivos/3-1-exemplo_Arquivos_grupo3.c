//UNIPAMPA - Laboratório de Programação I 
//Prof. Julio Saraçol
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

FILE *arquivoEntrada;
FILE *arquivoSaida;

//criando um arquivo de entrada e um arquivo de saida
arquivoEntrada = fopen("entrada3.txt","r");
arquivoSaida   = fopen("saida3.txt","w");
//testa se tudo ocorreu direito
if(arquivoEntrada == NULL){
	printf("Erro ao criar arquivo entrada\n");
	exit(-1);
}
if(arquivoSaida == NULL){
	printf("Erro ao criar arquivo de saida\n");
	exit(-1);
}

//Fscanf- lendo o arquivo em porções de caracteres
char frase[256];
char caractere;
int nota;
frase[0]='\0';
fscanf(arquivoEntrada,"%s",frase);
//fscanf(arquivoEntrada,"%c",&caractere);
fscanf(arquivoEntrada,"%d",&nota);
printf("%s %d",frase,nota);
//fprintf - escrevendo porções de caracteres no arquivo de saída
fprintf(arquivoSaida,"a frase lida: %s\n",frase);
fprintf(arquivoSaida,"e o valor lido é esse: %d",nota);

//fecha o arquivo de entrada
fclose(arquivoEntrada);
fclose(arquivoSaida);
return 0;
}
