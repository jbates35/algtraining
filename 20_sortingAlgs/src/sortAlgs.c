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
    int newVal = A[i];
    int j = i - 1;

    for (; j != -1 && A[j] > newVal; j--)
      A[j + 1] = A[j];

    A[j + 1] = newVal;
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

void quickSortR(int *A, int m, int n);
void algs_quickSort(int *A, int N) {
  if (A == NULL) {
    fflush(stdout);
    fprintf(stderr, "\nError: Null pointer in algs_quickSort\n");
    return;
  }

  if (N > 0)
    quickSortR(A, 0, N);
}

void quickSortR(int *A, int m, int n) {
  if (n - m <= 1)
    return;

  int pivot = A[m];

  int i = m + 1;
  int j = n - 1;

  do {
    if (A[i] > pivot && A[j] <= pivot)
      swap(&A[i], &A[j], sizeof(int));

    if (A[i] <= pivot)
      i++;
    if (A[j] > pivot)
      j--;
  } while (i <= j);

  swap(&A[m], &A[j], sizeof(int));

  quickSortR(A, m, j);
  quickSortR(A, i, n);
}
