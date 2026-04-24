#include <stdlib.h>
#include <stdio.h>

enum genero{
	rock=1,samba=2,reggae=3,heavy_metal=4
};
	
struct cadastro_banda{
	char nome[20];
	enum genero tipo;
};

	
int main(){
	int tipo;
	struct cadastro_banda* minhaBanda = (struct cadastro_banda*) malloc(sizeof(struct cadastro_banda));
	scanf("%s[^\n]", minhaBanda->nome);
	scanf("%d",&tipo);
	minhaBanda->tipo=tipo;
	switch(minhaBanda->tipo){
		case (rock):{
			printf("banda %s estilo Rock %d\n", minhaBanda->nome,minhaBanda->tipo);
			break;
		}
		case (samba):{
			printf("banda %s estilo Samba %d\n", minhaBanda->nome,minhaBanda->tipo);
			break;
		}
		case (reggae):{
			printf("banda %s estilo Reggae %d\n", minhaBanda->nome,minhaBanda->tipo);
			break;
		}
		case (heavy_metal):{
			printf("banda %s estilo Heavy-Metal %d\n", minhaBanda->nome,minhaBanda->tipo);
			break;
		}
	}
	return 0;
}
