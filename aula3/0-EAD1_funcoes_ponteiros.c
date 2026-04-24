//#Disciplina de Estrutura de Dados 
//#Curso de Engenharia de Computação
//#Universidade Federal do pampa - UNIPAMPA
//#Prof. Julio Saraçol
//#EAD1

#include <stdio.h>
#include <stdlib.h>

//--------------------------------
int ** criaMatriz(int m, int n);
void leiaMatriz(int **mat, int m, int n);
int somaMatriz(int **mat, int m, int n);
int * colunaMat(int **mat, int m, int n, int ncoluna);
void liberaMatriz(int **mat, int ncoluna);
void imprimeMatriz(int **mat, int m, int n);
void imprimeVet (int *vet, int n);
void liberaMatriz(int **mat, int ncoluna);

int main(){

 int menu=1,linhas=0,colunas=0,colunaVet=0;
 int **matriz = NULL;
 int *vetor  = NULL;
 
 while(menu != 0){
	 printf("\n 1-criar matriz\n 2-preenche matriz\n 3-soma matriz\n 4-cria vetor\n 5-sair\n 6-imprime matriz\n 7-imprime vetor\n 8-liberaMatriz\n");
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
			matriz = criaMatriz(linhas,colunas);
			break;
		 case 2:
			leiaMatriz(matriz,linhas,colunas);
			break;
		 case 3:
			int soma=0;
			soma = somaMatriz(matriz,linhas,colunas);
			printf("somatorio da matriz é %d\n",soma);			
			break;
		 case 4:
			//int vetor[linhas];
			printf("escolha qual a coluna a ser criada\n valor [0 até %d]",(colunas-1));
			setbuf(stdin,NULL);
			scanf("%d",&colunaVet);
			vetor = colunaMat(matriz,linhas,colunas,colunaVet);
			printf("\n");
			break;
		 case 5:
			menu =0;
			break;
		 case 6:
			imprimeMatriz(matriz,linhas,colunas);
			break;
		 case 7:
			imprimeVet(vetor,linhas);
			break;
		 case 8:
			liberaMatriz(matriz,linhas);
			break;
	 }

 }
 return 0;
}


int ** criaMatriz(int m, int n){
	int i,j;
	int **matriz =  (int **) malloc(sizeof(int *)*m);
	for(i=0;i<m;i++){
		matriz[i] = (int *) malloc(sizeof(int)*n);
	} 
/*	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			matriz[i][j] = random()%10;
		}
	} 
	* */
	return matriz;	
}

void leiaMatriz(int **mat, int m, int n){
	int i,j;
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			mat[i][j]= (int) (random()%10);
		}
	} 
}
int somaMatriz(int **mat, int m, int n){
	int i,j,soma=0;
		for(i=0;i<m;i++){
			for(j=0;j<n;j++){
					soma +=mat[i][j];
			}
		} 
		return soma;
}
int * colunaMat(int **mat, int m, int n, int ncoluna){
	int i;
	int *vetor = (int *)malloc(sizeof(int)*m);
	for(i=0;i<m;i++){
		vetor[i] = mat[i][ncoluna];
	}
	return vetor;
}
void liberaMatriz(int **mat, int ncoluna){
	int i;
	for(i=0;i<ncoluna;i++)
		free(mat[i]);
	free(mat);
}
void imprimeMatriz(int **mat, int m, int n){
	if(mat == NULL)
		printf("Vetor ainda não criado\n");
	else{
		printf("=------Matriz---------=\n");
		int i,j;
		for(i=0;i<m;i++){
			for(j=0;j<n;j++){
				printf("%d  ",mat[i][j]);
			}
			printf("\n");
		} 
		printf("=---------------------=\n");
	}
}
void imprimeVet (int *vet, int n){
	if(vet == NULL)
		printf("Vetor ainda não criado\n");
	else{
		int i;
		for(i=0;i<n;i++){
			printf("%d ",vet[i]);
		}
	}
}

