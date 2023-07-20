# Lesson 197
## Deleting duplicate entries list
### Description:
This exercise is designed to provide practice deleting duplicate nodes in a linked list.

### Setup: 
To use the program, rip the git, and then make a folder build in this folder. I.e.
```
$ git clone https://github.com/jbates35/algtraining
$ cd ./algtraining/11_linked_list
$ mkdir build && cd build
$ cmake .. && make
$ cd 197_removeDuplicates
```
### Example:
There is one optarg for this program, which is:
x - List of elements to make list with
p - Position for value to be inserted at (only matters if sorted isn't required)
```bash
$ ./delete -x "1 2 3 7 9 11" -p 3
```
This will give you a result of:
```bash
Displaying list:
[ 1 2 3 7 9 11 ]

Deleting linked list node at position 3
Deleted value is 7

Now displaying list again:
[ 1 2 3 9 11 ]
```

Other examples:
```bash
$ ./delete -x "1 2 3 7 9 11" -p 0
```
Gives:
```bash
Displaying list:
[ 1 2 3 7 9 11 ]

Deleting linked list node at position 0
Deleted value is 1

Now displaying list again:
[ 2 3 7 9 11 ]
```

```bash
./delete -x "1 2 3 7 9 11" -p 10
```
Gives:
```bash
Displaying list:
[ 1 2 3 7 9 11 ]

Deleting linked list node at position 10
Error: in deleteNode, position out of range
Deleted value is 0

Now displaying list again:
[ 1 2 3 7 9 11 ]
```
Eh, last one is sloppy, but you get my drift :P

Another note: If looking through code, the functions of interest are 
```c
int deleteNode(struct Node **p, int pos);
```
All of the implementations for these are found in src/linkedlist.c. 
