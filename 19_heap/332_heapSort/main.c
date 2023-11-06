#include "heap.h"

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  HeapArray heap;
  heap_init(&heap, 10);

  int vars[] = {1, 4, 2, 6, 10, 9, 3, 14, 16, 15};

  for (int i = 0; i < sizeof(vars) / sizeof(int); i++) {
    heap_insert(&heap, vars[i]);
    printf("Adding %d\nHeap: ", vars[i]);
    heap_print(&heap);
    printf("\n");
  }
}
