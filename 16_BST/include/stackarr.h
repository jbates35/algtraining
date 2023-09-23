#ifndef STACK_ARR_H
#define STACK_ARR_H

#include <stdio.h>
#include <stdlib.h>

#include "binTree.h"

typedef struct stack 
{
    int size;
    int top;
    BinNode** s;
} Stack;

void initStack(struct stack **st, int size);
void freeStack(struct stack **st);
int push(struct stack *st, BinNode* Node);
BinNode* pop(struct stack *st);
BinNode* peek(struct stack *st);
int isFull(struct stack *st);
int isEmpty(struct stack *st);

#endif