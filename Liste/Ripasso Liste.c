#include <stdio.h>
#include <stdlib.h>

struct nodo {

  int data;
  struct nodo *next;
};

struct nodo *bulidist(int n) {
  struct nodo *head = malloc(sizeof(struct nodo));
  struct nodo *tail = head;
  printf("Insericsci dato: ");
  scanf("%d", &head->data);

  for (int i = 0; i < n - 1; i++) {
    struct nodo *newNode = malloc(sizeof(struct nodo));
    printf("Insericsci dato: ");
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

int sumprodx(int x, struct nodo *head) {
  int prod = 0, c = 1;
  while (head != NULL) {
    if (c % x == 0) {
      prod += head->data * c;
    }
    head = head->next;
    c++;
  }
  return prod;
}

int nminusm(struct nodo *head, int n, int m) {
  int sumN = 0, sumM = 0, c = 1;
  while (head != NULL) {
    if (c <= n) {
      sumN += head->data;
    } else if (c <= m) {
      sumM += head->data;
    }
    c++;
    head = head->next;
  }
  return sumN - sumM;
}

int countocc(struct nodo *head, int x) {
  int c = 0, tot = 0;
  int k = 0;
  while (head != NULL) {
    if (head->data == x) {
      c++;
    } else {
      c = 0;
    }
    if (c == 3) {
      tot++;
      c = 0;
    }
    head = head->next;
  }
  return tot;
}

int ifsumlist(struct nodo *head1, struct nodo *head2, int s1, int s2) {
  if (head1 == NULL && head2 == NULL){
    if (s1 > s2)
    return s1;
  else
    return s2;
  }
    
  if (head1 != NULL && head2 != NULL) {
   return ifsumlist(head1->next, head2->next, s1+= head1->data, s2 += head2->data);
  } else if (head1 == NULL) {
   return  ifsumlist(head1, head2->next, s1, s2 += head2->data);
  } else {
    return ifsumlist(head1->next, head2, s1 += head1->data, s2);
  }

  
}
void addnode(struct nodo *head,int x,int n){
  int i=1;
  while(head !=NULL){
    if(head ->data==x && i%n==0){
      struct nodo *newNode=malloc(sizeof(struct nodo));
      newNode->data=head->data;
      newNode->next=head->next;
      head->next=newNode;
      head=head->next->next;
    }else{ 
    head=head->next;
    }i++;
    }
  }



int main(void) {
  struct nodo *head = bulidist(10);
  printlist(head);
  printf("Somma pesata per posizione: %d\n", sumprodx(2, head));
  printf("Differenza somma posizioni n e m: %d\n", nminusm(head, 3, 5));
  printf("Numero occorrenze X3 di 3(x): %d\n", countocc(head, 3));
  struct nodo *head2 = bulidist(4);
  printlist(head2);
  
  printf("Somma dei valori della lista maggiore %d\n",
         ifsumlist(head, head2, 0, 0));

  addnode(head,1,3);
  printlist(head);

}
