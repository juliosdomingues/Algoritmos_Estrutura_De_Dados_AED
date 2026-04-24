#include <stdio.h>
#include <stdlib.h>

struct aluno{
	char nome[50];
	char rua[50];
	int numero;
	int cep;
};
int main(void){
	printf("digite a quantidade de alunos\n");
	int alunosQ;
	setbuf(stdin,NULL);
	scanf("%d",&alunosQ);
	struct aluno *turma = (struct aluno*)malloc(sizeof(struct aluno) * alunosQ);
	int i;
	for(i=0;i<alunosQ;i++){
		getchar();
		setbuf(stdin,NULL);
		scanf("%[^\n]s", turma[i].nome);
		getchar();
		setbuf(stdin,NULL);
		scanf("%[^\n]s", turma[i].rua);
		setbuf(stdin,NULL);
		scanf("%d", &turma[i].numero);
		setbuf(stdin,NULL);
		scanf("%d", &turma[i].cep);
	}
	printf("ALUNOS CADASTRADOS:==============================\n");
	for(i=0;i<alunosQ;i++){
		printf("%s\n", turma[i].nome);
		printf("%s\n", turma[i].rua);
		printf("%d\n", turma[i].numero);
		printf("%d\n", turma[i].cep);
		printf("-------------------------\n");
	}
	printf("=================================================\n");
return 0;
}
