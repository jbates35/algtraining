# Lesson 263 - Using linked-list queues
## Linked-list queue practice
### Description:
Last practice is queues with linked lists. As always with linked lists vs arrays, we get an easier time coding in return for completely dynamic and heap based queue.
```shell
$ git clone https://github.com/jbates35/algtraining
$ cd ./algtraining/14_queues
$ mkdir build && cd build
$ cmake .. && make
$ cd 263_queueLL
```
### Example:
-x list of values you want in queue (ints)
```shell
$ ./llqueue -x "1 3 5 2 6 7 10 9 8 11 15 14 13"
```

```
Unloading queue (size==4):
1
3
5
2

Unloading queue (size==4):
6
7
10
9

Unloading queue (size==4):
8
11
15
14

Unloading remaining values in queue:
13
```

If interested, the functions of note are located in src/queueCircular.c:
```c
typedef struct Node {
    struct Node *next;
    int val;
} Node;

void enqueue(Node **first, int val);
int dequeue(Node **first);

```