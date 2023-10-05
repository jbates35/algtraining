#include "stackarr.h"

void initStack(Stack **st, int size)
{
    (*st) = (Stack*) malloc(sizeof(Stack));
    (*st)->size = size;
    (*st)->s = (RBNode**) malloc(sizeof(RBNode*) * (*st)->size);
    (*st)->top = -1; //Means empty
}

void freeStack(Stack **st)
{
    if((*st)->s)
        free((*st)->s);
    if(*st)
        free(*st);
}

int push(Stack *st, RBNode* Node)
{
    //Check for null pointers so no undefined behaviour
    if(st==NULL || st->s == NULL) {
        fflush(stdout);
        fprintf(stderr, "\nError: Null pointer in push");
        return -1;
    }

    //Make sure enough room is in stack
    if(isFull(st)) {
        fflush(stdout);
        fprintf(stderr, "\nWarning: Full stack, cannot push value");
        return -1;
    }

    //Finally, push the value onto stack and increment top
    st->top++;
    st->s[st->top] = Node;
    return 0;
}

RBNode* pop(Stack *st)
{
    //Check for null pointers so no undefined behaviour
    if(st==NULL || st->s == NULL) {
        fflush(stdout);
        fprintf(stderr, "\nError: Null pointer in pop");
        return NULL;
    }

    //Make sure there's something in the stack
    if(isEmpty(st)) {
        fflush(stdout);
        fprintf(stderr, "\nWarning: Empty stack, cannot pop");
        return NULL;
    }

    //Finally, take the value from the stack and decrement top
    RBNode* rtnVal = st->s[st->top--];
    return rtnVal;
}

RBNode* peek(Stack *st)
{
    //Check for null pointers so no undefined behaviour
    if(st==NULL || st->s == NULL) {
        fflush(stdout);
        fprintf(stderr, "\nError: Null pointer in peek");
        return 0;
    }

    //Make sure there's something in the stack
    if(isEmpty(st)) {
        fflush(stdout);
        fprintf(stderr, "\nWarning: Empty stack, cannot peek");
        return 0;
    }

    return st->s[st->top];
}

int isFull(Stack *st)
{
    return st->top >= st->size-1;
}

int isEmpty(Stack *st)
{
    return st->top <= -1;
}
