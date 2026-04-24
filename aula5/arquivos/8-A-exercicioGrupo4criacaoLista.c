#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct produto{
	char nome[50];
	int quantidade;
};



int main(){


FILE *arquivoSaida;
arquivoSaida = fopen("listaProdutos.bin","wb");
if(arquivoSaida == NULL){
	printf("erro de abertura arquivo\n");
	exit(-1);
}


int tipo, opcao=1;
printf("tipo de lista: 1-padaria, 2 churrasco\n");
setbuf(stdin,NULL);
scanf("%d",&tipo);
if(tipo==1){
	//fwrite("PADARIA\n",sizeof(char),strlen("PADARIA\n"),arquivoSaida);
	fwrite(&tipo,sizeof(int),1,arquivoSaida);
}else{
	//fwrite("CHURRASCO\n",sizeof(char),strlen("CHURRASCO\n"),arquivoSaida);
	fwrite(&tipo,sizeof(int),1,arquivoSaida);
}
while(opcao !=0){
	struct produto meuProduto;
	//char meuProduto[50];
	printf("Digite o nome do produto\n");
	setbuf(stdin,NULL);
	scanf("%[^\n]s", meuProduto.nome);
	//scanf("%[^\n]s", meuProduto);
	printf("quantidade:\n");
	setbuf(stdin,NULL);
	//int quantidade;
	scanf("%d",&meuProduto.quantidade);
	//scanf("%d",&quantidade);
	//gera saida
	fwrite(&meuProduto,sizeof(struct produto),1,arquivoSaida);
	//fwrite(&meuProduto.nome,sizeof(char),50,arquivoSaida);
	//fwrite(&quantidade.quantidade,sizeof(int)1,1,arquivoSaida);
	printf("Mais um produto? 1-Sim 0-Não\n");
	setbuf(stdin,NULL);
	scanf("%d",&opcao);
}
fclose(arquivoSaida);
}
