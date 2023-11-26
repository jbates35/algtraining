#include "heap.h"

#include <memory.h>

// local functions

void swap(Edge *x, Edge *y);
int isMarsenne(int x);

void heap_print(Edge A[], int N) {
  for (int i = 0; i < N; i++)
    printf("From edge %d to %d: %d\n", A[i].p1, A[i].p2, A[i].weight);
  printf("\n");
}

void heap_sort(Edge A[], int N) {
  heap_create(A, N);
  for (int i = 0; i < N - 1; i++)
    heap_delete(A, &N);
}

// From perspective of heapify
void heap_insert(Edge A[], int N, int n) {
  while (n < (N / 2)) {
    int compareInd = (n + 1) * 2 - 1;
    int compareVal = A[compareInd].weight;

    // Compare to sibling to see which value we should take
    if ((compareInd + 1) < N && A[compareInd + 1].weight < compareVal) {
      compareInd++;
      compareVal = A[compareInd].weight;
    }
    if (A[n].weight < compareVal)
      break;
    swap(&A[n], &A[compareInd]);
    n = compareInd;
  }
}

Edge heap_delete(Edge A[], int *N) {
  Edge retEdge = A[0];

  int n = 0;
  (*N)--;
  int m = *N;

  swap(&A[n], &A[m]);
  int asdf = 0;
  while (n < m / 2) {
    int compareInd = (n + 1) * 2 - 1;
    int compareVal = A[compareInd].weight;
    // Compare to sibling to see which value we should take
    if ((compareInd + 1) < m && A[compareInd + 1].weight < compareVal) {
      compareInd++;
      compareVal = A[compareInd].weight;
    }
    swap(&A[n], &A[compareInd]);
    n = compareInd;
  }
  return retEdge;
}

void heap_create(Edge A[], int N) {
  for (int i = N / 2 - 1; i >= 0; i--) {
    heap_insert(A, N, i);
  }
}

void swap(Edge *x, Edge *y) {
  Edge temp = *x;
  *x = *y;
  *y = temp;
}

int isMarsenne(int x) { return ((x & (x + 1)) == 0); }
