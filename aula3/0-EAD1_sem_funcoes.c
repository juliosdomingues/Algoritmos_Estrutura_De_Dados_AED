//#Disciplina de Estrutura de Dados 
//#Curso de Engenharia de Computação
//#Universidade Federal do pampa - UNIPAMPA
//#Prof. Julio Saraçol
//#semipresencial 1

#include <stdio.h>
#include <stdlib.h>

int main(){

 int menu=1,i,j,linhas=0,colunas=0,colunaVet=0;
 int **matriz = NULL;
 int *vetor = NULL;
 
 while(menu != 0){
	 printf(" \n1-criar matriz\n 2-preenche matriz\n 3-soma matriz\n 4-cria vetor\n 5-sair\n");
	 printf("Escolha uma opção:\n");
	 setbuf(stdin,NULL);
     scanf("%d", &menu);
     
     switch(menu){
		 case 1:
			printf("defina o tamanho de linhas e colunas da matriz\n");
			setbuf(stdin,NULL);
			scanf("%d",&linhas);
			setbuf(stdin,NULL);
			scanf("%d",&colunas);
			matriz =  (int **) malloc(sizeof(int *)*linhas);
			for(i=0;i<linhas;i++){
				matriz[i] = (int *) malloc(sizeof(int)*colunas);
			} 
			break;
		 case 2:
			for(i=0;i<linhas;i++){
				for(j=0;j<colunas;j++){
					matriz[i][j]= (int) (random()%10);
				}
			} 
			break;
		 case 3:
			float soma=0;
			for(i=0;i<linhas;i++){
				for(j=0;j<colunas;j++){
					soma +=matriz[i][j];
				}
			} 
			printf("somatorio da matriz é %f\n",soma);			
			break;
		 case 4:
			//int vetor[linhas];
			vetor = (int *)malloc(sizeof(int)*linhas);
			printf("escolha qual a coluna a ser criada\n valor [0 até %d]",(colunas-1));
			setbuf(stdin,NULL);
			scanf("%d",&colunaVet);
			for(i=0;i<linhas;i++){
				vetor[i] = matriz[i][colunaVet];
			}
			for(i=0;i<linhas;i++){
				printf("%d ",vetor[i]);
			}
			printf("\n");
			break;
		 case 5:
			menu =0;
			break;
		 case 6:
			printf("=------Matriz---------=\n");
			for(i=0;i<linhas;i++){
				for(j=0;j<colunas;j++){
					printf("%d  ",matriz[i][j]);
				}
				printf("\n");
			} 
			printf("=---------------------=\n");
			break;
	 }

 }
 return 0;
}

