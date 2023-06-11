#include <stdio.h>
#include <stdlib.h>

struct nodo {
  int data;
  struct nodo *next;
};

struct nodo *buildlist(int n) {
  struct nodo *head = malloc(sizeof(struct nodo));
  head->data = rand() % 10;
  head->next = NULL;
  for (int i = 0; i < n - 1; i++) {
    struct nodo *temp = malloc(sizeof(struct nodo));
    temp->data = rand() % 10;
    temp->next = head;
    head = temp;
  }
  return head;
}

int dot_prod(struct nodo *lis1, struct nodo *lis2) {
  int sum = 0;

  while (lis1 != NULL) {
    sum += lis1->data * lis2->data;
    lis1 = lis1->next;
    lis2 = lis2->next;
  }
  return sum;
}
int in_lista(struct nodo *head, int val) {
    while (head != NULL) {
        if (head->data == val)
            return 1;
        head = head->next;
    }
    return 0;
}
struct nodo *list_duplicate(struct nodo *head, int n) {
  struct nodo *dup = NULL;

  while(head !=NULL){
    if(in_lista(head->next, head->data)){
        if (dup == NULL) {
          dup = malloc(sizeof(struct nodo));
          dup->data = head->data;
          dup->next = NULL;
        } else{
          struct nodo *tail = dup;
          while (tail->next != NULL)
                    tail = tail->next;
          
         struct nodo *new_node = malloc(sizeof(struct nodo));
                new_node->data = head->data;
                new_node->next = NULL;

                tail->next = new_node;
        }
      }
    head = head->next;
  }
  return dup;
}

void list_print(struct nodo *head) {
  while (head != NULL) {
    printf("%d -> ", head->data);
    head = head->next;
  }
  printf("NULL \n");
}

int main(void) {
  struct nodo *head = buildlist(10);
  list_print(head);
  struct nodo *head2 = buildlist(10);
  list_print(head2);
  printf("Prodotto scalare: %d\n", dot_prod(head, head2));

  struct nodo *dup = list_duplicate(head, 10);
  list_print(dup);
  
  free(head);
  free(head2);
}
