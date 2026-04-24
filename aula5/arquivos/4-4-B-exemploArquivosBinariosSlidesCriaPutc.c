#include <stdio.h>
#include <stdlib.h>

int main(){

FILE *arquivo;
//int vet[5] = {1,2,3,4,5};
int vet[5] = {1,2,3,4,709342};
float numero=5;
char str[13]= "hello world";
if((arquivo=fopen("dadosFputc.bin","wb"))==NULL){
	printf("erro na abertura do arquivo");
}
int i; 
for(i=0;i<5;i++){
	fputc(vet[i],arquivo);
}
fputc(numero,arquivo);
for(i=0;i<13;i++){
	fputc(str[i],arquivo);
}
printf("%d %d %d %d %d\n",vet[0],vet[1],vet[2],vet[3],vet[4]);
printf("%f\n",numero);
printf("%s\n",str);
fclose(arquivo);
return 0;
}
