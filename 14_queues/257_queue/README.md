# Lesson 257 - Using queues
## Getting started with queues
### Description:
Queues are used everywhere. I didn't really need to go along with this version of the queue. It's not a circular queue and therefore unlikely a queue that'd ever be put into practice. However, I still wanted to get my feet wet with this one.
```shell
$ git clone https://github.com/jbates35/algtraining
$ cd ./algtraining/13_stack
$ mkdir build && cd build
$ cmake .. && make
$ cd 257_queue
```
### Example:
-x list of values you want in queue (ints)
-s size of queue
```shell
$ ./queue -x "1 3 5 2 6 7" -s "5"
```
Warning: Could not add value 7 to queue due to it being full
Dequeuing queue:
1
3
5
2
6
```

If interested, the functions of note are located in src/queue.c:
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
int queueReachedMax(Queue *q);
int queueIsEmpty(Queue *q);
```