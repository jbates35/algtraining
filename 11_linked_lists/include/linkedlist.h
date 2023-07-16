#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node *next;
};

void createNode(struct Node **p, int val);
void freeList(struct Node *p);
void displayList(struct Node *p);

#endif