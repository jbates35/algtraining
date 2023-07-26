# Lesson 222
## Doubly linked list
### Description:
This exercise is designed to provide practice working with doubly linked lists.

I will be experimenting a bit with encapsulating nodes in a linked list struct. I'd be a bit hesitant about using linked lists in embedded projects, as it relies on heap/dynamic memory. However, I think with due care linked lists could be useful, and therefore this module will hopefully have a bit of stuff hashed out that I can import later to a project.

### Setup: 
To use the program, rip the git, and then make a folder build in this folder. I.e.
```
$ git clone https://github.com/jbates35/algtraining
$ cd ./algtraining/11_linked_list
$ mkdir build && cd build
$ cmake .. && make
$ cd 222_doublylinkedlist 
```
### Example:
Simply run the program, there are no arguments for this program
```bash
$ ./doubly
```
This will give you a result of:
```
```
Another note: If looking through code, the functions of interest are 
```c
```
This can be found in src/dlinkedlist.c. 