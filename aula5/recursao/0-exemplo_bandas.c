#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum tipo{
	rock=1,salsa,samba,reggae,pagode,heavy_metal
};

struct banda{
	char nome[20];
	enum tipo genero;
	int integrantes;
};

void showRank(struct banda *bands, int size);
void showBands(struct banda *bands, int size);
void showSingleBand(struct banda *band);
void decrip(struct banda *band);

void busca_nome(char *name, struct banda *bands, int size);
void busca_genero(int genre, struct banda *bands, int size);

int insertBands(struct banda **ptrBands);
struct banda * renameBand(struct banda *bands,int sizeBands);
void renameBandForRef(struct banda **bands,int sizeBands);

void mudaIntegrantes(struct banda *bandas, int novoIntegrantes);


int main(){
	
	int option=1;
	int sizeBands=0;
	struct banda *bands = NULL;
	while(option > 0){
		printf("QUANTIDADE DE BANDAS %d\n",sizeBands);
		printf("Escolha uma opção: 0-Sair 1-bandas 2-busca nome 3-busca genero\n 4-rank 5-insere 6-altera rank\n");
		scanf("%d[^\n]",&option);
		switch(option){
			case  1: showBands(bands,sizeBands);
					break;
			case 2: 
					printf("digite o nome da banda a ser buscado\n");
					char band[20];
					scanf("%s[^\n]",band);
					busca_nome(band,bands,sizeBands);
					break;
			case 3: 
					printf("digite o estilo da banda a ser buscado\n");
					printf("--Style:rock=1,salsa=2,samba=3,reggae=4,pagode=5,heavy_metal=6\n");
					int genr;
					scanf("%d",&genr);
					printf("-----BANDAS COM O ESTILO:--------\n");
					busca_genero(genr,bands,sizeBands);
					printf("---------------------------------\n");
					break;
			case 4: showRank(bands,sizeBands);
					break;
			case 5: sizeBands = insertBands(&bands);
					showSingleBand(&bands[0]);
					break;
			case 6: //bands = renameBand(bands,sizeBands);
					renameBandForRef(&bands,sizeBands);
					break;
			default:
					printf("\nDigite algo entre 1-6 ou 0 para Sair\n");
		}
	}
	
	return 0;
}


//---------------FUNCAO DE INSERCAO--------------------/
int insertBands(struct banda **ptrBands){
	int sizeBands,i;
	printf("digite o numero de bandas do rank\n");
	scanf("%d",&sizeBands);
	//struct banda *Bands;
	ptrBands = (struct banda **)malloc(sizeof(struct banda *)*sizeBands);
	if(ptrBands != NULL){
	  for(i=0;i<sizeBands;i++){
		printf("\n-----BANDA------\n");
		printf("--Name:\n");
		ptrBands[i] = (struct banda *)malloc(sizeof(struct banda));
		setbuf(stdin,NULL);
		scanf("%s[^\n]",ptrBands[i]->nome);
		setbuf(stdin,NULL);
		printf("--Members:\n");
		scanf("%d",&ptrBands[i]->integrantes);
		printf("--Style:rock=1,salsa=2,samba=3,reggae=4,pagode=5,heavy_metal=6\n");
		int style;
		scanf("%d",&style);
		ptrBands[i]->genero = style; 
		printf("\n---------------\n");
		showSingleBand(ptrBands[i]);
	  }
//	  *ptrprtBands = prtBands;
	}
	else
		exit(-1);
	return sizeBands;
}

struct banda * renameBand(struct banda *bands,int sizeBands){
	int position;
	printf("digite a posição do rank a ser alterada 1-%d\n",sizeBands);
	scanf("%d",&position);
	printf("digite o novo nome da banda\n");
	scanf("%s[^\n]",bands[position-1].nome);
	return bands;
}

void renameBandForRef(struct banda **bands,int sizeBands){
	int position;
	printf("digite a posição do rank a ser alterada 1-%d\n",sizeBands);
	scanf("%d",&position);
	printf("digite o novo nome da banda\n");
	scanf("%s[^\n]",bands[position-1]->nome);
}

//---------------------------------------------------/

//----------Funções de Busca ------------------------/
void busca_nome(char *name, struct banda *bands, int size){
	int found = 0,i;
	for(i=0;i<size;i++){
		if(strcmp(name,bands[i].nome)==0){
			found++;
			showSingleBand(&bands[i]);
		}
	}
	if(found == 0)
			printf("Nenhuma banda encontrada\n");
}

void busca_genero(int genre, struct banda *bands, int size){
	int found = 0,i;
	for(i=0;i<size;i++){
		if(genre == (int)bands[i].genero){
			found++;
			showSingleBand(&bands[i]);
		}
	}
	if(found == 0)
			printf("Nenhuma banda desse genero encontrada\n");
}
//---------------------------------------------------/

//-----funções de impressão------------------------//
void showBands(struct banda *bands, int size){
	int i;
	for(i=0;i<size;i++){
		printf("-------BANDA %d------\n",i);
		showSingleBand(&bands[i]);
		printf("---------------------\n");
	}	
}
void showSingleBand(struct banda *band){
		printf("\n-----BAND------\n");
		printf("--Name: %s\n",band->nome);
		printf("--Members: %d\n",band->integrantes);
		decrip(band);
		printf("\n---------------\n");
}
void decrip(struct banda *band){
	int genre = (int) band->genero;
	switch(genre){
		case 1:
				printf("--Style: rock\n");
				break;
		case 2:
				printf("--Style: salsa\n");
				break;
		case 3:
				printf("--Style: samba\n");
				break;
		case 4:
				printf("--Style: reggae\n");
				break;
		case 5:
				printf("--Style: pagode\n");
				break;
		case 6:
				printf("--Style: heavy_metal\n");
				break;
	}
}
void showRank(struct banda *bands, int size){
	int i;
	for(i=0;i<size;i++){
		printf("-------POSICAO %d------\n",i);
		showSingleBand(&bands[i]);
		printf("---------------------\n");
	}
}
//---------------------------------------------------/




