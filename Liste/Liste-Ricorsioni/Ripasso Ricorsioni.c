#include <stdio.h>
#include <stdlib.h>

struct nodo {
  int data;
  struct nodo *next;
};

struct nodo *buildlist(int n) {
  struct nodo *head = malloc(sizeof(struct nodo));
  struct nodo *tail = head;
  printf("Inserisci valore: ");
  scanf("%d", &head->data);

  for (int i = 0; i < n - 1; i++) {
    struct nodo *newNode = malloc(sizeof(struct nodo));
    printf("Inserisci valore: ");
    scanf("%d", &newNode->data);
    tail->next = newNode;
    tail = newNode;
  }
  tail->next = NULL;

  return head;
}

void printlist(struct nodo *head) {
  while (head != NULL) {
    printf("%d -> ", head->data);
    head = head->next;
  }
  printf("NULL\n");
}

int occmax(struct nodo *head, int max, int n) {
  if (head == NULL)
    return n;

  if (head->data > max) {
    max = head->data;
    return occmax(head->next, max, 1);
  } else if (head->data == max) {
    return occmax(head->next, max, n + 1);
  } else {
    return occmax(head->next, max, n);
  }
}

int ceckcresc(struct nodo *head) {
  if (head == NULL)
    return 1;
  if (head->next == NULL)
    return 1;

  if (head->data < head->next->data)
    return ceckcresc(head->next);
  else
    return 0;
}

int ceckposeq(struct nodo *head1, struct nodo *head2) {
  if (head1 == NULL || head2 == NULL)
    return 0;

  if (head1->data == head2->data)
    return 1 + ceckposeq(head1->next, head2->next);
  else
    return ceckposeq(head1->next, head2->next);
}

struct nodo *lis3(struct nodo *head1, struct nodo *head2, int n) {
  struct nodo *temp;
  int diff;
  if (head1 != NULL && head2 != NULL) {
    diff = head1->data - head2->data;
    if (diff % n == 0) {
      temp = malloc(sizeof(struct nodo));
      temp->data = diff;
      temp->next = lis3(head1->next, head2->next, n + 1);
      return temp;
    } else
      return lis3(head1->next, head2->next, n + 1);
  } else
    return NULL;
}

struct nodo *listamultipli(struct nodo *head1, struct nodo *head2, int n) {
  struct nodo *head3;
  if (head1 != NULL && head2 != NULL) {
    if ((head1->data + head2->data) % n == 0) {
      head3 = malloc(sizeof(struct nodo));
      head3->data = head1->data * head2->data;
      head3->next = listamultipli(head1->next, head2->next, n + 1);
      return head3;
    } else
      return listamultipli(head1->next, head2->next, n + 1);
  } else
    return NULL;
}

struct nodo *duplica(struct nodo *head) {
  struct nodo *dup;
  if (head != NULL) {
    dup = malloc(sizeof(struct nodo));
    dup->data = head->data;
    dup->next = duplica(head->next);
    return dup;
  }else return NULL;
}

int main(void) {
  struct nodo *head = buildlist(7);
  printlist(head);
 struct nodo *head2 = buildlist(10);
  printlist(head2);

  printf("Numero di ripetizioni del massimo: %d\n", occmax(head, 0, 0));
  if (ceckcresc(head) == 1) {
    printf("La lista è ordinata in modo crescente\n");
  } else
    printf("La lista NON è ordinata in modo crescente\n");

  printf("Valori uguali e nella stessa posizione delle 2 Liste: %d\n",
         ceckposeq(head, head2));

  struct nodo *temp = lis3(head, head2, 1);
  printlist(temp);

  struct nodo *head4 = listamultipli(head, head2, 1);
  printlist(head4);

  struct nodo *headdup= duplica(head);
  printlist(headdup);
}
