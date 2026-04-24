#include <stdio.h>

int main ()
{
   FILE *fp;

   fp = fopen("file.txt","w");
   //escreve a informação inicial no arquivo com 26 bytes 
   fputs("Essa e a disciplina de LP1", fp);
   fclose(fp);
   getchar();
   fp = fopen("file.txt","rw+");
   //movimenta o ponteiro do arquivo 19 bytes após o inicio
   fseek(fp, 19, SEEK_SET);
   //sobrescreve a informação
   fputs(" de programação em C", fp);
   fclose(fp);
   
   return(0);
}
