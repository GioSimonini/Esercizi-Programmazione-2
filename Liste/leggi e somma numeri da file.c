#include <stdio.h>
#include <stdlib.h>

struct nodo {
  int data;
  struct nodo *next;
};

struct nodo *buildlist(char nomefile[]) {
  FILE* fp;
  int n;
  fp = fopen(nomefile, "r");
  
  struct nodo *head = malloc(sizeof(struct nodo));
  struct nodo *tail = head;
  
  while(fscanf(fp, "%d", &n) != EOF){
    struct nodo *temp = malloc(sizeof(struct nodo));
    fscanf(fp, "%d", &n);
    temp->data=n;
    tail->next = temp;
    tail = temp;
    }
  tail->next = NULL;
  fclose(fp);
  return head;
}

void list_print(struct nodo *head)
{
  while(head!=NULL){
     printf("%d -> ", head->data);
      head=head->next;
  }
}

int list_sum_even(struct nodo *head)
{
  int sum=0;
  for(;head != NULL; head=head->next->next)
    {
                                                        /*while (head != NULL){
                                                                  head=head-> next-> next;
                                                                 }
                                                        */
    sum+= head-> data;
    }

return sum;  
}
int main(int argc, char* argv[]) {
  if(argc!=2)
    exit(-1);
  struct nodo *head;
  head = buildlist(argv[1]); 
  list_print(head);
  printf("la somma e': %d", list_sum_even(head));
  
  return 0; 

}
