#include "graphs.h"
#include "queueCircular.h"
#include "stackarr.h"

#include <stdio.h>
#include <stdlib.h>

int graphs_BFS(int **graph, int M, int N, int startVal, int *arr, int *L) {
  if (graph == NULL) {
    fflush(stdout);
    fprintf(stderr, "Error: null ptr in graphs_BFS\n");
    return -1;
  }

  int *visited = calloc(M, sizeof(int));

  Queue *q;
  initQueue(&q, M);

  enqueue(q, startVal);
  arr[0] = startVal;
  visited[startVal] = 1;
  *L = 1;

  while (!queueIsEmpty(q)) {
    int nextVal = dequeue(q);

    for (int i = 0; i < N; i++) {
      if (graph[nextVal][i] == 0 || visited[i] == 1)
        continue;

      printf("From %d to %d\n", nextVal, i);
      enqueue(q, i);
      arr[*L] = i;
      visited[i] = 1;
      (*L)++;
    }
  }

  freeQueue(&q);
  free(visited);

  return 0;
}

int graphs_DFS(int **graph, int M, int N, int startVal, int *arr, int *L) {
  if (graph == NULL) {
    fflush(stdout);
    fprintf(stderr, "Error: null ptr in graphs_DFS\n");
    return -1;
  }

  int *visited = calloc(M, sizeof(int));

  Stack *s;
  initStack(&s, M);

  push(s, startVal);
  arr[0] = startVal;
  visited[startVal] = 1;
  *L = 1;

  int nextVal = startVal;

  while (!isEmpty(s)) {
    int i = 1;
    for (; i < N; i++) {
      if (graph[nextVal][i] == 1 && visited[i] == 0)
        break;
    }

    if (i == N) {
      nextVal = pop(s);
    } else {
      printf("From %d to %d\n", nextVal, i);
      push(s, nextVal);
      arr[*L] = i;
      visited[i] = 1;
      (*L)++;
      nextVal = i;
    }
  }

  freeStack(&s);
  free(visited);

  return 0;
}
