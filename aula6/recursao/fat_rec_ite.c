#include <stdio.h>
#include <stdlib.h>

int fatIterativo(int f);
int fatRecursivo(int f);


int main(){
	int totalRecursivo=0, totalIterativo=0;
	int f;
	
	printf("entre com o valor do fatorial\n");
	scanf("%d", &f);
	
	totalIterativo = fatIterativo(f);
	totalRecursivo = fatRecursivo(f);
	
	printf("total iterativo:%d\n",totalIterativo);
	printf("total recursivo:%d\n",totalRecursivo);
	return 0;
}

int fatIterativo(int f){
	int total = 1;
	int i;
	printf("------chamada iterativa fatorial f=%d------\n",f); 
	for(i=f;i>1;i--){
		total =i*total;
		printf("total %d i= %d\n",total,i);
	}
	printf("------retorno iterativa fatorial f=%d------\n",f); 
	return total;
}

int fatRecursivo(int f){
	printf("------chamada recursiva fatorial f=%d------\n",f); 
	if(f == 0){
		printf("------retorno recursivo fatorial f=1------\n"); 
		return 1;
	}
	else{
		int total = f*fatRecursivo((f-1));
		printf("------retorno recursivo fatorial f=%d------\n",total); 
		return 	total;	
	}
}

