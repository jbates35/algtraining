#include "rlinkedlist.h"

void createNode(struct Node **p, int val)
{
    //Start with what we'd see at end of list
    if(!*p)
    {
        //Create node and append it to the end of the linked list
        struct Node *q = (struct Node*) malloc(sizeof(struct Node));
        q->val = val;
        q->next = NULL;
        
        *p = q;
        return;
    }

    //Traverse to last entry of current list
    createNode(&(*p)->next, val);
}

void freeNodes(struct Node *p)
{
    if (!p)
        return;

    //Call recursively until we get to end of function
    freeNodes(p->next);

    //Now we can free the nodes as we fall back down the stack
    free(p);
}

void displayNodes(struct Node *p)
{
    if(!p)
        return;
    
    printf("%d ", p->val);
    displayNodes(p->next);
}