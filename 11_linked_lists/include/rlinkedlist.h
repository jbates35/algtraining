#ifndef R_LINKED_LIST_H
#define R_LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>

struct RNode {
    int val;
    struct RNode *next;
};

void createNodeR(struct RNode **p, int val);
void freeNodesR(struct RNode *p);
void displayNodesR(struct RNode *p);

#endif