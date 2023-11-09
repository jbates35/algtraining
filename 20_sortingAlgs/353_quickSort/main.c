#include "sortAlgs.h"

#include <stdio.h>
#include <stdlib.h>

void printArr(int A[], int N);

int main(int argc, char *argv[]) {
  int vals[] = {50, 20, 40, 5, 25, 15, 45};
  // int vals[] = {1, 3, 5, 9, 11, 13, 15, 17, 19};
  int N = sizeof(vals) / sizeof(int);

  algs_quickSort(vals, N);
  printArr(vals, N);
}

void printArr(int A[], int N) {
  printf("Printing array...\n");
  for (int i = 0; i < N; i++) {
    printf("%d ", A[i]);
  }
  printf("\n\n");
}
