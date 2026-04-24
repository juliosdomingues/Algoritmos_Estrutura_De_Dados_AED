#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

int main(void){
	int menu,valor,controle=0;
	
	descritorAvl *avl=NULL;
	Arv *aux=NULL;
	
	do{
	   	printf("1 - Criar uma arvore\n2 - Inserir um elemento\n3 - Imprimir o conteudo da arvore\n4 - Imprimir a altura da arvore\n5 - Buscar na arvore\n6 - Sair \n ");
	    scanf("%d",&menu);
	    switch(menu){
	    	case 1:{
                if(controle==0){
	    			avl=Cria();
	    			printf("Arvore criada com sucesso\n");
	    			controle++;
	    		}
	    		else{
	    			printf("Já existe uma arvore criada\n");
	    		}
	    		break;
	    	}
	    	case 2:{
	    		if(controle!=0){
	    			printf("Digite um valor para inserir\n");
	    			scanf("%d",&valor);
	    			Insere(&(avl->raiz),valor, NULL);
	    			avl->raiz=Balanceamento(avl->raiz);
	    			printf("Valor adicionado com sucesso\n");
	    		}
	    		else{
	    			printf("Crie uma arvore primeiro\n");
	    		}
	    		break;
	    	}
	    	case 3:{
	    		if(avl->raiz!=NULL && controle!=0){
	    			printf("Pre order= ");
		    		Imprime_preorder(avl->raiz);
		    		printf("\nIn order= ");
	    			Imprime_inorder(avl->raiz);
	    			printf("\nPos order= ");
	    			Imprime_posorder(avl->raiz);
	    			printf("\n");
	    		}
	    		else
                {
                    printf("Crie uma arvore primeiro ou adicione uma valor a arvore\n");
                }
	    		break;
	    	}
	    	case 4:{
					if(controle!=0){
						valor=Altura(avl->raiz);
						printf("Altura da arvore igual a %d\n",valor+1);
					}
					else{
						printf("Crie uma arvore primeiro\n");
					}
					break;
            }

            case 5:{
				    printf("Digite um valor para buscar\n");
				    scanf("%d",&menu);
				    aux=(Busca(avl->raiz,menu));
				    if (aux != NULL){
						printf("Valor encontrado %d\n",aux->dado);
				    }
				    else{
						printf("Valor inexistente\n");
				    }
				    break;
            }
		    default:{
			    printf("EXIT\n");
		    }
	    }
	}while(menu<5);
	return 0;
}
