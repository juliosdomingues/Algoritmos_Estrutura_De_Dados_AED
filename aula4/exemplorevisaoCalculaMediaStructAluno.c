#include <stdio.h>
#include <stdlib.h>

struct aluno{
	int matricula; 
	float nota1;
	float nota2;
	float nota3;
};


float calculamedia(float nota1,float nota2, float nota3);
float calculamediastruct(struct aluno umAluno);

int main(void){
	
struct aluno novoAluno[3];	
int i;

for(i=0;i<3;i++){	
	scanf("%d", &novoAluno[i].matricula);	
	scanf("%f", &novoAluno[i].nota1);	
	scanf("%f", &novoAluno[i].nota2);	
	scanf("%f", &novoAluno[i].nota3);	
	printf("a media do aluno %d e %f\n",novoAluno[i].matricula, calculamedia(novoAluno[i].nota1,novoAluno[i].nota2,novoAluno[i].nota3));
	printf("a media do aluno %d e %f\n",novoAluno[i].matricula, calculamediastruct(novoAluno[i]));	
}

return 0;
}


float calculamedia(float nota1,float nota2, float nota3){
	float media;
	media = (float) (nota1+nota2+nota3)/3;
	return media;
}


float calculamediastruct(struct aluno umAluno){
	float media;
	media = (float) (umAluno.nota1+umAluno.nota2+umAluno.nota3)/3;
	return media;
}
	
