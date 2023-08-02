#ifndef STACK_ARR_H
#define STACK_ARR_H

#include <stdio.h>
#include <stdlib.h>

#define DEFAULT_STACK_SIZE 5

struct stack 
{
    int size;
    int top;
    int *s;   
};

void initStack(struct stack **st);
void freeStack(struct stack **st);
void push(struct stack *st, int val);
int pop(struct stack *st);
int peek(struct stack *st);
int isFull(struct stack *st);
int isEmpty(struct stack *st);

#endif