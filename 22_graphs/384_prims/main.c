#include "graphs.h"

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  const int F = ~(1 << 31);
  int tempGraph[8][8] = {
      {F, F, F, F, F, F, F, F},    {F, F, 25, F, F, F, 5, F},
      {F, 25, 12, F, F, F, F, 10}, {F, F, 12, F, 8, F, F, F},
      {F, F, F, 8, F, 16, F, 18},  {F, F, F, F, 16, F, 20, 18},
      {F, 5, F, F, F, 20, F, F},   {F, F, 10, F, 14, 18, F, F}};
  int **graph;
  for (int i = 0; i < sizeof(tempGraph) / sizeof(tempGraph[0]); i++)
    graph[i] = tempGraph[i];

  return 0;
}
