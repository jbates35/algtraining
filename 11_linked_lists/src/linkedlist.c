#include "linkedlist.h"
#include "helpFuncs.h"

void createNode(struct Node **p, int val)
{
    //Make new node
    struct Node *q = (struct Node*) malloc(sizeof(struct Node));
    q->val = val;
    q->next = NULL;

    //If null pointer entirely, this is a new list
    if (*p==NULL)
    {
        *p = q;
        return;
    }

    //Otherwise, traverse to last entry of current list
    struct Node *temp = *p;
    while(temp->next != NULL)
        temp = temp->next;
    
    //Store node into last entry of current list
    temp->next = q;
}

void freeList(struct Node *p)
{
    struct Node *q;

    while (p != NULL)
    {
        q = p->next;
        free(p);
        p = q;
    }
}

void displayList(struct Node *p)
{
    printf("\n[ ");
    while (p != NULL)
    {
        printf("%d ", p->val);
        p = p->next;
    }
    printf("]");
}