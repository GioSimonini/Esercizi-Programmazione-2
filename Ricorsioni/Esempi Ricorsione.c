#include <stdio.h>

#define TRUE 1
#define FALSE 0


  int moltiplica(int x,int y){
      if(y<=1){
        return x; //CASO BASE  
      }else{
    return x+moltiplica(x,y-1); //PASSO RICORSIVO
    }
  }


  int carattere(char *str, char ch){
    if(*str=='\0')
      return FALSE;
    
    if(*str==ch)
        return TRUE;
    
    carattere(++str, ch);
  }


  void divisori(int n,int div){
      
    if(n % div ==0)
      printf("%d, %d ==0 \n",n,div);

    if(div==1){
      return;
    }
    
    divisori(n,div-1); //oppure parto da 1 e vado a salire 
  }


int main(void) {
  printf("---------------1---------------\n");
  int x,y,m;
  printf("Inserisci n1\t");
  scanf("%d",&x);
  printf("Inserisci n2\t");
  scanf("%d",&y);
  m=moltiplica(x,y);
  printf("\t%d * %d = %d\n",x,y,m);

 printf("---------------2---------------\n");
  char ch='a';
  char *str="this is a string";
  int res=carattere(str,ch);
  if(res)
  printf("c'è");  
  else
  printf("no");

printf("\n---------------3---------------\n");
  int n=50;
  divisori(n, n);
  
  
  return 0;
}
