#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *next;
};

struct node *buildlist( int n) {
  struct node *head=malloc(sizeof(struct node));
  struct node *tail = head;
  printf("Inserisci numero: ");
  scanf("%d",&head->data);

  for (int i = 0; i < n - 1; i++) {
    int n = 0;
    struct node *temp = malloc(sizeof(struct node));
    printf("Inserisci numero: ");
    scanf("%d", &n);
    temp->data = n;
    tail->next = temp;
    tail = temp;
  }
  tail->next=NULL;

  return head;
}

void printlist(struct node *head){

  while(head != NULL){
    printf(" -> %d", head->data);
    head=head->next;
  }
  printf("\n");
}

int prodlist(struct node *head){
  
  if(head==NULL)
    return 1;
  else
    return head->data*prodlist(head->next);
}

int main(void) {
  int n;
  printf("Inserisci lunghezza lista: ");
  scanf("%d",&n);
  struct node *head=buildlist(n);
  printlist(head);
  printf("Prodotto nodi della lista: %d",prodlist(head));
}
