# Lesson 204
## Merging or concatenating lists
### Description:
This exercise is designed to provide practice sorting, concatenating, and/or merging two linked lists.

### Setup: 
To use the program, rip the git, and then make a folder build in this folder. I.e.
```
$ git clone https://github.com/jbates35/algtraining
$ cd ./algtraining/11_linked_list
$ mkdir build && cd build
$ cmake .. && make
$ cd 204_mergelists 
```
### Example:
There is one optarg for this program, which is:
x - List of elements to make list with
```bash
$ ./mergelists -m -x "1 3 5 6 2 10" -y "1 0 2 4"
```
This will give you a result of:
```
Displaying list 1:
[ 1 3 5 6 2 10 ]
List not sorted.
Sorting...
Displaying list 1:
[ 1 2 3 5 6 10 ]

Displaying list 2:
[ 1 0 2 4 ]
List not sorted.
Sorting...
Displaying list 2:
[ 0 1 2 4 ]

Merging lists
Displaying merged list:
[ 0 1 1 2 2 3 4 5 6 10 ]
```
Another note: If looking through code, the functions of interest are 
```c
void sortList(struct Node **p);
void concatLists(struct Node **p, struct Node **q);
struct Node *mergeLists(struct Node **p, struct Node **q);
```
This can be found in src/linkedlist.c. 