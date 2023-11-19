#include "graphs.h"
#include "queueCircular.h"

#include <stdio.h>
#include <stdlib.h>

int graphs_BFS(int **graph, int M, int N, int startVal, int *arr, int *L) {
  if (graph == NULL) {
    fflush(stdout);
    fprintf(stderr, "Error: null ptr in graphs_BFS\n");
    return -1;
  }

  Queue *q;
  initQueue(&q, M);

  enqueue(q, startVal);
  arr[0] = startVal;

  *L = 1;

  while (!queueIsEmpty(q)) {
    int nextVal = dequeue(q);

    for (int i = 0; i < N; i++) {
      int isValid = 1;
      for (int j = 0; j < *L; j++) {
        if (graph[nextVal][i] == 0 || i == arr[j]) {
          isValid = 0;
          break;
        }
      }
      if (isValid) {
        enqueue(q, i);
        arr[*L] = i;
        (*L)++;
      }
    }
  }

  freeQueue(&q);

  return 0;
}
