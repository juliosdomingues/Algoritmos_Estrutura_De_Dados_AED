#include "goro.h"

int main(void){
	struct desc_lista *minhaLista = iniciaDesc();

	struct goro *novoGoro = iniciaGoro("breja",24,10);
	struct no *novoNo = iniciaNo(novoGoro);
	minhaLista = insereGoro(minhaLista,novoNo,10);

	printf("#######LISTA BAR##############\n");
	printaLista(minhaLista);
	printf("##############################\n");

	struct goro *novoGoro2 = iniciaGoro("breja2",24,10);
	struct no *novoNo2 = iniciaNo(novoGoro2);
	minhaLista = insereGoro(minhaLista,novoNo2,100);

	printf("#######LISTA BAR##############\n");
	printaLista(minhaLista);
	printf("##############################\n");

	struct goro *novoGoro3 = iniciaGoro("breja3",24,10);
	struct no *novoNo3 = iniciaNo(novoGoro3);
	minhaLista = insereGoro(minhaLista,novoNo3,2);

	printf("#######LISTA BAR##############\n");
	printaLista(minhaLista);
	printf("##############################\n");

	struct goro *novoGoro4 = iniciaGoro("breja4",24,10);
	struct no *novoNo4 = iniciaNo(novoGoro4);
	minhaLista = insereGoro(minhaLista,novoNo4,1);
	
	printf("#######LISTA BAR##############\n");
	printaLista(minhaLista);
	printf("##############################\n");
	return 0;
}
