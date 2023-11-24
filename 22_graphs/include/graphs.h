#ifndef GRAPHS_H
#define GRAPHS_H

#define F ~(1 << 31)

int graphs_BFS(int **graph, int M, int N, int startVal, int *arr, int *L);
int graphs_DFS(int **graph, int M, int N, int startVal, int *arr, int *L);
int graphs_prims(int **graph, int M, int N, int startVal, int *arr, int *L);

#endif
