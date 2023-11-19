# Lesson 377 - Breadth First Search
## Creating breadth first search from graph
### Description:

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
1 2 3 4 5 6 7 
Breadth first search for starting value 2 is:
2 1 3 4 5 6 7 
Breadth first search for starting value 3 is:
3 1 2 4 5 6 7 
Breadth first search for starting value 4 is:
4 1 3 5 2 6 7 
Breadth first search for starting value 5 is:
5 3 4 6 7 1 2 
Breadth first search for starting value 6 is:
6 3 5 1 2 4 7 
Breadth first search for starting value 7 is:
7 5 3 4 6 1 2 
```
If interested, the functions of note are located in src/chainhash.c:
```c
int graphs_BFS(int **graph, int M, int N, int startVal, int *arr, int *L);
```
