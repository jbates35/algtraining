#include "generatedarray.h"
#include "sortAlgs.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void testSpeed(void (*algFn)(int *, int), int A[], int N, char *algName);
int isSorted(int A[], int N);

int main(int argc, char *argv[]) {
  int N = sizeof(genArr) / sizeof(int);

  void (*algFns[])(int *, int) = {algs_bubbleSort,        algs_insertionSort,
                                  algs_selectionSort,     algs_quickSort,
                                  algs_mergeSortI,        algs_mergeSortR,
                                  algs_countSort,         algs_radixSort,
                                  algs_radixSort_altered, algs_shellSort};
  char *algNames[] = {"Bubble Sort", "Insertion Sort", "Selection Sort",
                      "Quick Sort",  "Merge Sort I",   "Merge Sort R",
                      "Count Sort",  "Radix Sort",     "Radix Sort Alt",
                      "Shell Sort"};

  for (int i = 0; i < sizeof(algFns) / sizeof(algFns[0]); i++) {
    int *vars = malloc(sizeof(genArr));
    for (int j = 0; j < N; j++) {
      vars[j] = genArr[j];
    }
    testSpeed(algFns[i], vars, N, algNames[i]);
    printf("Is sorted? %s\n", isSorted(vars, N) ? "Yes" : "No");
    free(vars);
  }
}

void testSpeed(void (*algFn)(int *, int), int A[], int N, char *algName) {
  clock_t start, end;
  double cpu_time_used;

  start = clock();
  algFn(A, N);
  end = clock();

  cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC * 1000000;
  printf("%s: %f us\n", algName, cpu_time_used);
}

int isSorted(int A[], int N) {
  for (int i = 0; i < N - 1; i++) {
    if (A[i] > A[i + 1])
      return 0;
  }
  return 1;
}
