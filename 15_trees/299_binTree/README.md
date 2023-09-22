# Lesson 299 - Making binary trees
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
```bash
$ ./binTree -x "1 2 3 4 -1 5 -1 6 7 8 -1 9"
```
./binTree -x "1 2 3 4 -1 5 -1 6 7 8 -1 9"
Pre-order tree traversal: 1 2 4 6 9 7 3 5 8 
In-order tree traversal: 9 6 4 7 2 1 8 5 3 
Level-order tree traversal: 1 2 3 4 5 6 7 8 9 
Number of nodes is 9
Height of tree is 5
Number of leaf nodes is 3
```
Note that the way the nodes are created are level-order.

If interested, the functions of note are located in src/binTree.c:
```c
typedef struct BinNode {
    int val;
    struct BinNode *lchild;
    struct BinNode *rchild;
} BinNode;

//Create entire tree from list of vals
void bt_createTree(BinNode **rootNode, int* arr, int length);
void bt_free(BinNode **rootNode);
void bt_preOrder(BinNode *rootNode);
void bt_inOrder(BinNode *rootNode);
void bt_levelOrder(BinNode *rootNode);
int bt_count(BinNode *rootNode);
int bt_height(BinNode *rootNode);
int student_challenge(BinNode *rootNode);
```