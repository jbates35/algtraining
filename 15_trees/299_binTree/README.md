# Lesson 286 - Making binary trees
## Getting started with binary trees
### Description:
Trees are often used for things such as file structures, searching and sorting algorithms etc. This program will contain all for this chapter, as it's hard to verify creating a binary tree without also traversing it.
```shell
$ git clone https://github.com/jbates35/algtraining
$ cd ./algtraining/15_trees
$ mkdir build && cd build
$ cmake .. && make
$ cd 299_binTree
```
### Example:
-x list of values you want in queue (ints). If -1 (or more negative) is entered, it will count as a skipped node. So positive values are for nodes.
```shell
$ ./binTree -x "1 3 5 2 6 7" -s "5"
```

```

If interested, the functions of note are located in src/binTree.c:
```c

```