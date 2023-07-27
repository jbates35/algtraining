#include "dlinkedlist.h"

void initList(DoublyLL **list)
{
    *list = (DoublyLL*) malloc(sizeof(DoublyLL));
    (*list)->length=0;
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

    while(p)
    {
        q = p;
        p = p->next;
        free(q);
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
    if(list == NULL)
    {
        fflush(stdout);
        fprintf(stderr, "\nError: Null pointer in insertNode\n");
        return;
    }

    struct DNode *new = (struct DNode*) malloc(sizeof(struct DNode));
    new->val = val;
    new->next = NULL;
    new->prev = NULL;

    struct DNode *p = list->first;

    //If insert is in front of all the other nodes
    if(pos == 0)
    {
        p->prev = new;
        new->next = p;
        list->first = new;

        return;        
    }

    //Traverse array until position or end
    for(int i = 0; i < pos-1 && p->next; i++)
        p = p->next;
    
    //While we're here, if we reached end of list, we have a new last node
    if(!p->next)
        list->last = new;

    if(p)
        (p->next)->prev = new; 

    new->next = p->next;
    new->prev = p;   

    p->next = new;
    
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
    
    printf("[ ");
    while(p);
    {   
        printf("%d ", p->val);
        p = p->next;
    } 
    printf("]\n");
}

void reverseList(DoublyLL *list)
{
    
}
