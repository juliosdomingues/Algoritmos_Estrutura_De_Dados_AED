#include <stdio.h>
#include <stdlib.h>

int main(){

FILE *arquivo;
int vet[5] = {1,2,3,4,709342};
float numero=50;
char str[13]= "hello world";
if((arquivo=fopen("dados.bin","wb"))==NULL){
	printf("erro na abertura do arquivo");
}
fwrite(&vet,sizeof(int),5,arquivo);
fwrite(&numero,sizeof(float),1,arquivo);
fwrite(&str,sizeof(char),13,arquivo);
//imprime todos os elementos inseridos no arquivo binario
printf("%d %d %d %d %d\n",vet[0],vet[1],vet[2],vet[3],vet[4]);
printf("%f\n",numero);
printf("%s\n",str);
fclose(arquivo);
return 0;
}
