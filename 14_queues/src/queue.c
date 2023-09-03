#include "queue.h"

#include <stdio.h>
#include <stdlib.h>

void initQueue(Queue **q, int size) {
    (*q) = (Queue*) malloc(sizeof(Queue));
    (*q)->size = size;
    (*q)->queue = (int*) malloc(sizeof(int) * (*q)->size);
    (*q)->front = -1;
    (*q)->rear = -1;
}

void freeQueue(Queue **q) {
    if((*q) == NULL || (*q)->queue==NULL) {
        fflush(stdout);
        fprintf(stderr, "\nERROR: Null pointer in enqueue");
        return;
    }

    free((*q)->queue);
    free(*q);
    q = NULL;
}

void enqueue(Queue *q, int val) {
    if(q == NULL) {
        fflush(stdout);
        fprintf(stderr, "\nERROR: Null pointer in enqueue");
        return;
    }
    
    if(queueReachedMax(q)) {
        fprintf(stderr, "\nWarning: Could not add value %d to queue due to it being full", val);
        return;
    }

    q->queue[++q->rear] = val;
}

int dequeue(Queue *q) {
    if(q == NULL) {
        fflush(stdout);
        fprintf(stderr, "\nERROR: Null pointer in enqueue");
        return -1;
    }

    if(queueIsEmpty(q)) {
        fflush(stdout);
        fprintf(stderr, "\nWarning: Queue could not be dequeued as it is empty");
        return -1;
    }

    int ret = q->queue[++q->front];
    return ret;
}

int queueReachedMax(Queue *q) {
    if(q == NULL) {
        fflush(stdout);
        fprintf(stderr, "\nERROR: Null pointer in queueIsEmpty");
        return -1;
    }

    return q->rear >= q->size-1;
}

int queueIsEmpty(Queue *q) {
    if(q == NULL) {
        fflush(stdout);
        fprintf(stderr, "\nERROR: Null pointer in queueIsEmpty");
        return -1;
    }

    return q->front == q->rear;
}