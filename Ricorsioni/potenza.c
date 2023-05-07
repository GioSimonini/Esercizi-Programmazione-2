#include <stdio.h>
#include <stdlib.h>
int pot(int n,int e){
  
  if(e==0)
    return 1;
  else
    return n*pot(n,e-1);
}


int main(void) {
  int n,e;
  
  printf("Inserire numero: ");
  scanf("%d",&n);
  
  printf("\nInserire esponente:");
  scanf("%d",&e);
  printf("\n%d alla %d = %d \n",n,e,pot(n,e));
}
