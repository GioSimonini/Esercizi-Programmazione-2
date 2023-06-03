#include <stdio.h>
#include <stdlib.h>

struct nodo {
  int data;
  struct nodo *next;
};

struct nodo *buildlist(int n) {
  struct nodo *head = malloc(sizeof(struct nodo));
  struct nodo *tail = head;
  head->data = rand() % 50;

  for (int i = 0; i < n - 1; i++) {
    struct nodo *temp = malloc(sizeof(struct nodo));
    temp->data = rand() % 50;
    tail->next = temp;
    tail = temp;
  }
  tail->next = NULL;

  return head;
}

void printlist(struct nodo *head) {
  printf("\n");
  while (head != NULL) {
    printf("%d -> ", head->data);
    head = head->next;
  }
  printf("NULL \n");
}

void addnode(struct nodo *head, int n, int k, int val) {
  if (head == NULL)
    return;

  if (n == k - 1) {
    struct nodo *newNode = malloc(sizeof(struct nodo));
    newNode->data = val;
    newNode->next = head->next;
    head->next = newNode;
    return;
  }
  return addnode(head->next, n + 1, k, val);
}

int countnode(struct nodo *head) {
  if (head == NULL)
    return 0;
  
  if (head->data % 2 == 1)
    return 1 + countnode(head->next);
  else
    return countnode(head->next);
}

float medianode(struct nodo *head, float media, int n) {
  if (head == NULL) {
    media = media / n;
    return media;
  }

  return medianode(head->next, media + head->data, n++);
}

struct nodo *delnode(struct nodo *head, int k) {

  if (head == NULL)
    return NULL;

  if (k == 0) {
    struct nodo *newNode = head->next;
    free(head);
    return newNode;
  }

  head->next = delnode(head->next, k - 1);

  return head;
}

struct nodo *delnode2(struct nodo *head, int k) { //secondo metodo

  if (head == NULL)
    return NULL;

  if (k == 1) {
    struct nodo *newNode = head->next->next;
    free(head->next);
    head->next= newNode;
    return head;
  }

  head->next = delnode(head->next, k - 1);

  return head;
}



void dellist(struct nodo *head) {
  if (head == NULL)
    return;

  dellist(head->next);
  free(head);
}

int findelement(struct nodo *head, int x) {
  if (head == NULL)
    return 0;

  if (head->data == x)
    return 1 + findelement(head->next, x);
  else
    return findelement(head->next, x);
}
int main(void) {
  float media = 0;
  struct nodo *head = NULL;
  head = buildlist(10);
  printlist(head);
  addnode(head, 0, 5, 99);
  printlist(head);
  printf("\n");
  printf("Nodi dispari :%d\n", countnode(head));
  printf("Media nodi :%f\n", medianode(head, media, 11));
  delnode(head, 3);
  printlist(head);
  // printf("CANCELLAZIONE");
  // dellist(head);
  int x;
  printf("Inserisci elemento da cercare: ");
  scanf("%d", &x);
  if (findelement(head, x) == 1)
    printf("L'elemento è presente nella lista");
  else
    printf("L'elemento non è presente");
}
