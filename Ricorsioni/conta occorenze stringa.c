#include <stdio.h>
#include <stdlib.h>
int contaoc(char *s,char c,int oc){

  if(*s=='\0')
    return oc;
  
  if(*s==c)
    oc++;
  
  return contaoc(s+1,c,oc);
}


int main(void) {
  char s[]={"ciao come stai ciccio?"};
  printf("il carattere %c, si trova %d volte",'c',contaoc(s,'c',0));
}
