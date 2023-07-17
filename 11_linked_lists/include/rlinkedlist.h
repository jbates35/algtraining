#ifndef R_LINKED_LIST_H
#define R_LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node *next;
};

void createNode(struct Node **p, int val);
void freeNodes(struct Node *p);
void displayNodes(struct Node *p);

#endif