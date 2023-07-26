#include "dlinkedlist.h"

void initList(DoublyLL **list)
{
    *list = (DoublyLL*) malloc(sizeof(DoublyLL));
    (*list)->length=0;
    (*list)->isCircular=0;
    (*list)->first = NULL;
    (*list)->last = NULL;
}

void freeList(DoublyLL *list)
{
    if(list == NULL)
    {
        fflush(stdout);
        fprintf(stderr, "\nError: Null pointer in freeList\n");
        return;
    }

    DNode *q=NULL;
    DNode *p = list->first;

    if(p == NULL)
        return;

    while(1)
    {
        q = p;
        p = p->next;
        free(q);

        if(!p || p == list->first)
            break;
    }

    free(list);
}

void appendNode(DoublyLL *list, int val)
{
    if(list == NULL)
    {
        fflush(stdout);
        fprintf(stderr, "\nError: Null pointer in appendNode\n");
        return;
    }

    DNode *new = (DNode*) malloc(sizeof(DNode));
    new->val = val;
    new->next = NULL;
    new->prev = NULL;

    list->length++;
    list->last = new;

    //If there's no nodes input, this is our first node
    if(list->first == NULL)
    {
        list->first = new;
        list->last = new;
        return;
    }
    
    //Otherwise, append, take care of links
    DNode *p = list->first;

    while(p->next)
        p = p->next;
    
    p->next = new;
    new->prev = p; 
}

void insertNode(DoublyLL *list, int val, int pos)
{
    
}

int deleteNode(DoublyLL *list, int pos)
{
    
}

void displayList(DoublyLL *list)
{
    if(list == NULL)
    {
        fflush(stdout);
        fprintf(stderr, "\nError: Null pointer in displayList\n");
        return;
    }

    DNode *p = list->first;
    
    if(p == NULL)
        return;
    
    printf("[ ");
    do
    {   
        printf("%d ", p->val);
        p = p->next;
    } while (p != NULL && p != list->first);
    printf("]\n");
}

void reverseList(DoublyLL *list)
{
    
}

void makeCircular(DoublyLL *list)
{
    
}

void isCircular(DoublyLL *list)
{
    
}

