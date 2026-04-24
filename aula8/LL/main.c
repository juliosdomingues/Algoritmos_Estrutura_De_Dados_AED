#include <stdlib.h>
#include <stdio.h>
#include "ll.h"

int main(){
	
	TipoLista* minhaLista = initializeLL();
	printf("tamanho da lista %d \n",lengthLL(minhaLista));
	TipoItem *novoItem = createTipoItem(4);
	insertLL(minhaLista,novoItem,0);
	showLL(minhaLista);
	printf("tamanho da lista %d \n",lengthLL(minhaLista));
	novoItem = createTipoItem(2);
	insertLL(minhaLista,novoItem,0);
	showLL(minhaLista);
	printf("tamanho da lista %d \n",lengthLL(minhaLista));
	novoItem = createTipoItem(1);
	insertLL(minhaLista,novoItem,0);
	showLL(minhaLista);
	novoItem = createTipoItem(7);
	insertLL(minhaLista,novoItem,0);
	showLL(minhaLista);
	setLL(minhaLista,20,0);
	showLL(minhaLista);
	deleteLL(minhaLista,1);
	showLL(minhaLista);
	deleteLL(minhaLista,3);
	showLL(minhaLista);
	deleteLL(minhaLista,2);
	showLL(minhaLista);
	return 0;
}
