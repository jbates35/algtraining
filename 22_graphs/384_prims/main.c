#include "graphs.h"

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int tempGraph[8][8] = {
      {F, F, F, F, F, F, F, F},    {F, F, 25, F, F, F, 5, F},
      {F, 25, F, 12, F, F, F, 10}, {F, F, 12, F, 8, F, F, F},
      {F, F, F, 8, F, 16, F, 14},  {F, F, F, F, 16, F, 20, 18},
      {F, 5, F, F, F, 20, F, F},   {F, F, 10, F, 14, 18, F, F}};
  int *graph[8];
  for (int i = 0; i < sizeof(tempGraph) / sizeof(tempGraph[0]); i++)
    graph[i] = tempGraph[i];

  int A[100];
  int L = 0;

  graphs_prims(graph, 8, 8, 1, A, &L);

  printf("Prims minimum spanning tree for starting value 1 is: \n");
  for (int i = 0; i < L; i++)
    printf("%d ", A[i]);
  printf("\n");

  return 0;
}
