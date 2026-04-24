#include <stdio.h>
#include <stdlib.h>

int main(void){

int nota[5] = {1,2,3,4,5};
int a;
int *p;
p=&a;
printf("%d valor de p e %d valor endereco de a\n",p,&(a));
p=nota;

printf("nota %d\n",nota[0]);
printf("*p %d\n",*p);
p++;
printf("nota %d\n",nota[1]);
printf("*p %d\n",*p);
p--;
printf("nota %d\n",nota[2]);
printf("*p %d\n",*p);


return 0;
}
