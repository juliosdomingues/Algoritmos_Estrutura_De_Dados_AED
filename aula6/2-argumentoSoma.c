#include <stdio.h>
#include <stdlib.h>
int main( int argc, char *argv[ ] )
{
	
/*if(argc < 3){
	printf("voce não digitou os parametros necessarios, são 2\n");
	exit(-1);
}*/	
	
int Resultado, valorA=0, valorB=0;
printf("\nSomando valores passados na linha de comando\n");
//atoi converte de alfanumérico para inteiro
valorA = atoi(argv[1]);
valorB = atoi(argv[2]);
Resultado = valorA + valorB;
printf("\n%d + %d = %d\n",valorA,valorB,Resultado);
return 0;
}
