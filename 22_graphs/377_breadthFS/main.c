#include "graphs.h"

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

  int **graph = malloc(sizeof(int *) *);
  graph = {{0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 1, 1, 1, 0, 0, 0},
           {0, 1, 0, 1, 0, 0, 0, 0}, {0, 1, 1, 0, 1, 1, 0, 0},
           {0, 1, 0, 1, 0, 1, 0, 0}, {0, 0, 0, 1, 1, 0, 1, 1},
           {0, 0, 0, 1, 0, 1, 0, 0}, {0, 0, 0, 0, 0, 1, 0, 0}};

  graphs_BFS(graph, 8, 8);
}
