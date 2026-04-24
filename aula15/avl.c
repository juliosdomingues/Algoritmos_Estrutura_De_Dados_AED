#include "avl.h"

descritorAvl *Cria(){
	descritorAvl *avl = (descritorAvl *)malloc(sizeof(descritorAvl));
	avl->altura = 0;
	avl->raiz = NULL;
	return avl;
}

Arv *Busca(Arv *no,int valor){
    Arv *aux=NULL;
    if(no!=NULL){
        if(no->dado==valor){
            return aux=no;
        }
        else{
            if(valor<no->dado){
                Busca(no->esq,valor);
            }
            else{
                Busca(no->dir,valor);
            }
        }
    }
    return NULL;
}


void Insere(Arv **no,int valor, Arv *pai){
	if((*no)==NULL){
		(*no)=(Arv*)malloc(sizeof(Arv));
		(*no)->dado=valor;
		(*no)->esq=NULL;
		(*no)->dir=NULL;
		(*no)->pai=pai;
		(*no)->rotacao=0;
	}
	else{
		if(valor<=(*no)->dado){
            (*no)->rotacao++;
			Insere(&(*no)->esq,valor, (*no));
		}
		else{
		    (*no)->rotacao--;
			Insere(&(*no)->dir,valor, (*no));
		}
	}
}
void Imprime_preorder(Arv *no){
	if(no!=NULL){
		printf("< %d r=%d >",no->dado,no->rotacao);
		Imprime_preorder(no->esq);
		Imprime_preorder(no->dir);
	}
}
void Imprime_inorder(Arv *no){
	if(no!=NULL){
		Imprime_inorder(no->esq);
		printf("< %d r=%d >",no->dado,no->rotacao);
		Imprime_inorder(no->dir);
	}
}
void Imprime_posorder(Arv *no){
	if(no!=NULL){
		Imprime_posorder(no->esq);
		Imprime_posorder(no->dir);
		printf("< %d r=%d >",no->dado,no->rotacao);
	}
}
int Maior(int a, int b){
    return (a>b) ? a : b;
}
int Altura(Arv *no){
   if(no == NULL){
        return 0;
   }
   else{
        return 1 + Maior(Altura(no->esq), Altura(no->dir));
    }
}


Arv *Balanceamento(Arv *no){
    Arv *aux=NULL,*aux2=NULL;
    if(no!=NULL){
        no->esq = Balanceamento(no->esq);
        no->dir = Balanceamento(no->dir);
        if((no->rotacao==2)||(no->rotacao==-2)){
			printf("Pre order= ");
		    Imprime_preorder(no);

            if((no->rotacao>0)&&(no->esq->rotacao>0)){
                //Rotacao Direita
                    if(no->pai !=NULL)
						no->pai->rotacao--;
                printf("*rotação a direita no nó %d\n",no->dado);
                aux = no->esq;
                no->esq = aux->dir;
                if(aux->dir !=NULL)
					aux->dir->pai = no;
                aux->dir = no;
                aux->pai = no->pai;
                no->pai  = aux;
                no->rotacao = 0;                
                no=aux;
                no->rotacao=0;
            }
            else{
                if((no->rotacao<0)&&(no->dir->rotacao<0)){
                    //Rotacao Esquerda
                    if(no->pai !=NULL)
						no->pai->rotacao++;
					printf("*rotação a esquerda no nó %d\n",no->dado);
                    aux = no->dir;
                    no->dir = aux->esq;
					if(aux->esq !=NULL)
						aux->esq->pai = no;
                    aux->esq = no;
                    aux->pai = no->pai;
                    no->pai  = aux;
                    no->rotacao = 0;
                    no = aux;
					no->rotacao=0;
                }
                else{
				//falta ajustar os pais
                    //Rotacao Dupla Direita
                    if((no->rotacao>0)&&(no->esq->rotacao<0)){
						no->pai->rotacao--;
						printf("**rotação Dupla a direita no nó %d\n",no->dado);
                        aux=no->esq;
                        aux2=aux->dir;
                        aux->dir=aux2->esq;
                        aux2->esq=aux;
                        no->esq=aux2->dir;
                        aux2->dir=no;
                        if(aux2->rotacao==-1){
                            no->rotacao=1;
                        }
                        else{
                            no->rotacao=0;
                        }
                        if(aux2->rotacao==1){
                            aux->rotacao=-1;
                        }
                        else{
                            aux->rotacao=0;
                        }
                        no=aux2;
                   }
                    else{
				//falta ajustar os pais
                        //Rotacao Dupla Esquerda
                        if((no->rotacao<0)&&(no->dir->rotacao>0)){
							no->pai->rotacao++;
							printf("**rotação Dupla a esquerda no nó %d\n",no->dado);
                            aux=no->dir;
                            aux2=aux->esq;
                            aux->esq=aux2->dir;
                            aux2->dir=aux;
                            no->dir=aux2->esq;
                            aux2->esq=no;
                            if(aux2->rotacao==-1){
                                no->rotacao=1;
                            }
                            else{
                                no->rotacao=0;
                            }
                            if(aux2->rotacao==1){
                                aux->rotacao=-1;
                            }
                            else{
                                aux->rotacao=0;
                            }
                            no=aux2;   
                        }
                    }
                }
            }
        }
        return no;
    }
    return NULL;
}
