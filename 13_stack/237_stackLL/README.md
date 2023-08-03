# Lesson 237 - Stack with Linked lists
## Basic stack being implemented with linked list
### Description:
This exercise is meant to introduce stacks. In this lesson we will use linked lists.
```bash
$ git clone https://github.com/jbates35/algtraining
$ cd ./algtraining/13_stack
$ mkdir build && cd build
$ cmake .. && make
$ cd 237_stackLL
```
### Example:
No optargs for this one, just run the program
```bash
$ ./stackll
```
This will give you a result of:
```
Pushing 1...
Pushing 3...
Pushing 2...
Pushing 4...
Pushing 9...
Pushing 3...
Popped 3
Popped 9
Popped 4
Popped 2
Popped 3
Popped 1
Attempting to pop one more time...
Warning: No values in sNode
```

If interested, the functions of note are located in src/stackarr.c:
```c
void push(struct st** first, int val);
int pop(struct st** first);
int peek(struct st* first);
int freeStack(struct st* first);
int isEmpty(struct st* first);
```