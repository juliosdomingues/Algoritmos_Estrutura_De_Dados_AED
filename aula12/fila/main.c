#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

int main(){
	
	struct desc_queue *minhaQueue = criaDescQueue();
	struct nodofila* novoNodo = criaNodoQueue(3);
	enqueue(minhaQueue,novoNodo);
	showQueue(minhaQueue);
	printf("heado da fila eh [%d]\n",head(minhaQueue)->info);
	novoNodo = criaNodoQueue(4);
	enqueue(minhaQueue,novoNodo);
	showQueue(minhaQueue);
	printf("heado da fila eh [%d]\n",head(minhaQueue)->info);
	novoNodo = criaNodoQueue(2);
	enqueue(minhaQueue,novoNodo);
	showQueue(minhaQueue);
	printf("heado da fila eh [%d]\n",head(minhaQueue)->info);
	novoNodo = criaNodoQueue(1);
	enqueue(minhaQueue,novoNodo);
	showQueue(minhaQueue);
	printf("heado da fila eh [%d]\n",head(minhaQueue)->info);
	novoNodo = criaNodoQueue(10);
	enqueue(minhaQueue,novoNodo);
	showQueue(minhaQueue);
	printf("heado da fila eh [%d]\n",head(minhaQueue)->info);
	novoNodo = criaNodoQueue(99);
	enqueue(minhaQueue,novoNodo);
	showQueue(minhaQueue);
	printf("heado da fila eh [%d]\n",head(minhaQueue)->info);
	printf("o tamanho da fila eh [%d]\n",length(minhaQueue));
	dequeue(minhaQueue);
	showQueue(minhaQueue);
	makeNull(minhaQueue);
	showQueue(minhaQueue);
	return 0;
}

