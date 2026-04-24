#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct produto{
	char nome[50];
	int quantidade;
}; //54bytes


int main(){


FILE *arquivoEntrada;
arquivoEntrada = fopen("listaProdutos.bin","rb");
if(arquivoEntrada == NULL){
	printf("erro de abertura arquivo\n");
	exit(-1);
}
int tipo;
struct produto meuProduto;
//char tipo[10];
fread(&tipo,sizeof(int),1,arquivoEntrada);
//fread(&tipo,sizeof(char),10,arquivoEntrada);
//	printf("%s\n",tipo);
if(tipo==1){
	printf("tipo PADARIA\n");
}
else{
	printf("tipo CHURRASCO\n");
}


  while((fread(&meuProduto,sizeof(struct produto),1,arquivoEntrada)) > 0){
	printf("NOME: %s\n",meuProduto.nome);
	printf("QUANTIDADE: %d \n",meuProduto.quantidade);
	printf("%d\n",feof(arquivoEntrada));
  }


//OU testando no final, acaba reimprimindo o ultimo lido
int sizeLido;
do{
	sizeLido = fread(&meuProduto,sizeof(struct produto),1,arquivoEntrada);
	printf("lido %d bytes\n",sizeLido); 
	printf("NOME: %s\n",meuProduto.nome);
	printf("QUANTIDADE: %d \n",meuProduto.quantidade);
}while(feof(arquivoEntrada) != 1);



fclose(arquivoEntrada);
}
