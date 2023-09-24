# Lesson 307 - Deleting nodes from binary search tree
## Getting started with binary search tree
### Description:
BSTs are useful because they make future search queries for a set of data extremely quick and easy. In this lesson, we'll start with creating a BST. We'll be piggy backing off the last lesson which was binary trees.
```shell
$ git clone https://github.com/jbates35/algtraining
$ cd ./algtraining/16_BST
$ mkdir build && cd build
$ cmake .. && make
$ cd 305_createBST
```
### Example:
-x list of values you want in the BST
```bash
$ ./createBST -x "10 6 5 7 10 13 12 14"
```
```
Pre-order tree traversal: 10 6 5 7 13 12 14 
In-order tree traversal: 5 6 7 10 12 13 14 
Post-order tree traversal: 5 7 6 12 14 13 10 
Level-order tree traversal: 10 6 13 5 7 12 14
```
If interested, the functions of note are located in src/bst.c:
```c
void bst_createNode(BinNode** rootNode, int val);
```