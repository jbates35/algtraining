#include "stackarr.h"

void initStack(struct stack **st, int size)
{
    (*st) = (struct stack*) malloc(sizeof(struct stack));
    (*st)->size = size;
    (*st)->s = (int*) malloc(sizeof(int) * (*st)->size);
    (*st)->top = -1; //Means empty
}

void freeStack(struct stack **st)
{
    if((*st)->s)
        free((*st)->s);
    if(*st)
        free(*st);
}

int push(struct stack *st, int val)
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
        fprintf(stderr, "\nWarning: Full stack, cannot push value %d", val);
        return -1;
    }

    //Finally, push the value onto stack and increment top
    st->s[++st->top] = val;
    return 0;
}

int pop(struct stack *st)
{
    //Check for null pointers so no undefined behaviour
    if(st==NULL || st->s == NULL) {
        fflush(stdout);
        fprintf(stderr, "\nError: Null pointer in pop");
        return 0;
    }

    //Make sure there's something in the stack
    if(isEmpty(st)) {
        fflush(stdout);
        fprintf(stderr, "\nWarning: Empty stack, cannot pop");
        return 0;
    }

    //Finally, take the value from the stack and decrement top
    int rtnVal = st->s[st->top--];
    return rtnVal;
}

int peek(struct stack *st)
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

int isFull(struct stack *st)
{
    return st->top >= st->size-1;
}

int isEmpty(struct stack *st)
{
    return st->top <= -1;
}
