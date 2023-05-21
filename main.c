#include <stdio.h>
#include <string.h>

int main(void) {
  
  FILE * f1;
  
  FILE * f2;
  
  FILE * f3;
  
  FILE * filelungo;
  char riga1[300], riga2[300], rigalungo[300];
  
  f1=fopen("File1.txt","r");
  f2=fopen("File2.txt","r");
  f3=fopen("Ordinato.txt","w");
  
  fgets (riga1, 300,f1);
  fgets (riga2, 300,f2);
  
  while(!feof(f1) && !feof(f2)){
    
    if(strcmp(riga1,riga2)<0){
        fprintf(f3,"%s",riga1);
        fgets(riga1, 300, f1);
    } else{
        fprintf(f3,"%s",riga2);
        fgets(riga2, 300, f2);
    }
  }
  if(feof(f1)){
      filelungo=f2;
      strcpy(rigalungo, riga2);
  } else{
      filelungo=f1;
      strcpy(rigalungo, riga1);
  }
  
  while(!feof(filelungo)){
      fprintf(f3,"%s",rigalungo);
      fgets (rigalungo,300,filelungo);
  }
  
  fclose (f1);
  
  fclose (f2);
  
  fclose (f3);
  
  return 0;

}
