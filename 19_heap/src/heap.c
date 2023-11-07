#include "heap.h"
#include <memory.h>

void swap(void *x, void *y, size_t varSize);
int isMarsenne(int x);

void heap_print(int A[], int N) {
  for (int i = 0; i < N; i++) {
    printf("%d ", A[i]);
    if (isMarsenne(i + 1))
      printf(", ");
  }
  printf("\n");
}

// From perspective of heapify
void heap_insert(int A[], int N, int n) {
  while (n < (N / 2)) {
    int compareInd = (n + 1) * 2 - 1;
    int compareVal = A[compareInd];
    if ((compareInd + 1) < N && A[compareInd + 1] > compareVal) {
      compareInd++;
      compareVal = A[compareInd];
    }
    if (A[n] > compareVal)
      break;
    swap(&A[n], &A[compareInd], sizeof(int));
    n = compareInd;
  }
}

void heap_delete(int A[], int m) {}

void heap_create(int A[], int N) {
  for (int i = N / 2 - 1; i >= 0; i--) {
    heap_insert(A, N, i);
  }
}

void heap_sort(int A[]) {}

void swap(void *x, void *y, size_t varSize) {
  void *temp = malloc(varSize);
  memcpy(temp, y, varSize);
  memcpy(y, x, varSize);
  memcpy(x, temp, varSize);
  free(temp);
}

int isMarsenne(int x) {
  while (x % 2 == 1)
    x = x >> 1;

  if (x == 0)
    return 1;
  return 0;
}
