# Lesson 234 - Stack with Arrays
## Basic stack being implemented with array
### Description:
This exercise is meant to introduce stacks. In this lesson we will use arrays.
```bash
$ git clone https://github.com/jbates35/algtraining
$ cd ./algtraining/13_stack
$ mkdir build && cd build
$ cmake .. && make
$ cd 234_stackArray
```
### Example:
No optargs for this one, just run the program
```bash
$ ./stackarr
```
This will give you a result of:
```
Pushing 1...
Last entry: 1
Pushing 3...
Last entry: 3
Pushing 2...
Last entry: 2
Pushing 4...
Last entry: 4
Pushing 9...
Last entry: 9
Pushing 3...
Warning: Full stack, cannot push value 3
Popped 9
Popped 4
Popped 2
Popped 3
Popped 1
Attempting to pop one more time...
Warning: Empty stack, cannot pop
```

If interested, the functions of note are located in src/stackarr.c:
```c
void initStack(struct stack **st);
void freeStack(struct stack **st);
void push(struct stack *st);
int pop(struct stack *st);
int peek(struct stack *st);
int isFull(struct stack *st);
int isEmpty(struct stack *st);
```