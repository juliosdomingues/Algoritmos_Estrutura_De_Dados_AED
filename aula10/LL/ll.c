#include <stdlib.h>
#include <stdio.h>
#include "ll.h"

//inicializa um descritor da lista
TipoLista* initializeLL(void){
	TipoLista* lista = (TipoLista*)malloc(sizeof(TipoLista));
	return lista;
}


//faz a lista vazia
void makeNUllLL (TipoLista* Lista){
	Lista->Ultimo =Lista->Primeiro = InicioVetor; 
}

//insere um elemento de valor x na posição anterior a p
void insertLL( TipoLista* Lista, TipoItem* x, Posicao p){ 
	if (Lista->Ultimo >= MaxTam)//lista cheia
		printf ("Lista está cheia\n");
	else{
		if(Lista->Ultimo < p){ //inserção no final 
			Lista->Item[Lista->Ultimo] = *x;
			printf ("Elemento inserido no final da lista\n");
		}
		else{ //inserção no meio
			int i;
			for(i=Lista->Ultimo;i>p;i--)
				Lista->Item[i]=Lista->Item[i-1];
			Lista->Item[p] = *x;
			printf ("Elemento [%d] inserido na posicao %d da lista\n",Lista->Item[p].valor,p);
		}
		Lista->Ultimo++;
	}
}

//retorna o número de elementos armazenados na lista
int lengthLL(TipoLista* Lista){
 return Lista->Ultimo;
}

//busca um elemento na posição anterior a p
TipoItem* getLL(TipoLista* Lista, Posicao p){
	return &Lista->Item[p];
} 


//modifica um elemento de valor x na posição anterior a p
void setLL(TipoLista* Lista, int novoValor,  Posicao p){
	TipoItem *item = getLL(Lista,p);
	modifyTipoItem(item,novoValor);
	printf ("Set Elemento [%d] inserido na posicao %d da lista\n",Lista->Item[p].valor,p);
}

//apaga o elemento de posição p			
TipoItem* deleteLL(TipoLista* Lista, Posicao p){
	int Aux; 
	TipoItem* item;
	item = (TipoItem*) malloc(sizeof(TipoItem));
	if ((lengthLL(Lista) ==0)||(p >= Lista->Ultimo)){
		printf ("A posição não existe!\n");
		return NULL;
	}
	*item = Lista->Item[p]; 
	for (Aux = p; Aux < Lista->Ultimo; Aux++)
		Lista->Item[Aux] = Lista->Item[Aux+1];
	Lista->Ultimo--;
	return item;
}


//imprime a lista
void showLL(TipoLista* Lista){
	int Aux;
  	printf ("Imprime Lista Estatica: ");
	for(Aux=Lista->Primeiro;Aux < Lista->Ultimo;Aux++){
			showTipoItem(Lista->Item[Aux]);
	}
	printf("\n");
}

//cria um novo item com o valor
TipoItem* createTipoItem(int valor){
	TipoItem* item = (TipoItem*)malloc(sizeof(TipoItem));
	item->valor = valor;
	return item;
}

//altera o campo valor para o novoValor
void modifyTipoItem(TipoItem* x, int novoValor){
	x->valor = novoValor;
}

//imprime o campo valor do Item
void showTipoItem(TipoItem x){
	printf (" [%d]", x.valor);
}

