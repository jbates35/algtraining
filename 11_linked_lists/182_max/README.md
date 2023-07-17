# Lesson 182
## Max node in linked list
### Description:
This exercise is designed to provide practice finding the max value in a linked list. This will be done both iteratively and recursively.
### Setup: 
To use the program, rip the git, and then make a folder build in this folder. I.e.
```
$ git clone https://github.com/jbates35/algtraining
$ cd ./algtraining/11_linked_list
$ mkdir build && cd build
$ cmake .. && make
$ cd 182_max 
```
### Example:
There is one optarg for this program, which is:
x - Elements in an array (separated with a space)
```bash
$ ./max -x "1 20 2 -1 50 4 88 3"
```
This will give you a result of:
```
Displaying list:
[ 1 20 2 -1 50 4 88 3 ]
Max val: 88

Displaying list recursively:
1 20 2 -1 50 4 88 3 
Max val: 88
```
Another note: If looking through code, the functions of interest are 
```c
int maxNode(struct Node *p);
```
and
```c
int maxNodeR(struct RNode *p);
```
All of the implementations for these are found in src/linkedlist.c and src/rlinkedlist.c. 
