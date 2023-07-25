# Lesson 210
## Circular linked lists
### Description:
This exercise is designed to provide practice working with circular linked lists

### Setup: 
To use the program, rip the git, and then make a folder build in this folder. I.e.
```
$ git clone https://github.com/jbates35/algtraining
$ cd ./algtraining/11_linked_list
$ mkdir build && cd build
$ cmake .. && make
$ cd 210_circularlists 
```
### Example:
Simply run the program, there are no arguments for this program
```bash
$ ./circular
```
This will give you a result of:
```
Displaying list:
[ 1 3 2 9 3 1 7 ]
List is not circular.

Making circular list now.
List is circular.
Displaying circular list:
[ 1 3 2 9 3 1 7 ]

Inserting value 19 into position 4
Deleting position 3
Displaying circular list:
[ 1 3 2 19 3 1 7 ]

Deleting position 0
Inserting value 21 into position 0
Displaying circular list:
[ 21 3 2 19 3 1 7 ]
```
Another note: If looking through code, the functions of interest are 
```c
void makeCircular(struct Node *p);
int checkCircular(struct Node *p);
void insertCircular(struct Node **p, int val, int pos);
int deleteCircular(struct Node **p, int pos);
void displayCircular(struct Node *p);
void freeCircular(struct Node *p);
```
This can be found in src/linkedlist.c. 