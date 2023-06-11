#include <stdio.h>
#include <stdlib.h>

int trovamax(int *v, int dim) {
  int max = 0;

  for (int i = 0; i < dim; i++) {
    if (i == 0)
      max = v[i];
    else if (v[i] > max)
      max = v[i];
  }
  return max;
}

int trovamin(int *v, int dim) {
  int min = v[0];
  for (int i = 0; i < dim; i++) {
    if (v[i] < min)
      min = v[i];
  }
  return min;
}

float trovamedia(int *v, int dim) {
  int sum;
  float media;
  for (int i = 0; i < dim; i++) {
    sum += v[i];
  }
  media = sum / dim;

  return media;
}

int main(int argc, char *argv[]) {
  FILE *fp;
  int x,num=0;
  fp = fopen(argv[1], "r");
  int *v = NULL;
  
  while (!feof(fp)) {
    
    fscanf(fp, "%d", &x);
    printf("%d \n", num);
    if(v==NULL)
      v=malloc(sizeof(int));
    else{

      v = realloc(v,sizeof(int)*(num+1));
    }
    v[num]=x;
    num++;
    
  }
  fclose(fp);
  int max, min;
  float media;
  max = trovamax(v, num);
  min = trovamin(v, num);
  media = trovamedia(v, num);

  for(int i=0; i<num; i++){
    printf("%d\t",v[i]);
  }
  printf("\n");
  
  printf("Massimo: %d \n", max);
  printf("Minimo: %d \n", min);
  printf("Media: %f \n", media);

  return 0;
}
