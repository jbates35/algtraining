#ifndef STACK_ARR_H
#define STACK_ARR_H

#include <stdio.h>
#include <stdlib.h>

struct stack 
{
    int size;
    int top;
    int *s;
};

void initStack(struct stack **st, int size);
void freeStack(struct stack **st);
int push(struct stack *st, int val);
int pop(struct stack *st);
int peek(struct stack *st);
int isFull(struct stack *st);
int isEmpty(struct stack *st);

#endif