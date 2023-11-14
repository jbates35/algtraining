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
int findMiddle(int *A, int m, int n);

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

  // Use medians of three approach for finding pivot
  swap(&A[m], &A[findMiddle(A, m, n)], sizeof(int));

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

int findMiddle(int *A, int m, int n) {
  int SortA[3] = {A[m], A[(m + n - 1) / 2], A[n - 1]};
  int Inds[3] = {m, (m + n - 1) / 2, n - 1};
  for (int i = 2; i > 0; i--) {
    for (int j = 0; j < i - 1; j++) {
      if (SortA[j] > SortA[j + 1]) {
        swap(&SortA[j], &SortA[j + 1], sizeof(int));
        swap(&Inds[j], &Inds[j + 1], sizeof(int));
      }
    }
  }
  return Inds[1];
}

void mergeWhileSorting(int *A, int lo, int mid, int hi);

void algs_mergeSortI(int *A, int N) {
  if (A == NULL) {
    fflush(stdout);
    fprintf(stderr, "\nError: Null pointer in algs_mergeSortI\n");
    return;
  }

  int multx = 2;
  int i = 0;

  while (multx < N * 2) {
    int lo = i;
    int hi = i + multx - 1;

    if (hi >= N) {
      hi = N - 1;
    }

    int mid = (hi - lo) / 2 + lo;

    mergeWhileSorting(A, lo, mid, hi);

    i += multx;
    if (i >= N) {
      i = 0;
      multx *= 2;
    }
  }
}

void mergeWhileSorting(int *A, int lo, int mid, int hi) {
  int i = lo, j = mid + 1, k = 0;
  int *B = (int *)malloc(sizeof(int) * (hi - lo + 1));

  while (i <= mid && j <= hi) {
    if (A[i] < A[j])
      B[k++] = A[i++];
    else
      B[k++] = A[j++];
  }

  while (i <= mid)
    B[k++] = A[i++];
  while (j <= hi)
    B[k++] = A[j++];

  for (i = 0, j = lo; i < k; i++, j++)
    A[j] = B[i];

  free(B);
}

void mergeSortR(int *A, int m, int n);
void algs_mergeSortR(int *A, int N) {
  if (A == NULL) {
    fflush(stdout);
    fprintf(stderr, "\nError: Null pointer in algs_mergeSortR\n");
    return;
  }

  mergeSortR(A, 0, N - 1);
}

void mergeSortR(int *A, int m, int n) {
  if (n - m < 1)
    return;

  int mid = (n - m) / 2 + m;
  mergeSortR(A, m, mid);
  mergeSortR(A, mid + 1, n);

  mergeWhileSorting(A, m, mid, n);
}

void algs_countSort(int *A, int N) {
  if (A == NULL) {
    fflush(stdout);
    fprintf(stderr, "\nError: Null pointer in algs_countSort\n");
    return;
  }

  if (N == 0)
    return;

  int maxVal = A[0];
  for (int i = 1; i < N; i++) {
    if (maxVal < A[i])
      maxVal = A[i];
  }

  int *tmpArr = calloc(maxVal + 1, sizeof(int));

  for (int i = 0; i < N; i++)
    tmpArr[A[i]]++;

  int newInd = 0;
  for (int i = 0; i < maxVal + 1; i++) {
    while (tmpArr[i] != 0) {
      A[newInd++] = i;
      tmpArr[i]--;
    }
  }

  free(tmpArr);
}

/**** Start of RADIX SORT *****/
typedef struct Bin {
  struct Bin *next;
  int val;
} Bin;

Bin *makeBin(int val);
void addBin(Bin **rootPtr, int val);
int delBin(Bin **rootPtr);

void algs_radixSort(int *A, int N) {
  if (A == NULL) {
    fflush(stdout);
    fprintf(stderr, "\nError: Null pointer in algs_radixSort\n");
    return;
  }

  int maxVal = A[0];
  for (int i = 1; i < N; i++) {
    if (maxVal < A[i])
      maxVal = A[i];
  }

  Bin *bins[16] = {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
                   NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};

  for (int bitsh = 0; (maxVal >> bitsh) != 0; bitsh += 4) {
    // First sort array values into the bins
    for (int i = N - 1; i >= 0; i--)
      addBin(&bins[(A[i] >> bitsh) & 0xF], A[i]);

    // Now pop the bins in order back into the array
    int aInd = 0;
    for (int i = 0; i < 16; i++) {
      while (bins[i] != NULL)
        A[aInd++] = delBin(&bins[i]);
    }
  }
}

Bin *makeBin(int val) {
  Bin *retBin = malloc(sizeof(Bin));
  retBin->next = NULL;
  retBin->val = val;
  return retBin;
}

void addBin(Bin **rootPtr, int val) {
  Bin *newBin = makeBin(val);
  newBin->next = (*rootPtr);
  (*rootPtr) = newBin;
}

int delBin(Bin **rootPtr) {
  // It's better to delete the first bin and reattach the ptr then go to end of
  // linked list and pop last value
  if (rootPtr == NULL || *rootPtr == NULL)
    return -1;

  Bin *rootBin = *rootPtr;
  Bin *nextBin = rootBin->next;

  int retVal = rootBin->val;

  free(rootBin);
  *rootPtr = nextBin;
  return retVal;
}

/***** Start of SHELL SORT *********/
void algs_shellSort(int *A, int N) {
  if (A == NULL) {
    fflush(stdout);
    fprintf(stderr, "\nError: Null pointer in algs_shellSort\n");
    return;
  }

}
