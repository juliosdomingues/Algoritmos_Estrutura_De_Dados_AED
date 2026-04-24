#include <stdio.h>
#include <stdlib.h>


typedef struct arv{
	struct arv *esq,*dir, *pai;
	int dado; //informação valida (chave)
	int rotacao; //indice ou fator de balanceamento, quando em 2 temos problema 
}Arv;

typedef struct desc_avl{
	struct arv *raiz;
	int altura;
}descritorAvl;


descritorAvl *Cria();
Arv *Busca(Arv *no,int valor);
Arv *Balanceamento(Arv *no);
void Insere(Arv **no,int valor, Arv *pai);
void Imprime_preorder(Arv *no);
void Imprime_inorder(Arv *no);
void Imprime_posorder(Arv *no);
int Maior(int a, int b);
int Altura(Arv *no);
