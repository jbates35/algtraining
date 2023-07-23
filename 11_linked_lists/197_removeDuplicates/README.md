# Lesson 197
## Deleting duplicate entries from a list
### Description:
This exercise is designed to provide practice deleting duplicate entries in a linked list.

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
```bash
$ ./removeDups -x "1 1 3 3 4 5 5 5 9 10 12 12"
```
This will give you a result of:
```bash
Displaying list:
[ 1 1 3 3 4 5 5 5 9 10 12 12 ]

Removing duplicate nodes from linked list

Now displaying list again:
[ 1 3 4 5 9 10 12 ]
```
Note: The link must be sorted. It checks for that!

Another note: If looking through code, the functions of interest are 
```c
void removeDuplicates(struct Node *p);
```
All of the implementations for these are found in src/linkedlist.c. 
