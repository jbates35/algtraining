# Lesson 184
## Search through a linked list for a key
### Description:
This exercise is designed to provide practice searching a keyed value in a linked list, returning the pointer to the node. This will be done both iteratively and recursively.

There will be an additional method called qsearchNode, in which the idea is that it doesn't just find the sought after key, but then re-arranges the list so that node is now the first node in the linked list. The idea is that the values that are searched for are more likely to be searched for again. This is also good practice as I had to break the link list up, patch the previous node to the next, and take the current node and put it in the front.

This particular exercise wouldn't be too useful as is, but would be a lot more useful if the linked list contained a data structure that had a key and value pair.
### Setup: 
To use the program, rip the git, and then make a folder build in this folder. I.e.
```
$ git clone https://github.com/jbates35/algtraining
$ cd ./algtraining/11_linked_list
$ mkdir build && cd build
$ cmake .. && make
$ cd 184_search 
```
### Example:
There is one optarg for this program, which is:
x - Elements in an array (separated with a space)
k - Key to be searched for
```bash
$ ./search -x "1 3 2 6 4 0 10 2 5 9 8" -k 5
```
This will give you a result of:
```
Displaying list:
[ 1 3 2 6 4 0 10 2 5 9 8 ]
Node at location 0x7fff15121dc0, with val 5

Now doing quicksearch:
Displaying list again (note different order):
[ 5 1 3 2 6 4 0 10 2 9 8 ]

Displaying list recursively:
1 3 2 6 4 0 10 2 5 9 8 
Finding node with key=5
Node at location 0x7fff15121dc8, with val 5
```
Another note: If looking through code, the functions of interest are 
```c
struct Node *searchNode(struct Node *p, int key);
struct Node *qsearchNode(struct Node **p, int key);
```
and
```c
struct RNode *searchNodeR(struct RNode *p, int key);
```
All of the implementations for these are found in src/linkedlist.c and src/rlinkedlist.c. 
