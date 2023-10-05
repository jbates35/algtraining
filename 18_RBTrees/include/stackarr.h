#ifndef STACK_ARR_H
#define STACK_ARR_H

#include <stdio.h>
#include <stdlib.h>

#include "redblack.h"

typedef struct Stack 
{
    int size;
    int top;
    RBNode** s;
} Stack;

void initStack(Stack **st, int size);
void freeStack(Stack **st);
int push(Stack *st, RBNode* Node);
RBNode* pop(Stack *st);
RBNode* peek(Stack *st);
int isFull(Stack *st);
int isEmpty(Stack *st);

#endif