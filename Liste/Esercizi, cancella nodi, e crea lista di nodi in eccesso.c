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
    printf("%d ->", head->data);
    head = head->next;
  }
  printf("NULL\n");
}

int scorri(int x, struct nodo *head) {
  int c = 1;
  while (head != NULL) {
    if (head->data == x) {
      c++;
      head = head->next;
    } else {
      return c;
    }
  }
  return c;
}

int countseq(struct nodo *head) {
  int seq = 0, x;
  while (head != NULL) {
    x = scorri(head->data, head->next);
    if (x > seq)
      seq = x;
    head = head->next;
  }
  return seq;
}
struct nodo *newList(struct nodo *head1, struct nodo *head2,int c1,int c2) {
  if (c2 > c1) {
    for (int i = 0; i < c1; i++) {
      head2 = head2->next;
    }
    struct nodo *head3 = malloc(sizeof(struct nodo));
    struct nodo *tail = head3;
    head3->data = head2->data;
    head2 = head2->next;
    while (head2 != NULL) {
      struct nodo *temp = malloc(sizeof(struct nodo));
      temp->data = head2->data;
      tail->next = temp;
      tail = temp;
      head2 = head2->next;
    }
    tail->next = NULL;
    return head3;
  } else {
    for (int i = 0; i < c2; i++) {
      head1 = head1->next;
    }
    struct nodo *head3 = malloc(sizeof(struct nodo));
    struct nodo *tail = head3;
    head3->data = head1->data;
    head1 = head1->next;
    while (head1 != NULL) {
      struct nodo *temp = malloc(sizeof(struct nodo));
      temp->data = head1->data;
      tail->next = temp;
      tail = temp;
      head1 = head1->next;
    }
    tail->next = NULL;
    return head3;
  }
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

struct nodo *delnodeval(struct nodo *head, int k) {
  if (head == NULL)
    return NULL;
  
  if (head->data==k) {  
    struct nodo *newNode = head->next;
    free(head);
    return newNode;
  }
  head->next = delnodeval(head->next,k);

  return head;
}

void dellist(struct nodo *head) {
  if (head == NULL)
    return;

  dellist(head->next);
  free(head);
}


int main(void) {
  
  printf("Lista1\n");
  struct nodo *head = buildlist(7);
  printf("Lista2\n");
  struct nodo *head2 = buildlist(10);
  
  printlist(head);
  printlist(head2);

  printf("Lista3\n");
  struct nodo *head3 = newList(head, head2,7,10);
  printlist(head3);
  
  printf("\n");
  printf("La sequenza più lunga: %d\n", countseq(head));

  delnode(head, 3);
  printf("Cancellazione nodo pozione 4 (Lista 1)\n");
  printlist(head);

  delnodeval(head2, 9);
  printf("Cancellazione nodo valore 9 (Lista 1)\n");
  printlist(head2);
}
