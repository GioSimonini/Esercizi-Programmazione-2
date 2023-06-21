#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*Creare una struct di calciatori con Nome,Cognome,Anno,Numero Maglia,Valore
  (MLN)
  creare una lista per aggiungere e Stampare i calciatori Usare la malloc
  e la realloc 
  Scrivere in un file tutti i dati
  funzione Modifica Calciatori ed elimina calciatori
*/

struct calciatore {

  char Nome[20];
  char Cognome[20];
  int AnnodiNascita;
  int NumeroMaglia;
  int Valore;
};

struct calciatore add_calciatore() {
  struct calciatore c;
  printf("Inserisci Nome: ");
  scanf("%s", c.Nome);
  printf("Inserisci Cognome: ");
  scanf("%s", c.Cognome);
  printf("Inserisci Anno di Nascita: ");
  scanf("%d", &c.AnnodiNascita);
  do {
    printf("Inserisci Numero di Maglia: ");
    scanf("%d", &c.NumeroMaglia);
  } while (c.NumeroMaglia <= 1 && c.NumeroMaglia >= 99);
  printf("Inserisci Valore (MLN): ");
  scanf("%d", &c.Valore);

  return c;
}

void stampa(struct calciatore database[], int n) {
  for (int i = 0; i < n; i++) {
    printf("------------------------------------------\n");
    printf("Nome: %s\n", database[i].Nome);
    printf("Cognome: %s\n", database[i].Cognome);
    printf("Anno di Nascita: %d\n", database[i].AnnodiNascita);
    printf("Numero Maglia: %d\n", database[i].NumeroMaglia);
    printf("Valore: %d MLN\n", database[i].Valore);
    printf("------------------------------------------\n");
  }
}

void upload_file(struct calciatore database[], char *nomefile, int n) {
  FILE *fp = fopen(nomefile, "w");

  for (int i = 0; i < n; i++) {
    fprintf(fp, "--------------%d---------------\n",i);
    fprintf(fp, "Nome: %s \n", database[i].Nome);
    fprintf(fp, "Cognome %s \n", database[i].Cognome);
    fprintf(fp, "Anno di Nascita %d\n", database[i].AnnodiNascita);
    fprintf(fp, "Numero Maglia %d\n", database[i].NumeroMaglia);
    fprintf(fp, "Valore %d MLN €\n", database[i].Valore);
    fprintf(fp, "------------------------------\n");
  }
  fclose(fp);
}

int find_calciatore(struct calciatore database[], char *Nome, char *Cognome,
                    int n) {
  int c = -1;
  for (int i = 0; i < n; i++) {
    if (strcmp(database[i].Nome, Nome) == 0 &&
        strcmp(database[i].Cognome, Cognome) == 0)
      c = i;
  }
  return c;
}

int main(void) {
  int scelta, scelta2, n = 0, mem;
  char FNome[20], FCognome[20];
  struct calciatore *database = malloc(sizeof(struct calciatore));
  printf("DATABASE VUOTO Carica primo Calciatore\n");
  database[n] = add_calciatore();
  n++;

  while (scelta != -1) {
    printf("\n");
    printf("1. Inserisci calciatore\n");
    printf("2. Stampa\n");
    printf("3. Salva Calciatori su FILE\n");
    printf("4. Cerca Calciatore\n");
    printf("0. ESCI\n");
    printf("Seleziona Scelta: ");
    scanf("%d", &scelta);

    switch (scelta) {
    case 1:
      n++;
      database = realloc(database, n * sizeof(struct calciatore));
      database[n - 1] = add_calciatore();
      break;

    case 2:
      stampa(database, n);
      break;

    case 3:
      upload_file(database, "file.txt", n);
      break;

    case 4:
      scelta=0;
      printf("Inserisci Nome: ");
      scanf("%s", FNome);
      printf("Inserisci Cognome: ");
      scanf("%s", FCognome);
      if (find_calciatore(database, FNome, FCognome, n) != -1)
        printf("\n-Trovato-\n");
      else
        printf("\n! NON Trovato !\n");

      while (scelta2 != -1) {
        printf("1. Rimuovi Calciatore\n");
        printf("2. Modifica Calciatore\n");
        printf("3. ESCI\n");
        printf("Inserisci Scelta: ");
        scanf("%d", &scelta2);

        switch (scelta2) {
        case 1:
          mem = find_calciatore(database, FNome, FCognome, n);
          for (int i = mem; i < n - 1; i++) {
            database[i] = database[i + 1];
          }
          n--;
          database = realloc(database, n * sizeof(struct calciatore));
          mem=0;
          break;
        case 2:
          if(mem==0){
          printf("Inserisci Nome: ");
          scanf("%s", FNome);
          printf("Inserisci Cognome: ");
          scanf("%s", FCognome);
          mem = find_calciatore(database, FNome, FCognome, n);
          }
          printf("Inserisci Nome: ");
          scanf("%s", database[mem].Nome);
          printf("Inserisci Cognome: ");
          scanf("%s", database[mem].Cognome);
          printf("Inserisci Anno di Nascita: ");
          scanf("%d", &database[mem].AnnodiNascita);
          do {
            printf("Inserisci Numero di Maglia: ");
            scanf("%d", &database[mem].NumeroMaglia);
          } while (database[mem].NumeroMaglia <= 1 &&
                   database[mem].NumeroMaglia >= 99);
          printf("Inserisci Valore (MLN): ");
          scanf("%d", &database[mem].Valore);
          break;
        case 3:
          scelta2 = -1;
          break;
        default:
          printf("2.. Numero errato\n");
        }
      }
      break;
    case 0:
      scelta = -1;
      break;
    default:
      printf("Numero errato\n");
    }
  }
}
