#include "sortAlgs.h"
#include "helpFuncs.h"

#include <math.h>

void algs_bubbleSort(int *A, int N) {
  if (A == NULL) {
    fflush(stdout);
    fprintf(stderr, "\nError: Null pointer in algs_bubbleSort\n");
    return;
  }

  for (int i = N - 1; i > 0; i--) {
    int isSorted = 1;

    for (int j = 1; j <= i; j++) {
      if (A[j] < A[j - 1]) {
        swap(&A[j - 1], &A[j], sizeof(int));
        isSorted = 0;
      }
    }

    if (isSorted)
      return;
  }
}

void algs_insertionSort(int *A, int N) {
  if (A == NULL) {
    fflush(stdout);
    fprintf(stderr, "\nError: Null pointer in algs_insertionSort\n");
    return;
  }

  for (int i = 1; i < N; i++) {
    int insInd = 0;
    int newVal = A[N - 1];
    for (; insInd < i; insInd++) {
      if (newVal < A[insInd])
        break;
    }
    for (int j = N - 1; j > insInd; j--)
      A[j] = A[j - 1];
    A[insInd] = newVal;
  }
}

void algs_selectionSort(int *A, int N) {
  if (A == NULL) {
    fflush(stdout);
    fprintf(stderr, "\nError: Null pointer in algs_selectionSort\n");
    return;
  }

  for (int i = 0; i < N - 1; i++) {
    int minVal = A[i];
    int k = i;

    for (int j = i + 1; j < N; j++) {
      if (minVal > A[j]) {
        minVal = A[j];
        k = j;
      }
    }

    swap(&A[i], &A[k], sizeof(int));
  }
}
