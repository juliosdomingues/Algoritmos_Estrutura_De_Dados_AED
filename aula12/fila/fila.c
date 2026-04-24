#include "fila.h"

struct desc_queue *criaDescQueue(void){
	struct desc_queue *queue = (struct desc_queue*)malloc(sizeof(struct desc_queue));
	queue->head = NULL;
	queue->tail = NULL;
	queue->tamanho=0;
	return queue;
}

struct nodofila* criaNodoQueue(int info){
	struct nodofila * novo = (struct nodofila*)malloc(sizeof(struct nodofila));
	novo->info = info;
	novo->prox = NULL;
	return novo;
}

void enqueue(struct desc_queue *queue,struct nodofila*novoElemento){
	if(empty(queue) == 1){
		queue->head = novoElemento;
		queue->tail = novoElemento;
	}
	else{
		queue->tail->prox = novoElemento;
		queue->tail = novoElemento;
	}
	queue->tamanho++;
}

/**@author =  juliosaracol**/
struct nodofila* dequeue(struct desc_queue *queue){
	struct nodofila *aux = queue->head;
	queue->head=queue->head->prox;
	queue->tamanho--;
	if(queue->head == NULL)
		queue->tail=queue->head;
	return aux;
}

int empty(struct desc_queue *queue){
	if(queue->head ==NULL)
		return 1;
		else
		return 0;
}

int length(struct desc_queue *queue){
	return queue->tamanho;
}

void makeNull(struct desc_queue *queue){
		while(empty(queue) == 0){
			free(dequeue(queue));
		}
}

struct nodofila* head(struct desc_queue *queue){
	return queue->head;
}

void showQueue(struct desc_queue *queue){
	struct nodofila* topo = head(queue);
	while(topo !=NULL){
		printf("[ %d ] ",topo->info);
		topo = topo->prox;
	}
	printf("\n");
}





