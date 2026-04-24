#include <stdio.h>

int main ()
{
   FILE *fp;

   fp = fopen("file2.txt","w");
   //escreve a informação inicial no arquivo com 26 bytes 
   fputs("Essa e a disciplina de LP1", fp);
   fclose(fp);
   getchar();
   fp = fopen("file2.txt","r+");
   //movimenta o ponteiro do arquivo 7 bytes (para isso negativo) a partir do final
   fseek(fp,(-7),SEEK_END);
   //sobrescreve a informação
   fputs(" de programação em C", fp);
   fclose(fp);
   
   return(0);
}
