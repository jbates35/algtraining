#ifndef QUEUE_H
#define QUEUE_H

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

#endif