#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int main(){
	
struct descritor_arvore* tree;
tree = inicializa();
struct nodo *novo = criaNodo(5);
tree->raiz = insereNodo(tree->raiz,novo,tree->raiz);
printf("raiz com valor %d\n", tree->raiz->chave);
novo = criaNodo(7);
tree->raiz = insereNodo(tree->raiz,novo,tree->raiz);
novo = criaNodo(6);
tree->raiz = insereNodo(tree->raiz,novo,tree->raiz);
novo = criaNodo(9);
tree->raiz = insereNodo(tree->raiz,novo,tree->raiz);
getchar();	
return 0;	
}
