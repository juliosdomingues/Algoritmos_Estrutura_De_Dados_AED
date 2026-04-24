
#include <stdio.h>
#include <stdlib.h>
struct goro{
	char nome[20];
	int quant;
	float preco;
};

struct no{
	struct goro *mgoro;
	struct no *proximo;
};

struct desc_lista{
	int tam;
	struct no *primeiro;
};


struct desc_lista * iniciaDesc(void);
struct no * iniciaNo(struct goro *meuGoro);
struct goro * iniciaGoro(char *nome, int quant, float preco);

void printaNo(struct no *noAtual);
void printGoro(struct goro *meuGoro);
void printaLista(struct desc_lista *minhaLista);

struct desc_lista* insereGoro(struct desc_lista *minhaLista, struct no *novoNo, int posicao);


