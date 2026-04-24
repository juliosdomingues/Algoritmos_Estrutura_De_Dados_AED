#include <stdio.h>
#include <stdlib.h>
#include "listaEncadeada.h"

int main(){
	
	char op='z';
	int posicao,chaveNova;
	struct nodo *novoNodo;
	struct desc_lista_duplamente_encadeada *minhaNovaLista;
	do{
		setbuf(stdin,NULL);
		setbuf(stdin,NULL);
		printf("\nescolha a opcao: [c]-cria [i]insere [d]remove [l]libera [p]imprime [s]sair\n");
		scanf("%c",&op);
		setbuf(stdin,NULL);
		switch(op){		
		case 'c':
					minhaNovaLista = criaDescritor();
					break;
		case 'i':	
					printf("digite o valor do novo nodo\n");
					setbuf(stdin,NULL);
					scanf("%d",&chaveNova);
					novoNodo = criaNodo(chaveNova);
					printf("digite a posicao do novo nodo\n");
					setbuf(stdin,NULL);
					scanf("%d",&posicao);
					insere(minhaNovaLista,novoNodo,posicao);
					break;
		case 'p':
					imprime(minhaNovaLista);
					break;
		case 'r':
					printf("digite a posicao da remocao\n");
					setbuf(stdin,NULL);
					scanf("%d",&posicao);
					removeLista(minhaNovaLista,posicao);
					break;
		case 'l':
					libera(minhaNovaLista);
					break;
		}
	}while(op != 's');
	return 0;
}
