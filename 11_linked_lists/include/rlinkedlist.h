#ifndef R_LINKED_LIST_H
#define R_LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>

struct RNode {
    int val;
    struct RNode *next;
};

//Lesson 177
void createNodeR(struct RNode **p, int val);
void freeNodesR(struct RNode *p);
void displayNodesR(struct RNode *p);

//Lesson 180
int countNodesR(struct RNode *p);
int sumNodesR(struct RNode *p);
#endif