#include <stdio.h>
#include <stdlib.h>
int main(){
int n;
fprintf(stdout, "Entre com um número entre 1 e 10\n");
setbuf(stdout,NULL);

fscanf(stdin, "%d", &n);
setbuf(stdin,NULL);

	if(n>=1 && n<=10){
		fprintf(stdout, "OK: %d\n", n);
	}
	else{
		fprintf(stderr, "Erro: %d\n", n);
	}
return 0;
}
