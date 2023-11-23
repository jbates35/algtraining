#ifndef GRAPHS_H
#define GRAPHS_H

int graphs_BFS(int **graph, int M, int N, int startVal, int *arr, int *L);
int graphs_DFS(int **graph, int M, int N, int startVal, int *arr, int *L);
int graph_prims(int **graph, int M, int N, int startVal, int *arr, int *L);

#endif
