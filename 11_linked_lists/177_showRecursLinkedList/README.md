# Lesson 175
## Showing a Linked List Recursively
### Description:
This exercise is designed to provide practice implementing and showing a linked list. Very similar to 175_showLinkedList, but using recursion. A user can enter their elements, and it will create a linked list out of it.
### Setup: 
To use the program, rip the git, and then make a folder build in this folder. I.e.
```
$ git clone https://github.com/jbates35/algtraining
$ cd ./algtraining/10_sparse_matrix
$ mkdir build && cd build
$ cmake .. && make
$ cd 177_showRecursLinkedList 
```
### Example:
There is one optarg for this program, which is:
x - Elements in an array (separated with a space)
```bash
$ ./showRLinkedList -x "1 3 1 2 4 6"
```
This will give you a result of:
```
Displaying list:
        1 3 1 2 4 6 
```
Another note: If looking through code, the functions of interest are 
```c
void createNodeR(struct RNode **p, int val);
void freeNodesR(struct RNode *p);
void displayNodesR(struct RNode *p);
```
All of the implementations for these are found in src/rlinkedlist.c. 

All in all, recursion and linked lists seem to go very well together. The code ended up being much shorter, and it helps being able to control when you'd free or allocate memory (i.e. before or after the recursive function call).