#include <stdio.h>
#include <stdlib.h>

void multiplica(int N1[], int *N2,int resultado[], int tamanho); 
//multiplica recebe N1,N2 e retorna um int
/******************* função principal (main) *********************/
int main(void) {
int tamanho=5, i;
int V1[tamanho], V2[tamanho], resultado[tamanho];
 for(i=0;i<tamanho;i++){
  printf("Digite o valor A[%d]:",i);
  scanf("%d", &V1[i]);
  printf("Digite o segundo valor B[%d]:",i);
  scanf("%d", &V2[i]);
}

 multiplica(V1,V2,resultado, tamanho);  
 for(i=0;i<tamanho;i++){
      printf("Resultado[%d] = %d\n", i,resultado[i]);
 }

 multiplicaP(V1,V2,resultado, tamanho);  
 for(i=0;i<tamanho;i++){
      printf("ResultadoP[%d] = %d\n", i,resultado[i]);
 }
   return 0;
}

void multiplica(int N1[], int *N2, int resultado[], int tamanho) 
//multiplica recebe N1,N2 e retorna um int
{
 int i;
 for(i=0;i<tamanho;i++){
      resultado[i] = N1[i] * N2[i];
  }
}

void multiplicaP(int N1[], int *N2, int *resultado, int tamanho) 
//multiplica recebe N1,N2 e retorna um int
{
 int i;
 for(i=0;i<tamanho;i++){
      resultado[i] = N1[i] * N2[i];
  }
}
