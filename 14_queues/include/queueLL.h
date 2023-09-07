#ifndef QUEUE_LL_H
#define QUEUE_LL_H

typedef struct Node {
    struct Node *next;
    int val;
} Node;

void enqueue(Node **first, int val);
int dequeue(Node **first);
int queueIsEmpty(Node *first);

#endif