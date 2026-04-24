#include <stdlib.h>
#include <stdio.h>
#include "lle.h"

int main(){
	
	TipoLista* minhaLista = initializeLLE();
	printf("tamanho da lista %d \n",lengthLLE(minhaLista));
	TipoItem *novoItem = createTipoItem(4);
	insertLLE(minhaLista,novoItem,0);
	showLLE(minhaLista);
	printf("tamanho da lista %d \n",lengthLLE(minhaLista));
	novoItem = createTipoItem(2);
	insertLLE(minhaLista,novoItem,0);
	showLLE(minhaLista);
	printf("tamanho da lista %d \n",lengthLLE(minhaLista));
	novoItem = createTipoItem(1);
	insertLLE(minhaLista,novoItem,0);
	showLLE(minhaLista);
	novoItem = createTipoItem(7);
	showLLE(minhaLista);
	insertLLE(minhaLista,novoItem,0);
	setLLE(minhaLista,20,0);
	showLLE(minhaLista);
	deleteLLE(minhaLista,1);
	showLLE(minhaLista);
	deleteLLE(minhaLista,3);
	showLLE(minhaLista);
	deleteLLE(minhaLista,2);
	showLLE(minhaLista);
	return 0;
}
