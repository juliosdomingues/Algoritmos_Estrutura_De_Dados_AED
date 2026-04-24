#include <stdio.h>
#include <stdlib.h>

typedef struct aluno{
	char nome[60];
	int nota1;
	int nota2;
	int matricula;
}tipo_aluno;


int main(){
	
	int valor; //variavel inteira 4bytes -> aloca memoria [1000] = 10
	valor = 10;
	int *pValor; // não aloca 4 bytes para guardar valor e sim posição/endereço de memória
	// pValor -> NULL/					
	pValor = &valor; // pValor = 1000 
	
	
	
	printf("pvalor vale [endereço memoria]  %d\n", pValor);
	printf("pvalor vale [conteúdo] %d\n", *pValor);
	
	tipo_aluno novoAluno;

	tipo_aluno * maisNovoAluno;
	maisNovoAluno = (tipo_aluno *) malloc(100*sizeof(tipo_aluno));
	maisNovoAluno[89].nota1=100;
	
	maisNovoAluno = &novoAluno;
	maisNovoAluno->nota1=10; //indireção
	(*maisNovoAluno).nota1=100;
	
	
	return 0;
}
