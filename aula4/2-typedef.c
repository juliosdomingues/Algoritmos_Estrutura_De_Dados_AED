#include <stdio.h>
#include <stdlib.h>

typedef struct ponto{
	int x;
	int y;
}ponteira;

int main(){
	
	ponteira meuponto;
	meuponto.x = 1;
	meuponto.y = 2;
	
	printf("meu ponto %d %d",meuponto.x,meuponto.y);
	
	return 0;
}
