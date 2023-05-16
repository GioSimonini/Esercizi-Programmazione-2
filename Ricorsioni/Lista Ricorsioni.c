#include <stdio.h>
#include <stdlib.h>

struct nodo {
  int data;
  struct nodo *next;
};

struct nodo *buildlist(struct nodo *head, int n) {

  struct nodo *tail = head;
  printf("Inserisci numero: ");
  scanf("%d",&head->data);

  for (int i = 0; i < n - 1; i++) {
    int n=0;
    struct nodo *temp = malloc(sizeof(struct nodo));
    printf("Inserisci numero: ");
    scanf("%d",&n);
    temp->data=n;
    tail->next = temp;
    tail = temp;
  }
  tail->next = NULL;

  return head;
}

void print_list(struct nodo *head) {

  while (head != NULL) {
    printf("-> %d ", head->data);
    head = head->next;
  }
  printf("\n");
}

int conta_lista(struct nodo *head, int p) {
  if (head == NULL)
    return p;

  return conta_lista(head->next, p + 1);
}
/*
struct nodo *inverti_lista(struct nodo *head)
{
  if(head-> next==NULL){
    struct nodo *head2=malloc(sizeof(struct nodo));

  if(head==NULL){
      printf("ERR");
      return NULL;
  }

  head2->data=head->data;
  return head2;
  }
  struct nodo *head3=malloc(sizeof(struct nodo));
  tailinsert(head3,head->data);
  return head3;
}
*/
void inserimento(struct nodo *head, int pos, int x) {

  if (head == NULL) {
    return;
  }

  if (pos == 0) {
    struct nodo *temp = malloc(sizeof(struct nodo));
    temp->data = x;
    temp->next = head->next;
    head->next = temp;
    return;
  }

  inserimento(head->next, pos - 1, x);
}

int cerca(struct nodo *head, int k) {
  if (head == NULL)
    return 0;
  if (k == 0) {
    return head->data;
  } else
    return cerca(head->next, k - 1);
}

struct nodo *newlist(struct nodo *head, int x) {

  if (head == NULL) { return NULL;
  }

  if (head->data < x) {
    struct nodo *temp = malloc(sizeof(struct nodo));
    temp->data = head->data;
    temp->next = newlist(head->next, x);
    return temp;
      }
   else
      return newlist(head->next, x);
    }
  

int main(void) {
  struct nodo *head = malloc(sizeof(struct nodo));
  buildlist(head, 5);
  print_list(head);
  printf("es1: Lunghezza lista: %d \n", conta_lista(head, 0));

  // struct nodo *head2 = malloc(sizeof(struct nodo));
  //  inverti_lista(head);
  int x,pos;
  printf("Inserisci elemento da aggiungere\t");
  scanf("%d",&x);
  printf("Inserisci in che posizione aggiungerlo\t");
  scanf("%d",&pos);
  inserimento(head, pos, x);
  print_list(head);

  int k;
  printf("Inserisci la posizone dell' elemento da cercare\t");
  scanf("%d",&k);
  printf("L'elemento in posizione %d è : %d \n",k, cerca(head, k));


  printf("-  Stampa elementi della lista >20  -\n");
  struct nodo *head2 = NULL;
  head2 = newlist(head, 20);
  print_list(head2);

  return 0;
}
