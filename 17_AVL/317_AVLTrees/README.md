# Lesson 317 - Working with AVL Trees
## AVL Trees, generation, rotation, deletion
### Description:
AVL Trees circumvent the problem BSTs have, which is that BSTs can grow n-elements long in height. AVL alleviates this by rotating it when imbalanced
```shell
$ git clone https://github.com/jbates35/algtraining
$ cd ./algtraining/17_AVL
$ mkdir build && cd build
$ cmake .. && make
$ cd 317_AVLTrees
```
### Example:
Just run the command once built.
```bash
$ ./AVLTree
```
```
Height of tree for AVL after inserting all:
13
Height of tree for BST after inserting all:
23

Count of nodes for AVL after inserting all:
1500
Count of nodes for AVL after inserting all:
1500

Height of tree for AVL after deleting half the values:
12

Height of tree for BST after deleting half the values:
19

Count of nodes for AVL after deleting half the values:
750
Count of nodes for BST after deleting half the values:
750
```
If interested, the functions of note are located in src/bst.c:
```c
void avl_createNode(BinNode** rootNode, int val);
void avl_deleteNode(BinNode** rootNode, int val);
void avl_rotateNode(BinNode** rootNode);
```
This code is kinda garbage. Had to end up using a triple pointer to make my weird stack work while still being able to pull pointers from it that I could modify. If I were coding this for someone I'd definitely try to find some different way of doing this - perhaps wrapping the root node of the tree in a struct. Recursion would have made this code a lot cleaner (and would have been far easier to program) but I wanted a deterministic approach with iteration. 

    The avl_rotateNode function is fairly cool though.