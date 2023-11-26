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
Depth first search for starting value 5 is:
From 5 to 3
From 3 to 1
From 1 to 2
From 1 to 4
From 5 to 6
From 5 to 7
5 3 1 2 4 6 7 
```
If interested, the functions of note are located in src/graphs.c:
```c
int graphs_DFS(int **graph, int M, int N, int startVal, int *arr, int *L);
```
