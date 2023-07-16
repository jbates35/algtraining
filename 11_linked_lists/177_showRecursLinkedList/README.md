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
$ ./showRLinkedList -x "1 2 1 3 1 4 1 5"
```
This will give you a result of:
```
Displaying list:
[ 1 2 1 3 1 4 1 5 ]
```
Another note: If looking through code, the functions of interest are 
```c
void createNode(struct Node **p, int val);
void freeList(struct Node *p);
void displayList(struct Node *p);
```
All of the implementations for these are found in src/rlinkedlist.c. 