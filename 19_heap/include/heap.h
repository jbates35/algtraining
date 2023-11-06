#include <stdio.h>
#include <stdlib.h>

typedef struct HeapArray {
  int size;
  int length;
  int *A;
} HeapArray;

void heap_init(HeapArray *heap, int size);
void heap_free(HeapArray *heap);
void heap_print(HeapArray *heap);
void heap_insert(HeapArray *heap, int val);

int checkMarsenne(int x);
