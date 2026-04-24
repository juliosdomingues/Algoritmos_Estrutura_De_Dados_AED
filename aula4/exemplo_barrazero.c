#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

char nome1[100];
char nome2[100];
char nome3[100];

printf("digite o seu nome completo\n");
scanf("%[^\n]s",nome1);
setbuf(stdin,NULL);
printf("digite o seu nome completo\n");
fgets(nome2,99,stdin);
printf("digite o seu nome completo\n");
gets(nome3);

printf("nome1: %s com tamanho %d\n",nome1,strlen(nome1));
printf("nome2: %s com tamanho %d\n",nome2,strlen(nome2));
printf("nome3: %s com tamanho %d\n",nome3,strlen(nome3));

if(strcmp(nome1,nome2) == 0)
	printf("nome1 e nome2 igual\n");
else
	printf("nome1 e nome2 diferente\n");

if(strcmp(nome1,nome3) == 0)
	printf("nome1 e nome3 igual\n");
else
	printf("nome1 e nome3 diferente\n");

if(strcmp(nome2,nome3) == 0)
	printf("nome3 e nome2 igual\n");
else
	printf("nome3 e nome2 diferente\n");




return 0;
}
