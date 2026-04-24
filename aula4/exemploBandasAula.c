#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum genero{rock=1,samba,pop,reggae,metal,funk};

struct banda{
	char nome[25];
	enum genero tipo;
	int integrantes;
	int ranking;
};

//retorno por cópia
struct banda * inserirBandas(int quantidadeBandas);

void inserirBandasPonteiroPonteiro(struct banda **minhasBandas, int quantidadeBandas);

void inserirBandasVoid(struct banda *minhasBandas, int quantidadeBandas);


void buscaGenero(struct banda *minhasBandas, int quantidadeBandas, int generoDigitado);

void buscaNome(struct banda *minhasBandas, int quantidadeBandas, char *nome);

void imprimeBandas(struct banda *minhasBandas, int quantidadeBandas);
void imprimeUmaBanda(struct banda umaBanda);


int main(void){
	
	//variavel das bandas
	struct banda *minhasBandas = NULL; 
	int quantidadeBandas;
	int generoDigitado;
	char nome[25];
	
	
	int opcao=-1;
	
	printf("digite a quantidade de bandas\n");
	setbuf(stdin,NULL); //limpa o buffer da entrada
	scanf("%d", &quantidadeBandas);
	
	while(opcao!=0){
		printf( "========MENU========\n");
		//printf( "1:inserir bandas\n 2:imprimir bandas\n 3:procurar genero\n 4:procurar nome\n 0:sair\n");
		printf( "1:inserir bandas\n 2:imprimir bandas\n 3:procurar genero\n 4:procurar nome\n 5:inserirPP\n 6:inserirVoid\n 0:sair\n");

		setbuf(stdin,NULL); //limpa o buffer da entrada
		scanf("%d", &opcao);

		switch(opcao){
			case 0:
					return 0;
			case 1: //inserir bandas
					minhasBandas = inserirBandas(quantidadeBandas);
					break;
			case 2: //imprimir bandas
					imprimeBandas(minhasBandas, quantidadeBandas);
			
					break;
			case 3:
					printf("digite o genero da banda que quer bucar [rock=1,samba=2,pop=3,reggae=4,metal=5,funk=6]\n");
					setbuf(stdin, NULL);
					scanf("%d", &generoDigitado);
					buscaGenero(minhasBandas, quantidadeBandas, generoDigitado);
					break;
			case 4:
					printf("digite o nome da banda\n");
					setbuf(stdin,NULL);
					scanf("%[^\n]s", nome);
					buscaNome(minhasBandas, quantidadeBandas, nome);
					break;
			case 5: //inserir bandas
					inserirBandasPonteiroPonteiro(&minhasBandas, quantidadeBandas);
					break;
			case 6: //inserir bandas void
					inserirBandasVoid(minhasBandas, quantidadeBandas);
					break;
			default:
					printf("opcao invalida\n");
					break;
					
		}
	}
	return 0;
}

//inserir bandas com cópia no retorno
struct banda * inserirBandas(int quantidadeBandas){

	//aloca bandas
	struct banda * minhasBandas = (struct banda *)malloc(quantidadeBandas * sizeof(struct banda));
	
	int  i;
	for(i=0;i<quantidadeBandas;i++){
		setbuf(stdin,NULL);
		printf("digite o nome da banda\n");
		scanf("%[^\n]s", minhasBandas[i].nome);
		printf("digite o numero de integrantes da banda\n");
		setbuf(stdin,NULL);
		scanf("%d", &minhasBandas[i].integrantes);
		printf("digite o genero da banda [rock=1,samba=2,pop=3,reggae=4,metal=5,funk=6]\n");
		int tipoDigitado;
		setbuf(stdin,NULL);		
		scanf("%d",&tipoDigitado);
		minhasBandas[i].tipo = tipoDigitado;
		printf("digite o numero ranking da banda [1:5]\n");
		scanf("%d", &minhasBandas[i].ranking);
	}	
	return minhasBandas;
}

//inserir bandas com ponteiro mas acaba passando por cópia
void inserirBandasVoid(struct banda *minhasBandas, int quantidadeBandas){
	//aloca bandas
	minhasBandas = (struct banda *)malloc(quantidadeBandas * sizeof(struct banda));
	
	int  i;
	for(i=0;i<quantidadeBandas;i++){
		setbuf(stdin,NULL);
		printf("digite o nome da banda\n");
		scanf("%[^\n]s", minhasBandas[i].nome);
		printf("digite o numero de integrantes da banda\n");
		setbuf(stdin,NULL);
		scanf("%d", &minhasBandas[i].integrantes);
		printf("digite o genero da banda [rock=1,samba=2,pop=3,reggae=4,metal=5,funk=6]\n");
		int tipoDigitado;
		setbuf(stdin,NULL);		
		scanf("%d",&tipoDigitado);
		minhasBandas[i].tipo = tipoDigitado;
		printf("digite o numero ranking da banda [1:5]\n");
		scanf("%d", &minhasBandas[i].ranking);
	}	
	//return minhasBandas;
}

//inserir ponteiro do ponteiro de bandas (mexe na alocação original)
void inserirBandasPonteiroPonteiro(struct banda **minhasBandas, int quantidadeBandas){
	//aloca bandas
	struct banda *bandas = (struct banda *)malloc(quantidadeBandas * sizeof(struct banda));
	
	int  i;
	for(i=0;i<quantidadeBandas;i++){
		setbuf(stdin,NULL);
		printf("digite o nome da banda\n");
		scanf("%[^\n]s", bandas[i].nome);
		printf("digite o numero de integrantes da banda\n");
		setbuf(stdin,NULL);
		scanf("%d", &bandas[i].integrantes);
		printf("digite o genero da banda [rock=1,samba=2,pop=3,reggae=4,metal=5,funk=6]\n");
		int tipoDigitado;
		setbuf(stdin,NULL);		
		scanf("%d",&tipoDigitado);
		bandas[i].tipo = tipoDigitado;
		printf("digite o numero ranking da banda [1:5]\n");
		scanf("%d", &bandas[i].ranking);
	}	
	*minhasBandas = bandas;
}


//imprimir bandas
void imprimeBandas(struct banda *minhasBandas, int quantidadeBandas){
	
	int  i;
	for(i=0;i<quantidadeBandas;i++){
		imprimeUmaBanda(minhasBandas[i]);
	}	
}

//busca nome
void buscaNome(struct banda *minhasBandas, int quantidadeBandas, char *nome){
		int  i;
	for(i=0;i<quantidadeBandas;i++){
		
		if(strcmp(nome,minhasBandas[i].nome) == 0){
				imprimeUmaBanda(minhasBandas[i]);
			}
	}	

}


//busca genero
void buscaGenero(struct banda *minhasBandas, int quantidadeBandas, int generoDigitado){
	
	int  i;
	for(i=0;i<quantidadeBandas;i++){
		
		if(generoDigitado == minhasBandas[i].tipo){
				imprimeUmaBanda(minhasBandas[i]);
			}
	}	
}

void imprimeUmaBanda(struct banda umaBanda){
			printf("NOME: %s\n",umaBanda.nome);
			printf("INTEGRANTES: %d\n",umaBanda.integrantes);
			printf("GENERO: ");
			switch(umaBanda.tipo){
				case 1:
					printf("Rock\n");
					break;
				case 2:
					printf("SAMBA\n");
					break;
				case 3:
					printf("Reggae\n");
					break;
				case 4:
					printf("Pop\n");
					break;
				case 5:
					printf("Metal\n");
					break;
				case 6:
					printf("Funk\n");
					break;
				}
				printf("RANKING: %d\n",umaBanda.ranking);	
}













