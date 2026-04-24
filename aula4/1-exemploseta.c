#include <stdio.h>
#include <stdlib.h>
struct TecProg {/* Criacao de uma struct sem alocacao de espaco */
long mat;
float nota;
};
struct identidade{ /* Criacao de uma segunda struct que inclui a primeira */
char nome[40];
struct TecProg aluno;
};

int main( )
{
struct identidade *apont ;
struct identidade apontOriginal ;

apont = (struct identidade *) malloc(sizeof(struct identidade));

apont->aluno.mat = 20411032;
apont->aluno.nota = 7.8 ;
apontOriginal = *(apont);

apont->aluno.mat = 2000000;
apont->aluno.nota = 9 ;

printf ("%ld %f\n", apontOriginal.aluno.mat,apontOriginal.aluno.nota) ;
printf ("%ld %f\n", apont->aluno.mat,apont->aluno.nota) ;
printf ("%ld %f\n", (*apont).aluno.mat, (*apont).aluno.nota) ;
return 0;
}
