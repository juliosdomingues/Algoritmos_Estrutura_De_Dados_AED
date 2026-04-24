#include <stdio.h>
#include <stdlib.h>

typedef struct arv {
    struct arv *esq, *dir, *pai;
    int dado;
    int rotacao;
} Arv;

typedef struct desc_avl {
    struct arv *raiz;
    int altura;
} descritorAvl;

Arv* novoNo(int dado) {
    Arv* no = (Arv*)malloc(sizeof(Arv));
    no->dado = dado;
    no->esq = no->dir = no->pai = NULL;
    no->rotacao = 0;
    return no;
}

int altura(Arv* no) {
    if (no == NULL) return -1;
    int alturaEsq = altura(no->esq);
    int alturaDir = altura(no->dir);
    return 1 + (alturaEsq > alturaDir ? alturaEsq : alturaDir);
}

void atualizaRotacao(Arv* no) {
    if (no) {
        int alturaEsq = altura(no->esq);
        int alturaDir = altura(no->dir);
        no->rotacao = alturaDir - alturaEsq;
    }
}

Arv* rotacaoEsquerda(Arv* x) {
	printf("*******rotação a direita\n");
    Arv* y = x->dir;
    x->dir = y->esq;
    if (y->esq) 
		y->esq->pai = x;
    y->esq = x;

    y->pai = x->pai;
    x->pai = y;

    atualizaRotacao(x);
    atualizaRotacao(y);

    return y;
}

Arv* rotacaoDireita(Arv* x) {
	printf("*******rotação a direita\n");
    Arv* y = x->esq;
    x->esq = y->dir;
    if (y->dir) 
		y->dir->pai = x;
    y->dir = x;

    y->pai = x->pai;
    x->pai = y;

    atualizaRotacao(x);
    atualizaRotacao(y);

    return y;
}

Arv* rotacaoDuplaEsquerda(Arv* x) {
	printf("*******rotação a DUPLA ESQUERDA\n");
    x->dir = rotacaoDireita(x->dir);
    return rotacaoEsquerda(x);
}

Arv* rotacaoDuplaDireita(Arv* x) {
	printf("*******rotação a DUPLA DIREITA\n");
    x->esq = rotacaoEsquerda(x->esq);
    return rotacaoDireita(x);
}

Arv* balancear(Arv* no) {
    atualizaRotacao(no);

    if(no->rotacao == -2){//rotação direita
       if (no->esq->rotacao <= 0){
           return rotacaoDireita(no);         
       }else
           return rotacaoDuplaDireita(no);    
    } 
    else{
		if(no->rotacao == 2){//rotação esquerda
			if (no->dir->rotacao >= 0)
				return rotacaoEsquerda(no);        
			else
				return rotacaoDuplaEsquerda(no);  
		}
	}
	return no;
}

Arv* inserirAVL(Arv* raiz, int dado, Arv* pai, int* cresceu) {
    if (raiz == NULL) {
        Arv* novo = novoNo(dado);
        novo->pai = pai;
        *cresceu = 1;
        return novo;
    }

    if (dado < raiz->dado) {
        raiz->esq = inserirAVL(raiz->esq, dado, raiz, cresceu);
    } 
    else{
		if (dado > raiz->dado) {
			raiz->dir = inserirAVL(raiz->dir, dado, raiz, cresceu);
		}
		else{
			*cresceu = 0; 
		}
        return raiz;
    }
    return balancear(raiz);
}

Arv* maiorEsq(Arv* no) {
    Arv* atual = no->esq;
    while (atual && atual->dir)
        atual = atual->dir;
    return atual;
}

Arv* removerAVL(Arv* raiz, int chave, int* diminuiu) {
    if (raiz == NULL) {
        *diminuiu = 0;
        return NULL;
    }

    if (chave < raiz->dado) {
        raiz->esq = removerAVL(raiz->esq, chave, diminuiu);
    } else if (chave > raiz->dado) {
        raiz->dir = removerAVL(raiz->dir, chave, diminuiu);
    } else {
        if (!raiz->esq || !raiz->dir) {
            Arv* temp = raiz->esq ? raiz->esq : raiz->dir;
            if (temp) temp->pai = raiz->pai;
            free(raiz);
            *diminuiu = 1;
            return temp;
        } else {
            Arv* temp = maiorEsq(raiz);
            raiz->dado = temp->dado;
            raiz->esq = removerAVL(raiz->esq, temp->dado, diminuiu);
        }
    }

    return balancear(raiz);
}

void emOrdem(Arv* raiz) {
    if (raiz) {
        emOrdem(raiz->esq);
        printf("%d ", raiz->dado);
        emOrdem(raiz->dir);
    }
}

void inicializarAVL(descritorAvl* arv) {
    arv->raiz = NULL;
    arv->altura = 0;
}

void atualizarAltura(descritorAvl* arv) {
    arv->altura = altura(arv->raiz);
}


void exibirArvore(Arv* raiz, int nivel) {
    if (raiz != NULL) {
        exibirArvore(raiz->dir, nivel + 1);

        for (int i = 0; i < nivel; i++)
            printf("    "); // indentação

        printf("%d\n", raiz->dado);

        exibirArvore(raiz->esq, nivel + 1);
    }
}

void menu() {
    printf("\n====== MENU AVL ======\n");
    printf("1. Inserir elemento\n");
    printf("2. Remover elemento\n");
    printf("3. Exibir em ordem\n");
    printf("4. Mostrar altura\n");
    printf("5. Exibir árvore graficamente\n");
    printf("0. Sair\n");
    printf("======================\n");
    printf("Escolha: ");
}

int main() {
    descritorAvl arvore;
    inicializarAVL(&arvore);

    int opcao, valor;
    int cresceu=-1, diminuiu;

    do {
        menu();
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o valor a inserir: ");
                setbuf(stdin,NULL);
                scanf("%d", &valor);
                arvore.raiz = inserirAVL(arvore.raiz, valor, NULL, &cresceu);
                if (cresceu==1) 
					printf("Inserido com sucesso.\n");
                else 
					printf("Valor já existe na árvore.\n");
                break;
            case 2:
                printf("Digite o valor a remover: ");
                setbuf(stdin,NULL);
                scanf("%d", &valor);
                arvore.raiz = removerAVL(arvore.raiz, valor, &diminuiu);
                if (diminuiu==1) 
					printf("Removido com sucesso.\n");
                else 
					printf("Valor não encontrado.\n");
                break;
            case 3:
                printf("Elementos em ordem: ");
                emOrdem(arvore.raiz);
                printf("\n");
                break;
            case 4:
                atualizarAltura(&arvore);
                printf("Altura da árvore: %d\n", arvore.altura);
                break;
            case 0:
                printf("Encerrando...\n");
                break;
            case 5:
                printf("\nVisualização da Árvore:\n");
                exibirArvore(arvore.raiz, 0);
                break;
            default:
                printf("Opção inválida.\n");
        }

    } while (opcao != 0);

    return 0;
}
