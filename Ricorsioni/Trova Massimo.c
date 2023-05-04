#include <stdio.h>

int maxarr(int v[], int p, int leng, int max) {

  if (p == leng)
    return max;

  if (v[p] > max)
    max = v[p];

  return maxarr(v, p + 1, leng, max);
}

int main(void) {
  int v[6] = {1, 6, 3, 9, 11, 2};
  printf("Max array %d: ", maxarr(v, 0, 6, 0));
}
