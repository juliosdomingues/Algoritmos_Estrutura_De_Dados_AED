#include <stdio.h>
#include <stdlib.h>
#include "listaEncadeada.h"
struct nodo* criaNodo(int novoDado){//cria novos nodos para a lista mas não inseri
	struct nodo *novoElemento = (struct nodo *)malloc(sizeof(struct nodo));
	if (novoElemento == NULL) return NULL;
	novoElemento->dado = novoDado;
	novoElemento->prox = NULL;
	novoElemento->ant = NULL;
	return novoElemento;
}
struct desc_lista_duplamente_encadeada * criaDescritor(void){//cria descritores de listas
	struct desc_lista_duplamente_encadeada *novoDescLista = (struct desc_lista_duplamente_encadeada *)malloc(sizeof(struct desc_lista_duplamente_encadeada));
	novoDescLista->tamanho = 0;
	novoDescLista->lista=NULL;
	novoDescLista->fimLista=NULL;
	return novoDescLista;
}

struct nodo* removeLista(struct desc_lista_duplamente_encadeada *minhaLista, int posicao){
	if(minhaLista == NULL || minhaLista->tamanho == 0 || posicao < 0 || posicao >= minhaLista->tamanho){
		return NULL;
	}

	struct nodo *removido = minhaLista->lista;
	if(posicao == 0){
		minhaLista->lista = removido->prox;
		if(minhaLista->lista != NULL){ // existe mais alguem na lista
			minhaLista->lista->ant = NULL;
		}
		if(minhaLista->lista == NULL)
			minhaLista->fimLista = NULL;
	} 
	else {
		int posicaoCont = 0;
		while(removido != NULL && posicaoCont < posicao){
			removido = removido->prox;
			posicaoCont++;
		}
		if(removido == NULL){
			return NULL;
		}
		if(removido->ant != NULL){
			removido->ant->prox = removido->prox;
		}
		if(removido->prox != NULL){
			removido->prox->ant = removido->ant;
		}
		if(removido == minhaLista->fimLista) // sinal que modifiquei o fim da lista
			minhaLista->fimLista = removido->ant;		
	}

	removido->prox = NULL;
	removido->ant = NULL;
	minhaLista->tamanho--;
	return removido;
}

void insere(struct desc_lista_duplamente_encadeada *minhaLista, struct nodo *novo_elemento, int posicao){
	if(minhaLista == NULL || novo_elemento == NULL){
		return;
	}

	if(minhaLista->lista == NULL || posicao <= 0){ //inserção lista vazia e posicao zero ou menos
		novo_elemento->prox = minhaLista->lista;
		if(minhaLista->lista != NULL){
			minhaLista->lista->ant = novo_elemento;
		}
		minhaLista->lista = novo_elemento;
		if(minhaLista->tamanho == 0)
			minhaLista->fimLista = novo_elemento;
		minhaLista->tamanho++;
		return;
	}

	if(posicao >= minhaLista->tamanho){//insere no final da lista (posicao invalida)
		struct nodo *aux = minhaLista->fimLista;
		aux->prox = novo_elemento;
		novo_elemento->ant = aux;
		minhaLista->tamanho++;
		minhaLista->fimLista = novo_elemento;
		return;
	}

	struct nodo *aux = minhaLista->lista;
	int listaPos = 0;
	while(listaPos < posicao){
		aux = aux->prox;
		listaPos++;
	}
	novo_elemento->prox = aux;
	novo_elemento->ant = aux->ant;
	aux->ant->prox = novo_elemento;
	aux->ant = novo_elemento;
	minhaLista->tamanho++;
}

int tamanho(struct desc_lista_duplamente_encadeada *minhaLista){
	return minhaLista->tamanho;
}

void libera(struct desc_lista_duplamente_encadeada *minhaLista){
	if(minhaLista == NULL) return;
	struct nodo *aux = minhaLista->lista;
	while(aux != NULL){
		struct nodo *proximo = aux->prox;
		free(aux);
		aux = proximo;
	}
	minhaLista->lista = NULL;
	minhaLista->fimLista=NULL;
	minhaLista->tamanho = 0;
}


void imprime(struct desc_lista_duplamente_encadeada *minhaLista){
	struct nodo* aux = minhaLista->lista;
	while(aux != NULL){
		printf("[%d] ", aux->dado);
		aux = aux->prox;
	}
	printf("\n");
}

struct nodo * get(struct desc_lista_duplamente_encadeada *minhaLista, int posicao){
	struct nodo* temp = minhaLista->lista;
	int posicaoAcessando=0;
	
	while(temp !=NULL){
		temp = temp->prox;
		posicaoAcessando++;
		if(posicao == posicaoAcessando){
			return temp;
		}	
	}
	
	
}

void set(struct desc_lista_duplamente_encadeada *minhaLista, int valor, int posicao){
	if(minhaLista == NULL || posicao < 0 || posicao >= minhaLista->tamanho){
		return;
	}
	struct nodo *aux = get(minhaLista, posicao);
	if(aux != NULL){
		aux->dado = valor;
	}
}
