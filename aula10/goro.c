#include "goro.h"
#include <string.h>

//iniciar o descritor
struct desc_lista * iniciaDesc(void){
	struct desc_lista *novoDescritor = (struct desc_lista*) malloc(sizeof(struct desc_lista));
	novoDescritor->tam=0;
	novoDescritor->primeiro=NULL;
	return novoDescritor;
}

//iniciar o no
struct no * iniciaNo(struct goro *meuGoro){
	struct no *novoNo = (struct no*) malloc(sizeof(struct no));
	novoNo->mgoro = meuGoro;
	novoNo->proximo=NULL;
	return novoNo;
}


//iniciar o goro
struct goro * iniciaGoro(char *nome, int quant, float preco){
	struct goro *novogoro = (struct goro*) malloc(sizeof(struct goro));
	strcpy(novogoro->nome,nome);
	novogoro->quant = quant;
	novogoro->preco = preco;
	return novogoro;
}

void printaLista(struct desc_lista *minhaLista){
	struct no* aux = minhaLista->primeiro;
	while(aux != NULL){
		printaNo(aux);	
		aux = aux->proximo;
	}
}


void printaNo(struct no *noAtual){
	printGoro(noAtual->mgoro);	
}


void printGoro(struct goro *meuGoro){
	printf("nome: %s\n", meuGoro->nome);
	printf("quant: %d\n",meuGoro->quant);
	printf("preco: %f\n",meuGoro->preco);
}


struct desc_lista* insereGoro(struct desc_lista *minhaLista, struct no *novoNo, int posicao){
	
	if((minhaLista->tam == 0)&&(minhaLista->primeiro==NULL)){//inserir lista vazia
			minhaLista->primeiro = novoNo;
			minhaLista->tam++;
			return minhaLista;
	}
	else{
		if((minhaLista->tam > 0)&&(posicao == 1)){//inserir no inicio da lista
			novoNo->proximo = minhaLista->primeiro;
			minhaLista->primeiro = novoNo;
			minhaLista->tam++;
			return minhaLista;	
		}
		else{//inserir na posicao ou no final
			if(posicao < (minhaLista->tam)){//inserir no meio -- AQUI O ERRO
				struct no *aux = minhaLista->primeiro;
				struct no *ant = NULL;
				while((aux->proximo != NULL)&&(posicao > 0)){	
					ant = aux;
					aux = aux->proximo;
					posicao--;
				}
				novoNo->proximo = aux;
				ant->proximo = novoNo;
				minhaLista->tam++;
				return minhaLista;
			}
			else{//inserir no fim
				struct no *aux = minhaLista->primeiro;
				while(aux->proximo != NULL){	
					aux = aux->proximo;
				}
				aux->proximo = novoNo;
				minhaLista->tam++;
				return minhaLista;
			}
		 }

	}
}







