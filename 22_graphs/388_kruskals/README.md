# Lesson 388 - Kruskals program
## Using Kruskal's algorithm for minimum cost spanning tree
### Description:
Kruskals program is a way of finding a minimum cost spanning tree
```shell
$ git clone https://github.com/jbates35/algtraining
$ cd ./algtraining/22_graphs
$ mkdir build && cd build
$ cmake .. && make
$ cd build/388_kruskals
```
### Example:
Just run the command once built.
```bash
$ ./kruskals
```
This should give you:
```
Kruskal's minimum spanning tree for starting value 1 is: 
Link 0: Edge {1, 6}: 5
Link 1: Edge {3, 4}: 8
Link 2: Edge {2, 7}: 10
Link 3: Edge {2, 3}: 12
Link 4: Edge {2, 6}: 14
Link 5: Edge {4, 5}: 16
```
If interested, the functions of note are located in src/graphs.c:
```c
int graphs_kruskal(Edge *edges, int edgeLen, int nodeCnt, Edge *arr,
                   int *arrLen);
```
