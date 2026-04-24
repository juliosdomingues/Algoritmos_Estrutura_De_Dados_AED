#include <stdio.h>
#include <stdlib.h>


int main(int argc, char **argv){
	if(argc < 3){
		printf("numero de argumentos minimo 3 programa arg1 arg2\n");
		exit(-1);
	}
	int i=0;
	for(i=0;i<argc;i++){
		printf("argumento no argv: %s\n",argv[i]);
	}

	return 0;
}
