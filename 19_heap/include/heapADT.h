#include <stdio.h>
#include <stdlib.h>

typedef struct HeapArray {
  int size;
  int length;
  int *A;
} HeapArray;

void heapADT_init(HeapArray *heap, int size);
void heapADT_free(HeapArray *heap);
void heapADT_print(HeapArray *heap);
void heapADT_insert(HeapArray *heap, int val);
