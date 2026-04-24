#include <stdio.h>
#include <stdlib.h>


typedef struct produto{/* Definicao de uma estrutura */
int num_item;
char nome_item[30];
char espec_item[60] ;
} Estrutura;/* Codinome da struct */

int main(){

Estrutura est1;
est1.num_item =100;

printf("est1 numitem %d\n",est1.num_item);

Estrutura *Apont;
Apont = &est1;
Apont->num_item=200;
printf("est1 numitem %d\n",est1.num_item);
(*Apont).num_item=300;
printf("est1 num_item %d\n",est1.num_item);

return 0;

}
