# Lesson 384 - Prims program
## Creating depth first search from graph
### Description:
Prims program is a way of finding a minimum cost spanning tree
```shell
$ git clone https://github.com/jbates35/algtraining
$ cd ./algtraining/22_graphs
$ mkdir build && cd build
$ cmake .. && make
$ cd build/384_prims
```
### Example:
Just run the command once built.
```bash
$ ./prims
```
This should give you:
```
Prims minimum spanning tree for starting value 1 is: 
Link: 1 6 
Link: 5 6 
Link: 4 5 
Link: 3 4 
Link: 2 3 
Link: 7 2 
```
If interested, the functions of note are located in src/graphs.c:
```c
```
