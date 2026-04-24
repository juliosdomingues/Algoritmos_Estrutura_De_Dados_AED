//UNIPAMPA - Laboratório de Programação I 
//Prof. Julio Saraçol
#include <stdio.h>
#include <stdlib.h>

int main(){

FILE *arquivoEntradaBinario;

//criando um arquivo de entrada e um arquivo de saida
arquivoEntradaBinario = fopen("saida.bin","rb");
//testa se tudo ocorreu direito
if(arquivoEntradaBinario == NULL){
	printf("Erro ao criar arquivo entrada binario\n");
	exit(-1);
}
char texto[1000];
texto[0]='\0';
int i=0;

//faz a leitura do tamanho de elementos que serão lidos (char)
fread(&i,sizeof(int),1,arquivoEntradaBinario);
fread(&texto,sizeof(char),i,arquivoEntradaBinario);

printf("%s\n",texto);
printf("com o tamanho %d\n",i);

//fecha o arquivo de entrada
fclose(arquivoEntradaBinario);

return 0;
}
