
#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

struct descritor_arvore* inicializa(void){
 struct descritor_arvore *myTree;
 myTree = (struct descritor_arvore *)malloc(sizeof(struct descritor_arvore));
 myTree->tamanho = 0;
 myTree->raiz = NULL;
 return myTree;	
}

struct nodo* criaNodo(int chave){
	struct nodo* novoNodo;
	novoNodo = (struct nodo *) malloc(sizeof(struct nodo));
	novoNodo->chave = chave;
	novoNodo->esquerdo=NULL;
	novoNodo->direito=NULL;
	novoNodo->pai=NULL;	
}

struct nodo* insereNodo(struct nodo* atual, struct nodo* novoNodo){
	if(atual == NULL){
		return novoNodo;
	}
	if(novoNodo->chave  > atual->chave)
		atual->direito = insereNodo(atual->direito,novoNodo);
	else
		atual->esquerdo = insereNodo(atual->esquerdo,novoNodo);
	return atual;	
}

