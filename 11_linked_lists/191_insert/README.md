# Lesson 191
## Inserting into a linked list
### Description:
This exercise is designed to provide practice insert a keyed value in a linked list. First non sorted (so by position), then sorted (therefore by value).

### Setup: 
To use the program, rip the git, and then make a folder build in this folder. I.e.
```
$ git clone https://github.com/jbates35/algtraining
$ cd ./algtraining/11_linked_list
$ mkdir build && cd build
$ cmake .. && make
$ cd 191_insert 
```
### Example:
There is one optarg for this program, which is:
x - List of elements to make list with
s - Sorted, boolean (first runs algorithm to make sure it is sorted)
v - Value to be inserted
p - Position for value to be inserted at (only matters if sorted isn't required)
```bash
$ ./insert -x "1 2 3 7" -v 6 -s
```
This will give you a result of:
```bash
Displaying list:
[ 1 2 3 7 ]
Sort-inserting value 6
Sorted-insert result:
[ 1 2 3 6 7 ]
```
Another example would be:
```
./insert -x "1 2 3 7" -v 6 -p 0
```
Which would give you:
```bash
Displaying list:
[ 1 2 3 7 ]
Inserting value 6 at position 0 (0 indexed)
Insert result:
[ 6 1 2 3 7 ]
```
Another note: If looking through code, the functions of interest are 
```c
int isSortedList(struct Node *p);
void insertNode(struct Node **p, int val, int pos);
void insertNodeS(struct Node **p, int val);
```
All of the implementations for these are found in src/linkedlist.c. 
