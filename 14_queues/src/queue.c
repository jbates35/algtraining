#include "queue.h"

#include <stdio.h>
#include <stdlib.h>

void init(Queue **q, int size) {
    (*q) = (Queue*) malloc(sizeof(Queue));
    (*q)->size = size;
    (*q)->queue = (int*) malloc(sizeof(int) * (*q)->size);
    (*q)->front = -1;
    (*q)->rear = -1;
}

void free(Queue **q) {
    if(q == NULL || (*q)->queue==NULL) {
        fprintf(stderr, "ERROR: Null pointer in enqueue");
        return;
    }

    free((*q)->queue);
    free(q);
    q = NULL;
}

void enqueue(Queue *q, int val) {
    if(q == NULL) {
        fprintf(stderr, "ERROR: Null pointer in enqueue");
        return;
    }
    
    if(q == q->size - 1) {
        fprintf(stderr, "ERROR: No more space in queue");
        return;
    }

    q->queue[++q->rear] = val;
}

int dequeue(Queue *q) {
    if(q == NULL) {
        fprintf(stderr, "ERROR: Null pointer in enqueue");
        return;
    }

    if(q->rear == q->front) {
        fprintf(stderr, "ERROR: Queue is empty");
        return -1;
    }

    int ret = q->queue[++q->front];
    return ret;
}

