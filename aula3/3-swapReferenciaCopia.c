#include <stdio.h>
#include <stdlib.h>

void troca(int ax,int bx);
void trocaP(int *ax,int *bx);

int main(void){

int a=6, b=5;

printf("a %d, b %d\n", a,b);
troca(a,b);
printf("a %d, b %d\n", a,b);

trocaP(&a,&b);
printf("a %d, b %d\n", a,b);

return 0;
}

void troca(int a,int b){
	int aux;
	aux = a;
	a = b ;
	b = aux;
	printf("ax %d, bx %d\n", a,b);
}


void trocaP(int *ax,int *bx){
	int aux;
	aux = *(ax);
	*(ax) = *(bx) ;
	*(bx) = aux;
}


