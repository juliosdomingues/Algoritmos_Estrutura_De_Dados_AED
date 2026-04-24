//UNIPAMPA - Laboratório de Programação I 
//Prof. Julio Saraçol
#include <stdio.h>
#include <stdlib.h>

int main(){

FILE *arquivoEntrada;
FILE *arquivoSaidaBinario;

//criando um arquivo de entrada e um arquivo de saida
arquivoEntrada        = fopen("entrada.txt","r");
arquivoSaidaBinario   = fopen("saida.bin","wb");
//testa se tudo ocorreu direito
if(arquivoEntrada == NULL){
	printf("Erro ao abrir arquivo entrada\n");
	exit(-1);
}
if(arquivoSaidaBinario == NULL){
	printf("Erro ao criar arquivo de saida\n");
	exit(-1);
}

char c;
char texto[1000];
texto[0]='\0';
int i=0;

while( (c = fgetc(arquivoEntrada)) != EOF){
	printf("%c",c);
    texto[i] = c;
    i++;
}
texto[i]='\0';
i++;
printf("%s\n",texto);
printf("com o tamanho %d\n",i);

fwrite(&i,(sizeof(int)),1,arquivoSaidaBinario);
fwrite(&texto,(sizeof(char)),i,arquivoSaidaBinario);
//fecha o arquivo de entrada
fclose(arquivoEntrada);
fclose(arquivoSaidaBinario);
return 0;
}
