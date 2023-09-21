#ifndef QUEUE_CIRCULAR_H
#define QUEUE_CIRCULAR_H

#include "binTree.h"

typedef struct Queue {
    int size;
    int front;
    int rear;
    BinNode** queue;
} Queue;

void initQueue(Queue **q, int size);
void freeQueue(Queue **q);
void enqueue(Queue *q, BinNode* Node);
BinNode* dequeue(Queue *q);
int queueIsFull(Queue *q);
int queueIsEmpty(Queue *q);

#endif