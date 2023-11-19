#include "graphs.h"

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

  int tempGraph[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 1, 1, 1, 0, 0, 0},
                         {0, 1, 0, 1, 0, 0, 0, 0}, {0, 1, 1, 0, 1, 1, 0, 0},
                         {0, 1, 0, 1, 0, 1, 0, 0}, {0, 0, 0, 1, 1, 0, 1, 1},
                         {0, 0, 0, 1, 0, 1, 0, 0}, {0, 0, 0, 0, 0, 1, 0, 0}};

  int *graph[8];

  for (int i = 0; i < 8; i++)
    graph[i] = tempGraph[i];

  int A[100];
  int L = 0;

  for (int start = 1; start < 8; start++) {

    printf("Breadth first search for starting value %d is:\n", start);

    graphs_BFS(graph, 8, 8, start, A, &L);

    for (int i = 0; i < L; i++)
      printf("%d ", A[i]);
    printf("\n");
  }
}
