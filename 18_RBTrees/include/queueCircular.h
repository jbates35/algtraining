#ifndef QUEUE_CIRCULAR_H
#define QUEUE_CIRCULAR_H

#include "redblack.h"

typedef struct Queue {
    int size;
    int front;
    int rear;
    RBNode** queue;
} Queue;

void initQueue(Queue **q, int size);
void freeQueue(Queue **q);
void enqueue(Queue *q, RBNode* Node);
RBNode* dequeue(Queue *q);
int queueIsFull(Queue *q);
int queueIsEmpty(Queue *q);

#endif
