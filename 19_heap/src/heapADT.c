#include "heapADT.h"

#include <memory.h>

void swap(void *x, void *y, size_t varSize);
int isMarsenne(int x);

void heapADT_init(HeapArray *heap, int size) {
  if (heap == NULL) {
    fflush(stdout);
    fprintf(stderr, "\nError: Null pointer in heapADT_init\n");
    return;
  }

  heap->size = size;
  heap->A = (int *)malloc(sizeof(int) * heap->size);
}

void heapADT_free(HeapArray *heap) {
  free(heap->A);
  heap->size = -1;
  heap->length = -1;
}

void heapADT_print(HeapArray *heap) {
  if (heap == NULL) {
    fflush(stdout);
    fprintf(stderr, "\nError: Null pointer in heapADT_print\n");
    return;
  }

  for (int i = 0; i < heap->length; i++) {
    printf("%d ", heap->A[i]);
    if (isMarsenne(i + 1))
      printf(", ");
  }
  printf("\n");
}

void heapADT_insert(HeapArray *heap, int val) {
  if (heap == NULL) {
    fflush(stdout);
    fprintf(stderr, "\nError: Null pointer in heapADT_insert\n");
    return;
  }

  if (heap->size == heap->length) {
    heap->size *= 2;
    heap->A = (int *)realloc(heap->A, sizeof(int) * heap->size);
  }

  int i = heap->length++;
  heap->A[i] = val;

  if (i == 0)
    return;

  // Now see if the variable is in its right place
  while (i != 0 && heap->A[i] > heap->A[(i + 1) / 2 - 1]) {
    swap(&heap->A[i], &heap->A[(i + 1) / 2 - 1], sizeof(int));
    i = (i + 1) / 2 - 1;
  }
}

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
