# Lesson 204
## Merging or concatenating lists
### Description:
This exercise is designed to provide practice reversing a linked list.

### Setup: 
To use the program, rip the git, and then make a folder build in this folder. I.e.
```
$ git clone https://github.com/jbates35/algtraining
$ cd ./algtraining/11_linked_list
$ mkdir build && cd build
$ cmake .. && make
$ cd 201_reverseList 
```
### Example:
There is one optarg for this program, which is:
x - List of elements to make list with
```bash
$ ./reverse -x "1 3 2 5 9"
```
This will give you a result of:
```
------------------------------
        Non recursive
------------------------------
Displaying list:
[ 1 3 2 5 9 ]
Reversing list...
Now displaying list again:
[ 9 5 2 3 1 ]

------------------------------
          Recursive
------------------------------
Displaying list:
1 3 2 5 9 
Reversing list...
Now displaying list again:
9 5 2 3 1 
```
If looking through the code, you'll notice that, as usual, the recursive solution is much more elegant than the iterative one.

Another note: If looking through code, the functions of interest are 
```c
void reverseList(struct Node **p);
```
This one can be found in src/linkedlist.c. 

And
```c
struct RNode *reverseListR(struct RNode *curr, struct RNode *next);
```
This one can be found in src/rlinkedlist.c