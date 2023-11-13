#include "sortAlgs.h"

#include <stdio.h>
#include <stdlib.h>

void printArr(int A[], int N);

int main(int argc, char *argv[]) {
  int vals[] = {6, 3, 9, 10, 15, 6, 8, 12, 3, 6};
  int N = sizeof(vals) / sizeof(int);

  algs_countSort(vals, N);
  printArr(vals, N);
}

void printArr(int A[], int N) {
  printf("Printing array...\n");
  for (int i = 0; i < N; i++) {
    printf("%d ", A[i]);
  }
  printf("\n\n");
}
