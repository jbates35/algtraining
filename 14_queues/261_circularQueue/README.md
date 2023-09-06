# Lesson 261 - Using cicular queues
## Circular queue practice
### Description:
The much more useful queue (and perhaps something I'll drag along into other projects). Circular queues are much more useful as they are not constrained by the array size (other than the max amount of values it can hold). For this exercise, we'll have an array size of 5.
```shell
$ git clone https://github.com/jbates35/algtraining
$ cd ./algtraining/14_queues
$ mkdir build && cd build
$ cmake .. && make
$ cd 261_circularQueue
```
### Example:
-x list of values you want in queue (ints)
```shell
$ ./circqueue -x "1 3 5 2 6 7 10 9 8 11 15 14 13"
```

```
Unloading queue (size==4)
1
3
5
2

Unloading queue (size==4)
6
7
10
9

Unloading queue (size==4)
8
11
15
14
```

If interested, the functions of note are located in src/queueCircular.c:
```c
typedef struct Queue {
    int size;
    int front;
    int rear;
    int *queue;
} Queue;

void initQueue(Queue **q, int size);
void freeQueue(Queue **q);
void enqueue(Queue *q, int val);
int dequeue(Queue *q);
int queueIsFull(Queue *q);
int queueIsEmpty(Queue *q);
```