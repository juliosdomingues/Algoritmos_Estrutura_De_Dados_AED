#include <stdio.h>
#include <stdlib.h>

//GLOBAL 
int valor; //alocação estática


struct aluno{
 char nome[60];
 } novoAluno; //alocação estática

int main(){
 int valor2; //Alocação na Pilha
 char nome[5000]; //Alocação na Pilha 
 int * ponteiroInteiro =  malloc(sizeof(int)); //Alocação da HEAP -> alocação dinâmica
 return 0;
}

int fatorial(int n){

int valor4; //Alocação na Pilha no escopo da função fatorial
	fatorial(n-1);		//Ao fim será deletado
}
