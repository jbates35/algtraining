#include "heap.h"

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int vals[] = {1, 3, 5, 7, 9, 10, 8, 6, 4, 2};
  int N = sizeof(vals) / sizeof(int);
  printf("Sorting heap with vals:\n");
  heap_print(vals, N);
  heap_sort(vals, N);
  heap_print(vals, N);
}
