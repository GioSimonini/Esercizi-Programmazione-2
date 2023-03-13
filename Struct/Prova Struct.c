#include <stdio.h>


typedef struct studente {
  char Nome[30];
  char Cognome[30];
  int annonascita;
  char sesso;
} s;



void carica (s elenco[],int n){

  for(int i=0;i<n; i++){
    printf("Inserisci Nome: ");
    scanf("%s",elenco[i].Nome);
    printf("Inserisci Cognome: ");
    scanf("%s",elenco[i].Cognome);
    printf("Inserisci Anno di nascita: ");
    scanf("%d",&elenco[i].annonascita);
    do{
    printf("Inserisci sesso: (M o F) ");
    scanf("\n%c",&elenco[i].sesso);
    }while(elenco[i].sesso!='M' && elenco[i].sesso!='F');
      printf("\n");
  }
}
  void stampa(s elenco[],int n){

    for(int i=0; i<n; i++){
      printf("\n");
      printf("-------------------------\n");
      printf("Nome: %s\n",elenco[i].Nome);
      printf("Cognome: %s\n",elenco[i].Cognome);
      int eta=2023;
      eta=eta-elenco[i].annonascita;
      printf("Eta': %d\n",eta);
      printf("Sesso: %c\n",elenco[i].sesso);
    }
    
  }

int main() {
  int n;
  printf("Inserire numero di studenti da caricare: ");
  scanf("%d",&n);
  s studenti[n];
  carica(studenti,n);
  stampa(studenti,n);
  return 0;
}
