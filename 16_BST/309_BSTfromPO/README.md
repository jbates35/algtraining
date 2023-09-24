# Lesson 309 - Create BST from PO
## Creating a BST from an array of values from a previously pre-ordered BST
### Description:
Generally, you need in-order and either post-order or pre-ordered trees if you want to re-create them.
With BSTs, you just need the pre-ordered or post-ordered tree to re-create the original BST.
In this exercise, we'll just use pre-ordered.
```shell
$ git clone https://github.com/jbates35/algtraining
$ cd ./algtraining/16_BST
$ mkdir build && cd build
$ cmake .. && make
$ cd 309_BSTfromPO
```
### Example:
-x list of values you want in the BST
```bash
$ ./BSTfromPO -x "10 6 13 5 7 12 14"
```
Which gives:
```
Level-order tree traversal: 10 6 13 5 7 12 14 
Pre-order tree traversal: 10 6 5 7 13 12 14 
In-order tree traversal: 5 6 7 10 12 13 14 
```
You can see that it's the same order as the level order given from exercise 305.

If interested, the functions of note are located in src/bst.c:
```c
void bst_fromPre(BinNode** rootNode, int *arr, int l);
```