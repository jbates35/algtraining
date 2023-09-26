#include "stackarr.h"

void initStack(Stack **st, int size)
{
    (*st) = (Stack*) malloc(sizeof(Stack));
    (*st)->size = size;
    (*st)->s = (BinNode**) malloc(sizeof(BinNode*) * (*st)->size);
    (*st)->top = -1; //Means empty
}

void freeStack(Stack **st)
{
    if((*st)->s)
        free((*st)->s);
    if(*st)
        free(*st);
}

int push(Stack *st, BinNode* Node)
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

BinNode* pop(Stack *st)
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
    BinNode* rtnVal = st->s[st->top--];
    return rtnVal;
}

BinNode* peek(Stack *st)
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

void sptr_init(StackPtr **st, int size) {
    (*st) = (StackPtr*) malloc(sizeof(StackPtr));
    (*st)->size = size;
    (*st)->s = (BinNode***) malloc(sizeof(BinNode**) * (*st)->size);
    (*st)->top = -1; //Means empty
}

void sptr_free(StackPtr **st) {
    if((*st)->s)
        free((*st)->s);
    if(*st)
        free(*st);
}

int sptr_push(StackPtr *st, BinNode** NodePtr) {
    //Check for null pointers so no undefined behaviour
    if(st==NULL || st->s == NULL) {
        fflush(stdout);
        fprintf(stderr, "\nError: Null pointer in push");
        return -1;
    }

    //Make sure enough room is in stack
    if(sptr_isFull(st)) {
        fflush(stdout);
        fprintf(stderr, "\nWarning: Full stack, cannot push value");
        return -1;
    }

    //Finally, push the value onto stack and increment top
    st->top++;
    st->s[st->top] = NodePtr;
    return 0;
}

BinNode** sptr_pop(StackPtr *st) {
    //Check for null pointers so no undefined behaviour
    if(st==NULL || st->s == NULL) {
        fflush(stdout);
        fprintf(stderr, "\nError: Null pointer in pop");
        return NULL;
    }

    //Make sure there's something in the stack
    if(sptr_isEmpty(st)) {
        fflush(stdout);
        fprintf(stderr, "\nWarning: Empty stack, cannot pop");
        return NULL;
    }

    //Finally, take the value from the stack and decrement top
    BinNode** rtnVal = st->s[st->top--];
    return rtnVal;
}

BinNode** sptr_peek(StackPtr *st) {
    //Check for null pointers so no undefined behaviour
    if(st==NULL || st->s == NULL) {
        fflush(stdout);
        fprintf(stderr, "\nError: Null pointer in peek");
        return 0;
    }

    //Make sure there's something in the stack
    if(sptr_isEmpty(st)) {
        fflush(stdout);
        fprintf(stderr, "\nWarning: Empty stack, cannot peek");
        return 0;
    }

    return st->s[st->top];
}

int sptr_isFull(StackPtr *st) {
    return st->top >= st->size-1;
}

int sptr_isEmpty(StackPtr *st) {
    return st->top <= -1;
}
