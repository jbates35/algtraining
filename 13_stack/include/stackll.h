#ifndef STACK_LL_H
#define STACK_LL_H

#include <stdio.h>
#include <stdlib.h>

struct sNode {
    int data;
    struct sNode *next;
};

void push(struct sNode** first, int val);
int pop(struct sNode** first);
int peek(struct sNode* first);
void freeStack(struct sNode* first);
int isEmpty(struct sNode* first);

#endif