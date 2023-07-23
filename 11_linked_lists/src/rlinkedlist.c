#include "rlinkedlist.h"

void createNodeR(struct RNode **p, int val)
{
    //Start with what we'd see at end of list
    if(!*p)
    {
        //Create node and append it to the end of the linked list
        struct RNode *q = (struct RNode*) malloc(sizeof(struct RNode));
        q->val = val;
        q->next = NULL;
        
        *p = q;
        return;
    }

    //Traverse to last entry of current list
    createNodeR(&(*p)->next, val);
}

void freeNodesR(struct RNode *p)
{
    if (!p)
        return;

    //Call recursively until we get to end of function
    freeNodesR(p->next);

    //Now we can free the nodes as we fall back down the stack
    free(p);
}

void displayNodesR(struct RNode *p)
{
    if(!p)
        return;
    
    printf("%d ", p->val);
    displayNodesR(p->next);
}

int countNodesR(struct RNode *p)
{
    if(!p)
        return 0;
    
    return countNodesR(p->next) + 1;
}

int sumNodesR(struct RNode *p)
{
    if(!p)
        return 0;

    return sumNodesR(p->next) + p->val;
}

int maxNodeR(struct RNode *p)
{
    if(!p)
        return INT_MIN;
    
    int x = maxNodeR(p->next);
    return p->val > x ? p->val : x;
}

struct RNode *searchNodeR(struct RNode *p, int key)
{
    //Should return either the key that's found, or if it's reached the end of the list, then NULL
    if(p->val == key || !p)
        return p;
    
    return searchNodeR(p->next, key);
}


//We need return the last pointer all the way to the first
//Otherwise, we need the pointers to flip around the links
struct RNode *reverseListR(struct RNode *curr, struct RNode *next)
{
    if(next == NULL)
        return curr;

    //Main purpose of this is to traverse the last pointer through the func calls to be the new head 
    struct RNode *first = reverseListR(next, next->next);

    //Reverse the links, act as if curr is end of link
    next->next = curr;
    curr->next = NULL;

    return first;
}
