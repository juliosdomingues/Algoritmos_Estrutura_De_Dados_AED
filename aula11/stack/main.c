#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main(){
	
	struct desc_stack *minhaStack = criaDescStack();
	struct nodopilha* novoNodo = criaNodoStack(3);
	push(minhaStack,novoNodo);
	showStack(minhaStack);
	printf("topo da pilha eh [%d]\n",top(minhaStack)->info);
	novoNodo = criaNodoStack(4);
	push(minhaStack,novoNodo);
	showStack(minhaStack);
	printf("topo da pilha eh [%d]\n",top(minhaStack)->info);
	novoNodo = criaNodoStack(2);
	push(minhaStack,novoNodo);
	showStack(minhaStack);
	printf("topo da pilha eh [%d]\n",top(minhaStack)->info);
	novoNodo = criaNodoStack(1);
	push(minhaStack,novoNodo);
	showStack(minhaStack);
	printf("topo da pilha eh [%d]\n",top(minhaStack)->info);
	novoNodo = criaNodoStack(10);
	push(minhaStack,novoNodo);
	showStack(minhaStack);
	printf("topo da pilha eh [%d]\n",top(minhaStack)->info);
	novoNodo = criaNodoStack(99);
	push(minhaStack,novoNodo);
	showStack(minhaStack);
	printf("topo da pilha eh [%d]\n",top(minhaStack)->info);
	printf("o tamanho da pilha eh [%d]\n",length(minhaStack));
	struct nodopilha *aux = pop(minhaStack);
	printf("topo da pilha eh [%d]\n",top(minhaStack)->info);
	showStack(minhaStack);
	makeNull(minhaStack);
	showStack(minhaStack);
	return 0;
}
