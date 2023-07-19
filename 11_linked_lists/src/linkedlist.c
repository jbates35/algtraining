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
    int x = INT_MIN;

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
            struct Node *temp = *p;

            //Now need to change head pointer and change what it points to
            *p = curr;
            (*p)->next = temp;

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

int isSortedList(struct Node *p)
{
    int x = INT_MIN; // Keeps track of current lowest value. Needed since it's a linked list, not array

    //Checks last value to see if it's higher than the current val
    while(p)
    {
        //If x is greater than p val, then not sorted
        if(p->val < x)
            return 0;

        x = p->val;
        p = p->next;
    }

    return 1;
}

void insertNode(struct Node **p, int val, int pos)
{
    struct Node *q = (struct Node*) malloc(sizeof(struct Node));
    q-> val = val;

    if(pos == 0)
    {
        q->next = *p;
        *p = q;    
        return;
    }

    struct Node *curr = *p;
    struct Node *prev;
    
    for(int i = 0; i < pos && curr; i++)
    {
        prev = curr;
        curr = curr->next;
    }

    q->next = curr;
    prev->next = q;
}

void insertNodeS(struct Node **p, int val)
{
    struct Node *q = (struct Node*) malloc(sizeof(struct Node));
    q-> val = val;

    if(val < (*p)->val)
    {
        q->next = *p;
        *p = q;    
        return;
    }

    struct Node *curr = *p;
    struct Node *prev;

    while(curr && curr->val < val)
    {
        prev = curr;
        curr = curr->next;
    }

    q->next = curr;
    prev->next = q;    
}