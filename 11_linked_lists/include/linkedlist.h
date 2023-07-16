#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node *next;
};

void createNode(struct Node *node);
void showLL(struct Node *first);

#endif