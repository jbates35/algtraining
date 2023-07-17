# Lesson 180
## Count and sum
### Description:
This exercise is designed to provide practice counting and summing a linked list. Both methods will be done both iteratively and recursively.
### Setup: 
To use the program, rip the git, and then make a folder build in this folder. I.e.
```
$ git clone https://github.com/jbates35/algtraining
$ cd ./algtraining/10_sparse_matrix
$ mkdir build && cd build
$ cmake .. && make
$ cd 180_countAndSum 
```
### Example:
There is one optarg for this program, which is:
x - Elements in an array (separated with a space)
```bash
$ ./countSum -x "1 3 1 2 4 6"
```
This will give you a result of:
```
Displaying list:
[ 1 3 1 2 4 6 ]
Number of nodes: 6
Sum of linked list: 17

Displaying list recursively:
1 3 1 2 4 6 
Number of nodes: 6
Sum of linked list: 17
```
Another note: If looking through code, the functions of interest are 
```c
int countNodes(struct Node *p);
int sumNodes(struct Node *p);
```
and
```c
int countNodesR(struct RNode *p);
int sumNodesR(struct RNode *p);
```
All of the implementations for these are found in src/linkedlist.c and src/rlinkedlist.c. 
