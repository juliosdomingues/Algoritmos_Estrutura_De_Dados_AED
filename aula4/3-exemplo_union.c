#include <stdio.h>
#include <stdlib.h>
#include <string.h>
union valor{
int unsigned valorInt;
float valorFloat;
char valorChar[4];
}variavel;

int main(){

variavel.valorInt=3;
variavel.valorFloat=3.15;
strcpy(variavel.valorChar,"LP1");

printf("valorint %d\nvalorFloat %f\nvalorChar %s\n",variavel.valorInt,variavel.valorFloat,variavel.valorChar);
return 0;
}
