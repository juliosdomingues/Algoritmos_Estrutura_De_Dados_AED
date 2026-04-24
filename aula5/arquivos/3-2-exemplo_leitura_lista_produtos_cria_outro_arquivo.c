#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	char nomeArq[50],nomeArqSaida[50];
	FILE *arquivoEntrada;
	FILE *arquivoSaida;
	
	printf("entre com o nome do arquivo de entrada\n");
	//entrada5.txt
	scanf("%s[^\n]",nomeArq);
	if((arquivoEntrada = fopen(nomeArq,"r"))==NULL){
		printf("ERRO AO ABRIR O ARQUIVO de ENTRADA\n");
		exit(-1);
	}
	printf("entre com o nome do arquivo de saida\n");
	//saida5.txt
	scanf("%s[^\n]",nomeArqSaida);
	if((arquivoSaida = fopen(nomeArqSaida,"w"))==NULL){
		printf("ERRO AO ABRIR O ARQUIVO de SAIDA\n");
		exit(-1);
	}
	
	char 	c;
	int 	i=0;
	char 	nome[200];
	float 	preco;
	int 	quantidade;
	
	while((c = fgetc(arquivoEntrada)) != EOF){
		if((i>1)&&(c == '\n')&&(c != ' ')){
			nome[i] = '\0';
			fscanf(arquivoEntrada,"%d",&quantidade);
			fscanf(arquivoEntrada,"%f",&preco);
			printf("\n--------\nNOME: %s\nPRECO: %f\nQuantidade: %d\n ------------\n",nome,preco,quantidade);
			fprintf(arquivoSaida,"\n--------\nNOME: %s\nPRECO: %f\nQuantidade: %d\n ------------\n",nome,preco,quantidade);
			nome[0]='\0';
			i=0;
			c=' ';
		}
		else{
			if(c!='\n'){
				nome[i] = c;
			 i++;
		    }
		}
		
	} 	
return 0;
}
