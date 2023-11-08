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
    int maxVal = A[0];
    int maxValInd = 0;
    int isSorted = 1;

    for (int j = 1; j <= i; j++) {
      if (maxVal < A[j]) {
        maxVal = A[j];
        maxValInd = j;
      } else {
        isSorted = 0;
      }
    }

    if (isSorted)
      return;

    swap(&A[i], &A[maxValInd], sizeof(int));
  }
}
