#include "heap.h"
#include <memory.h>

void swap(void *x, void *y, size_t varSize);
int isMarsenne(int x);

// From perspective of heapify
void heap_insert(int A[], int n) {}
void heap_delete(int A[], int m) {}
void heap_create(int A[]) {}
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
