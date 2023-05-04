
#include <stdio.h>
#include <stdlib.h>


struct nodo {
  int data;
  struct nodo *next;
};

struct nodo* buildlist(int n){
  struct nodo *head= malloc(sizeof( struct nodo));
  struct nodo *tail= head;
  head -> data = rand() % 51;
  
  for(int i=0; i<n-1; i++){
      struct nodo *temp= malloc(sizeof(struct nodo));
      temp -> data= rand() % 51; 
      tail ->next= temp;
      tail=temp;   
  }
  tail -> next= NULL;

  return head;
}

void print_list(struct nodo *head){

  while(head != NULL){
    printf(" %d ->", head -> data);
    head=head->next;
  }
  printf("\n");
}


int printn_rt(struct nodo *head, int l, int pos) {
  if (head == NULL) {
    return 0;
  }
    if (pos <l) 
      return head->data+printn_rt(head->next,l,pos+1);
      else
    return 0;
  }
  


int main(void) {
  struct nodo *head=buildlist(5);
  print_list(head);
  printf("somma: %d",printn_rt(head,3,0));
  
}
