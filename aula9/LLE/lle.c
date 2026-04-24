#include <stdlib.h>
#include <stdio.h>
#include "lle.h"

//inicializa um descritor da lista
TipoLista* initializeLLE(void){
	TipoLista* lista = (TipoLista*)malloc(sizeof(TipoLista));
	lista->Primeiro=NULL;
	lista->Ultimo=NULL;
	lista->tamanho=0;
	return lista;
}


//faz a lista vazia
void makeNUllLLE (TipoLista* Lista){
	TipoItem *aux = Lista->Primeiro;
	TipoItem *ant;
	while(aux->Prox !=NULL){
		ant = aux;
		aux = aux->Prox;
		free(ant);
	}
	Lista->tamanho=0;
	Lista->Ultimo =Lista->Primeiro = NULL; 
}

//insere um elemento de valor x na posição anterior a p
void insertLLE( TipoLista* Lista, TipoItem* x, Posicao p){ 
	if(Lista->Primeiro ==NULL){ //inserção no inicio 
		Lista->Primeiro = x;
		Lista->Ultimo = Lista->Primeiro;
		printf ("Elemento %d inserido no inicio da lista\n",x->valor);
		Lista->tamanho++;
	}
	else{
		 if(p > Lista->tamanho){
			printf("posição inexistente\n");
			return;
		}
		else{			
			int i=0;
			if(p==0){
				x->Prox=Lista->Primeiro; 
				Lista->Primeiro =x;
				Lista->tamanho++;
			}
			else{
				TipoItem *aux = Lista->Primeiro;
				while(i < p){
					aux= aux->Prox;
					i++;
				}
				aux->Prox = x;
				if(p==Lista->tamanho)
					Lista->Ultimo = x;
				printf ("Elemento [%d] inserido na posicao %d da lista\n",x->valor,p);
				Lista->tamanho++;
			}
		}
	}
}

//retorna o número de elementos armazenados na lista
int lengthLLE(TipoLista* Lista){
 return Lista->tamanho;
}

//busca um elemento na posição anterior a p
TipoItem* getLLE(TipoLista* Lista, Posicao p){
		 if(p > Lista->tamanho) {
			printf("Posicao Invalida\n");
			return NULL;
		}
		else{			
			int i=0;
			TipoItem *aux = Lista->Primeiro;
			while(i < p){
			    aux= aux->Prox;
			    i++;
			}
			return aux;
		}
		return NULL;
} 


//modifica um elemento de valor x na posição anterior a p
void setLLE(TipoLista* Lista, int novoValor, Posicao p){
	TipoItem *item = getLLE(Lista,p);
	modifyTipoItem(item,novoValor);
	printf ("Set Elemento [%d] inserido na posicao %d da lista\n",item->valor,p);
}

//apaga o elemento de posição p			
TipoItem* deleteLLE(TipoLista* Lista, Posicao p){
	if (((lengthLLE(Lista)) ==0)||(p >= Lista->tamanho)){
		printf ("A posição não existe!\n");
		return NULL;
	}
	int i=0;
	TipoItem *aux = Lista->Primeiro;
	TipoItem *ant;
	while(i < p){
		ant=aux;
	    aux= aux->Prox;
	    i++;
	}
	ant->Prox = aux->Prox;
	Lista->tamanho--;
	return aux;
}


//imprime a lista
void showLLE(TipoLista* Lista){
	printf ("Imprime Lista Encadeada: ");
	TipoItem* aux = Lista->Primeiro;
	while(aux != NULL){
			showTipoItem(aux);
			aux=aux->Prox;
	}
	printf("\n");
}

//cria um novo item com o valor
TipoItem* createTipoItem(int valor){
	TipoItem* item = (TipoItem*)malloc(sizeof(TipoItem));
	item->valor = valor;
	item->Prox=NULL;
	printf("Novo item %d\n",item->valor);
	return item;
}

//altera o campo valor para o novoValor
void modifyTipoItem(TipoItem* x, int novoValor){
	x->valor = novoValor;
}

//imprime o campo valor do Item
void showTipoItem(TipoItem *x){
	printf (" [%d]", x->valor);
}
