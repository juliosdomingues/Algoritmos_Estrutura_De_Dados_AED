#include <stdio.h>
#include <stdlib.h>

struct hm{
	int horas;
	int minutos;
};

struct hm calculaHora(int minutos);

int main(){
int minutos;
scanf("%d",&minutos);
struct hm minhaHora;
minhaHora = calculaHora(minutos);
printf("HORAS:%d\n",minhaHora.horas);
printf("MINUTOS:%d\n",minhaHora.minutos);
return 0;
}

struct hm calculaHora(int minutos){
	struct hm structCalculaHora;
	structCalculaHora.horas 	= minutos/60;
    structCalculaHora.minutos 	= minutos % 60;
	return structCalculaHora;	
}
