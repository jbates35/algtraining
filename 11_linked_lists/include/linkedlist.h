#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node *next;
};

//Lesson 175
void createNode(struct Node **p, int val);
void freeList(struct Node *p);
void displayList(struct Node *p);

//Lesson 180
int countNodes(struct Node *p);
int sumNodes(struct Node *p);
#endif