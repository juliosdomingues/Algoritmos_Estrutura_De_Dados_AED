#include <stdio.h>
#include <stdlib.h>

int main (){

char nome[10];
char curso[10];
int idade;
scanf("%d",&idade);
setbuf(stdin,NULL);
//scanf("%s",nome);
scanf("%[^\n]s",nome);
setbuf(stdin,NULL);
//scanf("%s",curso);
scanf("%[^\n]s",curso);
setbuf(stdin,NULL);

printf("===========================\n");
printf("nome: %s\n",nome);
printf("curso: %s\n",curso);
printf("idade: %d\n",idade);

return 0;
}
