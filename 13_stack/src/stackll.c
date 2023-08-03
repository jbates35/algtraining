#include "stackll.h"

void push(struct sNode** first, int val)
{
    struct sNode *new = (struct sNode*) malloc(sizeof(struct sNode));
    new->data = val;
    new->next = *first;
    *first = new;
}

int pop(struct sNode** first)
{
    if(*first == NULL)
    {
        fflush(stdout);
        fprintf(stderr, "\nWarning: No values in sNode\n");
        return 0;
    }
    
    int val = (*first)->data;
    struct sNode *p = *first;
    *first = p->next;
    free(p);
    return val;
}

int peek(struct sNode* first)
{
    if(!isEmpty(first))
        return first->data;

    fflush(stdout);
    fprintf(stderr, "\nWarning: No values in sNode\n");
    return 0;    
}

void freeStack(struct sNode* first)
{
    struct sNode* p = first;
    struct sNode* q = NULL;

    while(p) {
        q = p;
        p = p->next;
        free(q);
    }
}

int isEmpty(struct sNode* first)
{
    return first==NULL;
}
