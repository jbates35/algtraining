#include "sortAlgs.h"

#include <stdio.h>
#include <stdlib.h>

void printArr(int A[], int N);

int main(int argc, char *argv[]) {
  int vals[] = {237, 146, 259, 348, 152, 163, 235, 48, 36, 62};
  int N = sizeof(vals) / sizeof(int);

  algs_radixSort(vals, N);
  printArr(vals, N);
}

void printArr(int A[], int N) {
  printf("Printing array...\n");
  for (int i = 0; i < N; i++) {
    printf("%d ", A[i]);
  }
  printf("\n\n");
}
