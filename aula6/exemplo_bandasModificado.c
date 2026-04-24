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
void showSingleBand(struct banda band);
void decrip(struct banda band);
void busca_nome(char *name, struct banda *bands, int size);
void busca_genero(int genre, struct banda *bands, int size);

//int insertBands(struct banda **ptrBands);   //alocado em uma função e retornado o ponteiro
int insertBands(struct banda *ptrBands, int sizeBands); //alocado no main antes da função

struct banda * renameBand(struct banda *bands,int sizeBands);
void renameBandForRef(struct banda *bands,int sizeBands);

void mudaIntegrantes(struct banda *bands, int size, char *nome, int novoIntegrantes);


int main(){

	int option=1;
	int sizeBands=0;
	struct banda *bands=NULL;
	//struct banda *bands;

	char nome[30];
	int novoIntegrantes;

	while(option > 0){
		printf("QUANTIDADE DE BANDAS %d\n",sizeBands);
		printf("Escolha uma opção: \n0-Sair \n1-bandas \n2-busca nome \n3-busca genero\n4-rank \n5-insere \n6-altera rank\n");
		setbuf(stdin,NULL);
		scanf("%d",&option);
		switch(option){
			case  1: showBands(bands,sizeBands);
					break;
			case 2:
					printf("digite o nome da banda a ser buscado\n");
					char band[20];
					setbuf(stdin,NULL);
					scanf("%[^\n]s",band);
					busca_nome(band,bands,sizeBands);
					break;
			case 3:
					printf("digite o estilo da banda a ser buscado\n");
					printf("--Style:rock=1,salsa=2,samba=3,reggae=4,pagode=5,heavy_metal=6\n");
					int genr;
					setbuf(stdin,NULL);
					scanf("%d",&genr);
					printf("-----BANDAS COM O ESTILO:--------\n");
					busca_genero(genr,bands,sizeBands);
					printf("---------------------------------\n");
					break;
			case 4: showRank(bands,sizeBands);
					break;
			case 5: 
					
					//utilizando a versão com ponteiro simples
					printf("digite o numero de bandas do rank\n");
					setbuf(stdin,NULL);
					scanf("%d",&sizeBands);
					//struct banda *bands = NULL;
					bands = (struct banda *)malloc(sizeof(struct banda)*sizeBands);
					sizeBands = insertBands(bands, sizeBands);
					
					//versão com ponteiro de ponteiro
					/*
					sizeBands = insertBands(&bands);
					*/
					if(bands == NULL)
						printf("não inseriu informações\n");
					//showSingleBand(bands[sizeBands-1]);
					break;
			case 6: //bands = renameBand(bands,sizeBands);
					renameBandForRef(bands,sizeBands);
					break;
			case 7:
					
					printf("digite o nome da banda a ser buscada\n");
					setbuf(stdin, NULL);
					scanf("%[^\n]s", nome);
					printf("digite o novo numero de integrantes\n");
					setbuf(stdin, NULL);
					scanf("%d", &novoIntegrantes);
					mudaIntegrantes(bands, sizeBands, nome, novoIntegrantes);
					break;
			default:
					printf("\nDigite algo entre 1-6 ou 0 para Sair\n");
		}
	}

	return 0;
}


//---------------FUNCAO DE INSERCAO--------------------/
//int insertBands(struct banda **ptrBands){
int insertBands(struct banda *ptrBands, int sizeBands){
	/*int sizeBands,i;
	printf("digite o numero de bandas do rank\n");
	setbuf(stdin,NULL);
	scanf("%d",&sizeBands);
	struct banda *bands = NULL;
	bands = (struct banda *)malloc(sizeof(struct banda)*sizeBands);
	if(bands != NULL){
	  for(i=0;i<sizeBands;i++){
		printf("\n-----BANDA------\n");
		printf("--Name:\n");
		setbuf(stdin,NULL);
		scanf("%[^\n]s",bands[i].nome);
		printf("--Members:\n");
		setbuf(stdin,NULL);
		scanf("%d",&bands[i].integrantes);
		printf("--Style:rock=1,salsa=2,samba=3,reggae=4,pagode=5,heavy_metal=6\n");
		int style;
		setbuf(stdin,NULL);
		scanf("%d",&style);
		bands[i].genero = style;
		printf("\n---------------\n");
	  }
	  *ptrBands = bands;  
	  }
	  */
	  
	  
	 //ponteiro já alocado
	 
	 int i;
	 if(ptrBands != NULL){
	  for(i=0;i<sizeBands;i++){
		printf("\n-----BANDA------\n");
		printf("--Name:\n");
		getchar();
		setbuf(stdin,NULL);
		scanf("%[^\n]s",ptrBands[i].nome);
		printf("--Members:\n");
		setbuf(stdin,NULL);
		scanf("%d",&ptrBands[i].integrantes);
		printf("--Style:rock=1,salsa=2,samba=3,reggae=4,pagode=5,heavy_metal=6\n");
		int style;
		setbuf(stdin,NULL);
		scanf("%d",&style);
		ptrBands[i].genero = style;
		printf("\n---------------\n");
	   }
	 }
	 else
		exit(-1);
	return sizeBands;
}

struct banda * renameBand(struct banda *bands,int sizeBands){
	int position;
	printf("digite a posição do rank a ser alterada 1-%d\n",sizeBands);
	setbuf(stdin,NULL);
	scanf("%d",&position);
	printf("digite o novo nome da banda\n");
	setbuf(stdin,NULL);
	scanf("%[^\n]s",bands[position-1].nome);
	return bands;
}

void renameBandForRef(struct banda *bands,int sizeBands){
	int position;
	printf("digite a posição do rank a ser alterada 1-%d\n",sizeBands);
	setbuf(stdin,NULL);
	scanf("%d",&position);
	printf("digite o novo nome da banda\n");
	setbuf(stdin,NULL);
	scanf("%[^\n]s",bands[position-1].nome);
}

//---------------------------------------------------/

//----------Funções de Busca ------------------------/
void busca_nome(char *name, struct banda *bands, int size){
	int found = 0,i;
	for(i=0;i<size;i++){
		int x = strcmp(name,bands[i].nome);
		if(x==0){
			found++;
			showSingleBand(bands[i]);
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
			showSingleBand(bands[i]);
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
		showSingleBand(bands[i]);
		printf("---------------------\n");
	}
	getchar();
}
void showSingleBand(struct banda band){
		printf("\n-----BAND------\n");
		printf("--Name: %s\n",band.nome);
		printf("--Members: %d\n",band.integrantes);
		decrip(band);
		printf("\n---------------\n");
}
void decrip(struct banda band){
	int genre = (int) band.genero;
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
		showSingleBand(bands[i]);
		printf("---------------------\n");
	}
}
//---------------------------------------------------/


void mudaIntegrantes(struct banda *bands, int size, char *nome, int novoIntegrantes){

	int found = 0,i;
	for(i=0;i<size;i++){
		if(strcmp(nome,bands[i].nome)==0){
			found++;
			
			showSingleBand(bands[i]);
			bands[i].integrantes = novoIntegrantes;
			showSingleBand(bands[i]);
			
		}
	}
	if(found == 0)
			printf("Nenhuma banda encontrada\n");

}



