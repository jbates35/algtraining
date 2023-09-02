#ifndef QUEUE_H
#define QUEUE_H

typedef struct Queue {
    int size;
    int front;
    int rear;
    int *queue;
} Queue;

void init(Queue **q, int size);
void free(Queue **q);
void enqueue(Queue *q, int val);
int dequeue(Queue *q);

#endif