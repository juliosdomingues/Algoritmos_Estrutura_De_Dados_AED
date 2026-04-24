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
	// pValor -> NULL
	pValor = &valor; // pValor = 1000 
	
	
	//imprimindo conteudo apontado pelo endereço de memória 
	printf("pvalor vale inteiro [endereço memoria]  %d\n", pValor);
	printf("pvalor vale hexa [endereço memoria]  %x\n", (unsigned int )pValor);
	printf("pvalor vale [conteúdo] %d\n", *pValor);
	
	tipo_aluno novoAluno;

	//ponteiro para o tipo tipo_aluno
	tipo_aluno * maisNovoAluno;
	//alocação dinâmica de um vetor de 100 alunos
	maisNovoAluno = (tipo_aluno *) malloc(100*sizeof(tipo_aluno));
	//modificando o valor do aluno 89 do vetor
	maisNovoAluno[89].nota1=100;
	
	//copiando o endereço alocado de novo Aluno para maisNovoAluno
	maisNovoAluno = &novoAluno;
	maisNovoAluno->nota1=10; //indireção
	(*maisNovoAluno).nota1=100;

	
	return 0;
}
