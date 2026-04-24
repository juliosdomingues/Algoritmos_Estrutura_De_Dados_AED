#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int main(){
	
struct descritor_arvore* tree;
tree = inicializa();
struct nodo *novo = criaNodo(5);
tree->raiz = insereNodo(tree->raiz,novo);
novo = criaNodo(6);
tree->raiz = insereNodo(tree->raiz,novo);
printf("raiz com valor %d\n", tree->raiz->chave);
getchar();	
return 0;	
}
