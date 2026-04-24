#include <stdlib.h>
#include <stdio.h>

int main(){

FILE *arquivoSaida;

arquivoSaida = fopen("relatorio.txt", "w");
if(arquivoSaida == NULL){
	printf("o arquivo de relatorio não foi aberto\n");
	exit(-1);
}
int i=10;
printf("ola mundo %d======== \n",i);

fprintf(arquivoSaida,"ola mundo %d======== \n",i);

return 0;
}
