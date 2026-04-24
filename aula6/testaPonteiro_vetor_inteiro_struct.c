#include <stdio.h>
#include <stdlib.h>

struct vetor{
	int valor;
};

typedef struct vetor pontVet;

void swap(int *a, int *b);

int inicializa(int *vetorPonteiro);
int inicializaPonteiro(int **vetorPonteiro);



int inicializaStruct(struct vetor *vetorPonteiro);
int inicializaPonteiroStruct(struct vetor **vetorPonteiro);
int inicializaStructTypedef(pontVet*vetorPonteiro);
int inicializaPonteiroStructTypedef(pontVet **vetorPonteiro);
void inicializaStructPreAlocada(struct vetor *vetorPonteiro);



int main(){
/*
int vet[10] ={1};
int b = 2;
/*printf("vet[0]= %d b=%d\n",vet[0],b);
swap(&vet[0],&b);
printf("vet[0]= %d b=%d\n",vet[0],b);

//--------------------------------------------
b = 2;

int *pvet;

//int qtd2 = inicializa(pvet); //trabalhando com cópia do ponteiro (tipo original é ponteiro)
//int qtd = inicializa(vet); //trabalhando com o ponteiro para a variavel primitiva

int qtd = inicializaPonteiro(&pvet); //trabalhando com o ponteiro para ponteiro

printf("pvet[0]= %d b=%d\n",pvet[0],b);
swap(&pvet[0],&b);
printf("pvet[0]= %d b=%d\n",pvet[0],b);
*/

struct vetor vetorS[10];
int i;
for(i=0;i<10;i++)
	vetorS[i].valor =1;
for(i=0;i<10;i++)
	printf("conteudo do vetorS[%d] = %d\n",i,vetorS[i].valor);

struct vetor *pVetor = NULL;
pontVet *pontVetor = NULL;

//i = inicializaStruct(pVetor);
//i = inicializaPonteiroStruct(&pVetor);
//for(i=0;i<10;i++)
//	printf("conteudo do pVetor[%d] = %d\n",i,pVetor[i]);

//i = inicializaStructTypedef(pontVetor);
//i = inicializaPonteiroStructTypedef(&pontVetor);
//for(i=0;i<10;i++)
//	printf("conteudo do pontVetor[%d] = %d\n",i,pontVetor[i]);
	
struct vetor *pVetorAlocado = NULL;
pVetorAlocado = (struct vetor *) malloc(sizeof(struct vetor)*10);
inicializaStructPreAlocada(pVetorAlocado);
for(i=0;i<10;i++)
	printf("conteudo do pontVetorAlocado[%d] = %d\n",i,pVetorAlocado[i].valor);

return 0;
}

void swap(int *a, int *b){
	int aux;
	aux = *a;
	*a = *b;
	*b =aux;
}


int inicializa(int *vetorPonteiro){
	//vetorPonteiro = (int *) malloc(sizeof(int)*10);
	vetorPonteiro[0] = 1;
	return 10;
}


int inicializaPonteiro(int **vetorPonteiro){
	int *vetorP = (int *) malloc(sizeof(int)*10);
	*vetorPonteiro = vetorP;
	*vetorPonteiro[0] = 1;
	return 10;
}



int inicializaStruct(struct vetor *vetorPonteiro){
	vetorPonteiro = (struct vetor*) malloc(sizeof(struct vetor)*10);
	return 10;
}


int inicializaPonteiroStruct(struct vetor **vetorPonteiro){
	struct vetor *vetorP = (struct vetor *) malloc(sizeof(struct vetor)*10);
	*vetorPonteiro = vetorP;
	return 10;
}


int inicializaStructTypedef(pontVet *vetorPonteiro){
	vetorPonteiro = (pontVet *) malloc(sizeof(pontVet)*10);
	return 10;
}

int inicializaPonteiroStructTypedef(pontVet **vetorPonteiro){
	pontVet *vetorP = (pontVet *) malloc(sizeof(pontVet)*10);
	*vetorPonteiro = vetorP;
	return 10;
}


void inicializaStructPreAlocada(struct vetor *vetorPonteiro){
	int i;
	for(i=0;i<10;i++)
		vetorPonteiro[i].valor=i;
}


