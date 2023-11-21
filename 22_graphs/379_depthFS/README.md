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
Breadth first search for starting value 5 is:
From 5 to 3
From 5 to 4
From 5 to 6
From 5 to 7
From 3 to 1
From 3 to 2
5 3 4 6 7 1 2 
```
If interested, the functions of note are located in src/chainhash.c:
```c
int graphs_DFS(int **graph, int M, int N, int startVal, int *arr, int *L);
```
