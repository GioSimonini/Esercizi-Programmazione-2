#include <stdio.h>
#include <stdlib.h>

struct nodo {
  int data;
  struct nodo *next;
};

struct nodo *buildlist() {
  int x;
  struct nodo *head = malloc(sizeof(struct nodo));
  struct nodo *tail = head;
  printf("Inserisci numero: ");
  scanf("%d", &head->data);
  if (head->data == -1) {
    head = NULL;
    return head;
  }
  while (x != -1) {
    printf("Inserisci numero: ");
    scanf("%d", &x);
    if (x != -1) {
      struct nodo *temp = malloc(sizeof(struct nodo));
      temp->data = x;
      tail->next = temp;
      tail = temp;
      tail->next = NULL;
    }
  }
  return head;
}
void printlist(struct nodo *head) {
  while (head != NULL) {
    printf("%d ->", head->data);
    head = head->next;
  }
  printf("NULL\n");
}

float ES1(struct nodo *head, int k) {
  float m;
  for (int i = 0; i < k; i++) {
    if (head != NULL) {
      m += head->data;
      head = head->next;
    }
  }
  m = m / k;
  return m;
}
// Coplessità Tempo: O(k) dove k è l'imput dei nodi da calcolare
// Coplessità Spazio: O(1)

struct nodo *ES2(struct nodo *head, int k, int pos) {
  if (head == NULL)
    return NULL;
  if (head->data == k && pos % 2 == 0) {
    struct nodo *temp = head->next;
    free(head);
    return temp;
  }
  head->next = ES2(head->next, k, pos + 1);
  return head;
}
// Coplessità Tempo: O(n) con n numero di nodi nella lista
// Coplessità Spazio: O(n) con n numero di nodi nella lista



int main(void) {
  struct nodo *head = buildlist();
   printlist(head);

   int k;
   printf("Inserisci K: ");
   scanf("%d", &k);
   printf("Media primi %d nodi: %f\n", k, ES1(head, k));

   printf("Inserisci K da cancellare: ");
   scanf("%d", &k);
   ES2(head,k,0);
   printlist(head);
}
