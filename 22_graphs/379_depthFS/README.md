# Lesson 379 - Depth First Search
## Creating depth first search from graph
### Description:
Depth first search on graphs. Much like a pre-order tree.
```shell
$ git clone https://github.com/jbates35/algtraining
$ cd ./algtraining/22_graphs
$ mkdir build && cd build
$ cmake .. && make
$ cd build/379_depthFS
```
### Example:
Just run the command once built.
```bash
$ ./BFS
```
This should give you:
```
```
If interested, the functions of note are located in src/chainhash.c:
```c
int graphs_DFS(int **graph, int M, int N, int startVal, int *arr, int *L);
```
