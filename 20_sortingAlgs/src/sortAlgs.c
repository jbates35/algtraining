#include "sortAlgs.h"

void algs_bubbleSort(int *A, int N) {
  if (A == NULL) {
    fflush(stdout);
    fprintf(stderr, "\nError: Null pointer in algs_bubbleSort\n");
    return;
  }

  for (int i = 0; i < N - 1; i++) {
    for (int j = i; j < N - 1; j++) {
      return;
    }
  }
}

void swap(void *x, void *y, size_t varSize) {
  void *temp = malloc(varSize);
  memcpy(temp, y, varSize);
  memcpy(y, x, varSize);
  memcpy(x, temp, varSize);
  free(temp);
}
