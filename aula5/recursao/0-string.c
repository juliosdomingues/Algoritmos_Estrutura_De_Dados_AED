#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
 char nome[7];
 char nome2[7];
 setbuf(stdin,NULL);
 scanf("%s[^\n]",nome);
 setbuf(stdin,NULL);
 fgets(nome2,6,stdin);
 printf ("%s %d\n",nome, strlen(nome));
 printf ("%s %d\n",nome2, strlen(nome2));
 setbuf(stdin,NULL);
return 0;
}
