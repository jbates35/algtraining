# Lesson 377 - Breadth First Search
## Creating breadth first search from graph
### Description:
Breadth first search. Much like a level-order tree.
```shell
$ git clone https://github.com/jbates35/algtraining
$ cd ./algtraining/22_graphs
$ mkdir build && cd build
$ cmake .. && make
$ cd build/377_breadthFS
```
### Example:
Just run the command once built.
```bash
$ ./BFS
```
This should give you:
```
Breadth first search for starting value 1 is:
From 1 to 2
From 1 to 3
From 1 to 4
From 3 to 5
From 5 to 6
From 5 to 7
1 2 3 4 5 6 7 
```
If interested, the functions of note are located in src/graphs.c:
```c
int graphs_BFS(int **graph, int M, int N, int startVal, int *arr, int *L);
```
