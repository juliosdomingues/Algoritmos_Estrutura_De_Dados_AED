#include <stdio.h>

int estouraPilha(int n);

int main(){

estouraPilha(10);

return 0;

}


int estouraPilha(int n){
	printf("instancia do estoura pilha %d\n",n);
	if(n==0)
	 return 0;
		else
		return estouraPilha(n+1);
}
