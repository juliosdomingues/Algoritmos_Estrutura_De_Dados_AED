#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	char nomeArqEntrada[50],nomeArqSaida[50];
	FILE *arquivoEntrada;
	FILE *arquivoSaida;
	
	setbuf(stdin,NULL);
	printf("entre com o nome do arquivo de entrada\n");
	scanf("%[^\n]s",nomeArqEntrada);
	if((arquivoEntrada = fopen(nomeArqEntrada,"r"))==NULL){
		printf("ERRO AO ABRIR O ARQUIVO de ENTRADA\n");
		exit(-1);
	}
	setbuf(stdin,NULL);
	printf("entre com o nome do arquivo de saida\n");
	scanf("%[^\n]s",nomeArqSaida);
	if((arquivoSaida = fopen(nomeArqSaida,"wb"))==NULL){
		printf("ERRO AO ABRIR O ARQUIVO de SAIDA\n");
		exit(-1);
	}
	
	char 	c;
	int 	i=0;
	char 	frase[200];
	
	while((c = fgetc(arquivoEntrada)) != EOF){
		if(c == '\n'){
			frase[i] = '\0';
			fwrite(&frase,sizeof(char),i,arquivoSaida);
			fwrite(&"\n",sizeof(char),1,arquivoSaida);
			frase[0]='\0';
			i=0;
		}
		else{
				frase[i] = c;
				i++;
		}
	} 	
	fclose(arquivoEntrada);
	fclose(arquivoSaida);
return 0;
}
