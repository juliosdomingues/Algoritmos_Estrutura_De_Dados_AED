#include <stdio.h>
#include <stdlib.h>
int multiplica(int N1, int N2); //multiplica recebe N1,N2 e retorna um int

int main(void){
int V1,V2, resultado=0;
printf("Digite o primeiro valor:");
scanf("%d",&V1);
printf("Digite o segundo valor:");
//multiplica recebe N1,N2 e retorna um int
scanf("%d",&V2);
//chama a função e recebe o retorno
resultado = multiplica(V1,V2);
printf("Resultado = %d\n", resultado);
return 0; 
}

int multiplica(int N1, int N2){
	int resultado = 0;
	resultado = N1*N2;
	return resultado;
}
