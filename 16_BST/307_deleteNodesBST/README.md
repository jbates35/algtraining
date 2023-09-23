# Lesson 307 - Delete nodes from BST
## Deleting nodes from BST and properly re-building tree
### Description:
Deleting nodes can result in a few different situations:
1.) Deleting a leaf node - easy. Just delete the node.
2.) Deleting a node a single child node. Easy, just reattach the parent node to the child node.
3.) Deleting a node with two child nodes. uh-oh:

The way I thought to solve this was with the use of a stack and then re-building the tree. This not a bad way but is O(n).
But when following the course, a better way was doing an in-order search from the node being deleted. and then taking the first node afterwards and attaching it to the previous node.
```shell
$ git clone https://github.com/jbates35/algtraining
$ cd ./algtraining/15_trees
$ mkdir build && cd build
$ cmake .. && make
$ cd 307_deleteNodesBST
```
### Example:
-x list of values you want in the BST
```bash
$ ./deleteBST -x "10 5 40 3 7 35 60 6 8 37 50 65 36" -d 40
```

```
BEFORE DELETING:
Level-order tree traversal: 10 5 40 3 7 35 60 6 8 37 50 65 36 
In-order tree traversal: 3 5 6 7 8 10 35 36 37 40 50 60 65 

DELETING NODE WITH KEY==40
Level-order tree traversal: 10 5 37 3 7 35 60 6 8 36 50 65 
In-order tree traversal: 3 5 6 7 8 10 35 36 37 50 60 65 
```

If interested, the functions of note are located in src/bst.c:
```c
void bst_deleteNode(BinNode** rootNode, int val);
```
I'm happy with the deleteNode implementation here and might show it off on a portfolio, as it required some problem solving and a good use case of double pointers.