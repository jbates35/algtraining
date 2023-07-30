# Student Challenge 1
## Sparse matrix with linked lists
### Description:
This exercise is meant to see if we can use our linked list library to represent a sparse matrix. This will require changing the value type in the linked list nodes to the sparse matrix node.
```
$ git clone https://github.com/jbates35/algtraining
$ cd ./algtraining/11_linked_list
$ mkdir build && cd build
$ cmake .. && make
$ cd 228_sparseMatLL
```
### Example:
No optargs for this one, just run the program
```bash
$ ./sparseMatLL
```
This will give you a result of:
```
Displaying list 1:
[ 1 3 6 2 10 14 152 193 ]
Displaying list 2:
[ 2 6 2 9 10 14 152 193 ]

Intersecting nodes are:
[ 10 14 152 193 ]
```
This just mean that's it has detected the last four nodes as having common pointers between the two lists, which is true.

I managed to use two array stacks and pop them until the lists don't match. This way, the problem was done with an O(n) solution instead of O(n^2). Though, this is more like O(4*n) lol. 