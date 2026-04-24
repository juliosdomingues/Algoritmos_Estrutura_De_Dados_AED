#include <stdio.h>
struct TecProg {/* Criacao de uma struct sem alocacao de espaco */
long mat;
float nota;
} ;
struct identidade{ /*Criacao de uma segunda struct que inclui a primeira*/
char nome[40];
struct TecProg aluno;
} ;

struct turma{ /*Criacao de uma terceira struct que inclui a primeira*/
int id;
struct identidade * alunos;
};


int main( )
{
//a_locação direta identidade
struct identidade aluno1;// endereco [1000]
//ponteiro para o tipo identidade
struct identidade *apont ; //[null]

//atualizando referência direta 
aluno1.aluno.mat = 20411032;
aluno1.aluno.nota = 7.8 ;
//referência indireta
apont = &aluno1; //apont -> [1000]
printf ("%ld %f\n", aluno1.aluno.mat,aluno1.aluno.nota) ;
printf ("%ld %f\n", apont->aluno.mat, apont->aluno.nota) ;
printf ("%ld %f\n", (*apont).aluno.mat, (*apont).aluno.nota) ;



//-----------------terceiro redirecionamento-----------------------//
struct turma *pnovaTurma;
struct turma novaTurma;

novaTurma.id=1;
novaTurma.alunos=&(aluno1);

//novaTurma.alunos = (struct identidade*)malloc(sizeof(struct identidade)*1);
//novaTurma->alunos.mat=10;
//strcpy(novaTurma->alunos.nome,"Julio");

printf ("%d %ld %f\n", novaTurma.id, novaTurma.alunos->aluno.mat, novaTurma.alunos->aluno.nota) ;
printf ("%d %ld %f\n", novaTurma.id, (*novaTurma.alunos).aluno.mat, (*novaTurma.alunos).aluno.nota) ;

pnovaTurma = &(novaTurma);
printf ("%d %ld %f\n", pnovaTurma->id, pnovaTurma->alunos->aluno.mat, pnovaTurma->alunos->aluno.nota) ;
printf ("%d %ld %f\n", (*pnovaTurma).id, (*pnovaTurma->alunos).aluno.mat, (*pnovaTurma->alunos).aluno.nota) ;


return 0;
}
