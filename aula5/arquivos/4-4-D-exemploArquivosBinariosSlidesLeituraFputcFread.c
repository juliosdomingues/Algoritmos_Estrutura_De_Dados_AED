#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

FILE *arquivo;
int vet[5];// = {1,2,3,4,5};
float numero; //=5;
char str[13]; //= "hello world";
if((arquivo=fopen("dadosFputc.bin","rb"))==NULL){
	printf("erro na abertura do arquivo");
}

int i; 
for(i=0;i<5;i++){
	vet[i] = fgetc(arquivo);
}
numero = fgetc(arquivo);
for(i=0;i<13;i++){
	str[i] = fgetc(arquivo);
}
printf("%d %d %d %d %d\n",vet[0],vet[1],vet[2],vet[3],vet[4]);
printf("%f\n",numero);
printf("%s\n",str);




fread(&vet,sizeof(int),5,arquivo);
fread(&numero,sizeof(float),1,arquivo);
fread(&str,sizeof(char),13,arquivo);
//imprime todos os elementos
printf("%d %d %d %d %d\n",vet[0],vet[1],vet[2],vet[3],vet[4]);
printf("%f\n",numero);
printf("%s\n",str);
fclose(arquivo);

return 0;
}
