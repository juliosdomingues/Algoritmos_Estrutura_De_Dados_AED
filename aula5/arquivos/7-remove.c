#include <stdio.h>
#include <stdlib.h>
int main()
{
	FILE *p;
	char str[30], frase[] = "Este e um arquivo chamado: ", resposta[80];
	int i;

	/* Le um nome para o arquivo a ser aberto: */
	printf("\n\n Entre com um nome para o arquivo:\n");
	/* Usa fgets como se fosse gets */
	fgets(str,29,stdin);			
	/* Elimina o \n da string lida */		
	for(i=0; str[i]; i++) if(str[i]=='\n') str[i]=0;
	/* Caso ocorra algum erro na abertura do arquivo..*/	
	if (!(p = fopen(str,"w")))  				 
  	{   /* o programa aborta automaticamente */            				
  		printf("Erro! Impossivel abrir o arquivo!\n");
  		exit(1);
  	}
	/* Se nao houve erro, imprime no arquivo, e o fecha ...*/
	fputs(frase, p);
	fputs(str,p);
  	fclose(p);

	/* abre novamente e le */
	p = fopen(str,"r");
	fgets(resposta, 79, p);
	printf("\n\n%s\n", resposta);
	fclose(p);			/* Fecha o arquivo */
	printf("arquivo removido status de retorno:%d",remove(str));			/* Apaga o arquivo */
	return(0);
}
