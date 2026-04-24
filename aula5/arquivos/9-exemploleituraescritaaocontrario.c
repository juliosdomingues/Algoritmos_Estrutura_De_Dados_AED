#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct produto{	
	int codigo;
	float valor;
	char nome[100];
}; //100+4+8 =108bytes


int main(){

int i;

//cria vetor de produtos com nome produto_a produto_b etc...
struct produto *novoProduto = (struct produto *) malloc(sizeof(struct produto) * 5);
char produtoNome [10];
int item = 'a';
strcat(produtoNome,(char *)&(item));

for(i=0;i<5;i++){
	novoProduto[i].codigo 	=i+1;
	novoProduto[i].valor 	=(i+1)*5;
	strcpy(produtoNome,"produto_");
	strcat(produtoNome,(char *)&(item));
	strcpy(novoProduto[i].nome,produtoNome);
	item++;
}

FILE *arquivoEscrita = fopen("produtos.bin","wb");

if(arquivoEscrita == NULL){
	printf("erro de abertura arquivo\n");
	exit(-1);
}
//fwrite(item,sizeof(int),1,arquivoEscrita);
fwrite(novoProduto,sizeof(struct produto),5,arquivoEscrita);
fclose(arquivoEscrita);

printf("lista de produtos criada no arquivp produtos.bin\n");
getchar();
//
//--codigo de leitura do arquivo
FILE *arquivoLeitura = fopen("produtos.bin", "rb");

if(arquivoLeitura == NULL){
	printf("erro de abertura arquivo leitura\n");
	exit(-1);
}

getchar();

printf("%%%%%%%%%%%%%%%%%%IMPRESSÃO AO CONTRARIO%%%%%%%%%%%%%%%%%%%%%%\n");
//movimenta para o final
struct produto *elementosCarregadosInverso = (struct produto *) malloc(sizeof(struct produto));

for(i=1;i<=5;i++){
	int offset = (int) (sizeof(struct produto)*i*-1); 
	printf("tamanho offset %d\n",offset);
	fseek(arquivoLeitura, offset ,SEEK_END); //posiciona o ponteiro de arquivo no final, volta 108bytes -108 *2 = -216

	fread(elementosCarregadosInverso,sizeof(struct produto),1,arquivoLeitura);

	printf("o conteúdo do arquivo é:\n");

	printf("produto nome: %s, produto codigo: %d, produto valor: %f\n",elementosCarregadosInverso->nome, elementosCarregadosInverso->codigo, elementosCarregadosInverso->valor);
}
printf("%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n");


rewind(arquivoLeitura);//reposiciona o ponteiro de arquivo para o inicio.

struct produto *elementosCarregados = (struct produto *) malloc(sizeof(struct produto) * 5);
printf("%%%%%%%%%%%%%%%%%%IMPRESSÃO NA ORDEM%%%%%%%%%%%%%%%%%%%%%%\n");
fread(elementosCarregados,sizeof(struct produto),5,arquivoLeitura);
for(i=0;i<5;i++){
	printf("produto nome: %s, produto codigo: %d, produto valor: %f\n",elementosCarregados[i].nome, elementosCarregados[i].codigo, elementosCarregados[i].valor);
}
printf("%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n");
fclose(arquivoLeitura);

return 0;
}
