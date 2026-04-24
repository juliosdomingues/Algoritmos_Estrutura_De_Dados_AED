#include <stdio.h>

int fiboRec(int n);

int main(){
	int N, num, numA, numB, i;
	printf("Digite quantos termos devem aparecer.\n");
	scanf("%d", &N);
	numA = 1; numB = 0; i = 0;
	printf("Calculo ITERATIVO\n");
	while(i < N){
		printf("%d, ", numA);
		num = numA + numB;
		numB = numA;
		numA = num;
		i++;
	}
	printf("\nresultado ITERATIVO %d\n", numB);	
	printf("\nresultado RECURSIVO %d\n", fiboRec(N));
return 0;
}

int fiboRec(int n){
	printf("Recursão calculo fib(%d)\n",n);
	if((n==1)||(n==2)){
		printf("calculou %d = 1\n",n);
		return 1;
	}
	else{
		int fib_1 = fiboRec(n-1);
		int fib_2 = fiboRec(n-2);
		int total = fib_1+fib_2;
		printf("calculou %d = %d + %d\n",total,fib_1,fib_2);
		return total;
	}
	
}
