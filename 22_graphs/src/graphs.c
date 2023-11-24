#include "graphs.h"
#include "queueCircular.h"
#include "stackarr.h"

#include <bits/pthreadtypes.h>
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

typedef struct nearestVal {
  int val;
  int to;
  int from;
} NearestVal;

NearestVal makeNearestVal(int val, int to, int from) {
  NearestVal retVal = {val, to, from};
  return retVal;
}

int findMinInd(int A[], int M, int N);
int findMinArr(int **graph, int M, int N, int *nearest, int L);
int sumOfArr(int A[], int L);

int graphs_prims(int **graph, int M, int N, int startVal, int *arr, int *L) {
  if (graph == NULL) {
    fflush(stdout);
    fprintf(stderr, "Error: null ptr in graphs_DFS\n");
    return -1;
  }

  int minVal = 0;
  int minInd = 0;

  unsigned long inArray = 0x0;

  int *nearest = malloc(sizeof(int) * M);

  arr[0] = startVal;
  arr[1] = findMinInd(graph[startVal], 1, N);

  inArray |= 1 << arr[0];
  inArray |= 1 << arr[1];

  for (int i = 1; i < M; i++) {
    if (i == arr[0] || i == arr[1]) {
      nearest[i] = 0; // makeNearestVal(0, 0, 0);
      continue;
    }

    int minInd = 0;

    for (int j = 1; j < M; j++) {
      if (((1 << j) & inArray) == 0)
        continue;

      if (graph[i][j] <= graph[i][minInd])
        minInd = j;
    }
    nearest[i] = minInd;
  }

  int x = findMinArr(graph, M, N, nearest, M);

  arr[2] = x;
  arr[3] = nearest[x];
  *L = 4;

  inArray |= 1 << x;
  nearest[x] = 0;

  while (sumOfArr(nearest, M)) {
    for (int i = 1; i < M; i++) {
      if (nearest[i] == 0) {
        continue;
      }

      int minInd = nearest[i];

      for (int j = 1; j < M; j++) {
        if (((1 << j) & inArray) == 0)
          continue;

        if (graph[i][j] < graph[i][minInd])
          minInd = j;
      }
      nearest[i] = minInd;
    }

    x = findMinArr(graph, M, N, nearest, M);
    arr[(*L)++] = x;
    arr[(*L)++] = nearest[x];
    inArray |= 1 << x;
    nearest[x] = 0;
  }
  free(nearest);
  return 0;
}

/**
 * findMin finds the min index from pos M, to pos N,
 * note that these are absolute values
 * */
int findMinInd(int A[], int M, int N) {
  int minInd = N - 1;

  for (int i = M; i < N - 1; i++) {
    if (A[i] < A[minInd])
      minInd = i;
  }

  return minInd;
}

int findMinArr(int **graph, int M, int N, int *nearest, int L) {
  int minInd = 0;

  for (int i = 1; i < L; i++) {
    if (graph[nearest[i]][i] < graph[nearest[minInd]][minInd])
      minInd = i;
  }

  return minInd;
}

int sumOfArr(int A[], int L) {
  int retVal = 0;
  for (int i = 0; i < L; i++)
    retVal += A[i];
  return retVal;
}
