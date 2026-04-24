#include <stdio.h>
#include <stdlib.h>

void incrementa(int *x, int *y);


int main(){

int a[] = {1,2,3};
printf("Vetor: %d %d %d\n",a[0],a[1],a[2]);
for (int i=0; i<3; i++){
	incrementa(&a[i],&a[1]);
	printf("\n %d\n",a[i]);
	printf("Vetor: %d %d %d\n",a[0],a[1],a[2]);
}

return 0;
}

void incrementa(int *x, int *y){
	*x = *x + (*y);
	(*y)++;
}
