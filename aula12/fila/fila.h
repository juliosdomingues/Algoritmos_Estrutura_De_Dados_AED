#include <stdlib.h>
#include <stdio.h>

struct nodofila{
	int info;
	struct nodofila *prox;
};

struct desc_queue{
	struct nodofila *head;
	struct nodofila *tail;
	int tamanho;
};

struct desc_queue *criaDescQueue(void);
struct nodofila* criaNodoQueue(int info);
void enqueue(struct desc_queue *queue,struct nodofila*novoElemento);
struct nodofila* dequeue(struct desc_queue *queue);
int empty(struct desc_queue *queue);
int length(struct desc_queue *queue);
void makeNull(struct desc_queue *queue);
struct nodofila* head(struct desc_queue *queue);
void showQueue(struct desc_queue *queue);

