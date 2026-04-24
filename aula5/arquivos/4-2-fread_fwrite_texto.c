#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

FILE *file;

file = fopen("entrada.txt","wb");

//cria um arquivo de entrada.txt em texto puro com fwrite
char string[200];
strcpy(string,"olá estou escrevendo em bytes com fwrite\n");
int tamanho=strlen(string);
fwrite(string,sizeof(char),tamanho, file);
fclose(file);

FILE *file2 = fopen("entrada.txt","rb");
//cria um arquivo de entrada.txt em texto puro com fwrite
char string2[200];
fread(string2,200,1,file2);
printf("Lendo o arquivo em bytes com Fread com o conteudo:\n");
printf("%s",string2);
fclose(file2);


return 0;

}
