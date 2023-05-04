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

float mediad_list(struct nodo *head){
  float media=0.0;
  int x=0;
  while (head != NULL){
    media +=head -> data;  
    head=head->next;
    x++;
  }
  media=media/x;

  return media;
}

int sumlis_rt(struct nodo *lis, int ris) {

  if (lis != NULL) {
      ris+=lis->data; 
  return sumlis_rt(lis->next,ris);
  }
  return ris;
}


int main(int argc, char *argv[]) {
  
  if(argc !=2){
    printf("ERROR NUMBER OF ARGUMENTS");
    exit(-1);
  }

  int n= atoi(argv[1]);
  struct nodo *head=buildlist(n);
  print_list(head);
  printf("Media: %f", mediad_list(head));
  printf("somma: %d",sumlis_rt(head, 0));

  FILE *fp;
  fp=fopen("file.txt", "w");

  for(int i=0; i<n;i++){
    fprintf(fp, "%d\n", head ->data);
      head=head-> next;
  }
  
  fclose(fp);
  
}
