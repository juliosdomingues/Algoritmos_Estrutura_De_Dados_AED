#include <stdio.h>
#include <stdlib.h>

int main (void){
int a[5] = {3,5,8,11,13};
int i;
printf("vetor original\n");
for(i=0; i<5; i++){
	printf("%d - ", *(a+i));
}

for(i=0; i<5; i++){
	*(a+i)+=1;
}
printf("\nvetor modificado\n");
for(i=0; i<5; i++){
	printf("%d - ", *(a+i));
}

return 0;
}
