#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
Scrivere un programma che legga da un
file di testo una serie di numeri interi, li sommi e stampi il
risultato.

Scrivere un programma che legga da un
file di testo una serie di numeri interi, li inserisca in un
array e li scriva su un altro file in ordine inverso (usando le
primitive fscanf e fwrite).

Scrivere un programma che legga da un
file di testo una serie di parole e conti quanti volte
compare una determinata parola all'interno del file.*/


int Es1 (char *nomefile){
  FILE *fp=fopen(nomefile, "r");
  int sum=0,n;
  while(!feof(fp)){
    fscanf(fp,"%d",&n);
    sum+=n;
  }
  fclose(fp);
  return sum;
}
void Es2(char *nomefile,char *nomefile2){
  FILE *fp=fopen(nomefile,"r");
  int *v=NULL;
  int n=0;
  
  while(!feof(fp)){
    if(v==NULL){
      v=malloc(sizeof(int));
    }else{
      v=realloc(v,(n+1)*sizeof(int));
    }
    fscanf(fp,"%d",&v[n]);
    n++;
  }
  fclose(fp);

 FILE *fp2=fopen(nomefile2,"w");
  for(int i=n-1; i>=0;i--){
    fprintf(fp2,"%d\t",v[i]);
  }
  fclose(fp2);
}


int Es3(char* nomefile,char *cerca){
  FILE *fp=fopen(nomefile,"r");
  if(fp==NULL){
    printf("ERRORE APERTURA FILE");
  return -1;
  }
  char v[64];
  int n=0;
  while(!feof(fp)){
    fscanf(fp,"%s",v);
    if(strcmp(v,cerca)==0)
      n++;
  
  }
  return n;
}


int main(int argc, char* argv[]) {
  char v[64];
  if(argc<1){
    printf("Errore inserimento argomenti\n");
    return -1;
  }else{
  printf("Somma valori file: %d\n",Es1(argv[1]));
  
  
  Es2(argv[1],"contrario.txt");

  printf("Inserire parola da controllare: ");
  scanf("%s",v);
  printf("Numero di ripetizioni di %s: %d\n",v,Es3("parole.txt",v));
  }
}
