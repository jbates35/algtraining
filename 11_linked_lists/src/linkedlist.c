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

int countNodes(struct Node *p)
{
    int count = 0;

    while(p)
    {
        count ++;
        p = p->next; 
    }

    return count;
}

int sumNodes(struct Node *p)
{
    int sum = 0;

    while(p)
    {
        sum += p->val;
        p = p->next;
    }

    return sum;
}


int maxNode(struct Node *p)
{
    int x = MIN_INT;

    while(p)
    {
        x = p->val > x ? p->val : x;
        p = p->next;
    }

    return x;
}

struct Node *searchNode(struct Node *p, int key)
{
    while(p)
    {
        if(p->val == key)
            return p;
        else
            p = p->next;
    }
    
    return NULL;
}


struct Node *qsearchNode(struct Node **p, int key)
{
    struct Node *last;
    struct Node *curr = *p;

    while(curr)
    {
        if(curr->val == key)
        {
            //Need to make last link to the next
            last->next = curr->next;

            //Now store what the first pointer points to
            curr->next = *p;

            //Now need to change head pointer and change what it points to
            *p = curr;

            //Return the pointer
            return curr;
        }
        else
        {
            last = curr;
            curr = curr->next;
        }
    }
    return NULL;
}