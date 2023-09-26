#ifndef STACK_ARR_H
#define STACK_ARR_H

#include <stdio.h>
#include <stdlib.h>

#include "binTree.h"

typedef struct Stack 
{
    int size;
    int top;
    BinNode** s;
} Stack;

void initStack(Stack **st, int size);
void freeStack(Stack **st);
int push(Stack *st, BinNode* Node);
BinNode* pop(Stack *st);
BinNode* peek(Stack *st);
int isFull(Stack *st);
int isEmpty(Stack *st);

typedef struct StackPtr
{
    int size;
    int top;
    BinNode*** s;
} StackPtr;

void sptr_init(StackPtr **st, int size);
void sptr_free(StackPtr **st);
int sptr_push(StackPtr *st, BinNode** NodePtr);
BinNode** sptr_pop(StackPtr *st);
BinNode** sptr_peek(StackPtr *st);
int sptr_isFull(StackPtr *st);
int sptr_isEmpty(StackPtr *st);

#endif