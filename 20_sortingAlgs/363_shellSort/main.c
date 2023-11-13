#include "sortAlgs.h"

#include <stdio.h>
#include <stdlib.h>

void printArr(int A[], int N);

int main(int argc, char *argv[]) {
  int vals[] = {9, 5, 16, 8, 13, 6, 12, 10, 4, 2, 3};
  int N = sizeof(vals) / sizeof(int);

  algs_shellSort(vals, N);
  printArr(vals, N);
}

void printArr(int A[], int N) {
  printf("Printing array...\n");
  for (int i = 0; i < N; i++) {
    printf("%d ", A[i]);
  }
  printf("\n\n");
}
