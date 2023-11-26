#include "graphs.h"

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  Edge edges[] = {{1, 2, 25}, {1, 6, 5},  {2, 3, 12}, {2, 6, 14},
                  {2, 7, 10}, {3, 4, 8},  {3, 6, 15}, {4, 5, 16},
                  {4, 7, 14}, {5, 6, 20}, {5, 7, 18}};
  int edgeLength = sizeof(edges) / sizeof(Edge);

  Edge A[100];
  int L = 0;

  graphs_kruskal(edges, edgeLength, 7, A, &L);

  printf("Kruskal's minimum spanning tree for starting value 1 is: \n");
  for (int i = 0; i < L; i++) {
    printf("Link %d: Edge {%d, %d}: %d\n", i, A[i].p1, A[i].p2, A[i].weight);
  }
  return 0;
}
