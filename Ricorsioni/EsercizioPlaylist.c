#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct brano {
  char *titolo;
  char *autore;
  int durata;
  struct brano *next;
};

struct brano *build_playlist(int n,int i ,char *titoli[],char *autori[], int durata[]) {
  if (i == n)
    return NULL;

  struct brano *head = malloc(sizeof(struct brano));
  head->titolo=titoli[i];
  head->autore=autori[i];
  head->durata=durata[i];
  head->next = build_playlist(n,i+1,titoli,autori,durata);
  return head;
}

void printlis(struct brano *head) {
  while (head != NULL) {
    printf("--------Brano---------\n");
    printf("Titolo: %s\n", head->titolo);
    printf("Autore: %s\n", head->autore);
    printf("Durata: %d sec\n", head->durata);
    head = head->next;
  }
  printf("\n");
}

struct brano *skip_to(struct brano *head,char titolo[]){
  if(head==NULL)
    return NULL;

  if(strcmp(head->titolo,titolo)==0)
    return head;

  struct brano *next= head->next;
  free(head);
  
  return skip_to(next,titolo);
}

int playlist_len (struct brano *head){
  if(head==NULL)
    return 0;

  return head->durata+playlist_len(head->next);
}

struct brano *delete_song (struct brano *head, char titolo[]){
  if(head==NULL)
    return NULL;
  
  if(strcmp(head->titolo, titolo)==0){
    struct brano *newNode=head->next;
    free(head);
    return newNode;
  }
  head->next= delete_song(head->next, titolo);

  return head;
}
int main(void) {
  char *titoli[] = {"Wake me up", "Given Up", "Sweet Child o' Mine",
                    "Back in Black"};
  char *autori[] = {"Green Day", "Linkin Park", "Guns'n'Roses", "ACDC"};
  int durata[] = {180, 240, 300, 220};
  struct brano *head = build_playlist(4,0,titoli,autori,durata);
  printlis(head);

  head=skip_to(head,"Given Up");
  printlis(head);
  
  printf("Durata totale: %d sec o %d minuti\n", playlist_len(head), playlist_len(head)/60);
  

  delete_song(head, "Sweet Child o' Mine");
  printlis(head);
  
  return 0;
}
