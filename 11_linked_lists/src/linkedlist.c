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

int deleteNode(struct Node **p, int pos)
{
    int returnVal = 0;
    
    //Need a node to allow operations while also having the pointer to free
    struct Node *q = *p, *qPrev;

    if(pos==0)
    {        
        //Store the value, and change where the pointer points to
        returnVal = q->val; 
        *p = q->next;
        
        //Don't need entry anymore but need to clear from heap
        free(q);

        return returnVal;
    }

    for(int i = 0; i < pos && q; i++)
    {   
        qPrev = q;
        q = q->next;
    }
    //If a null pointer, well, obviously nothing to delete
    if(!q)
    {
        fflush(stdout);
        fprintf(stderr, "\nError: in deleteNode, position out of range");
        return returnVal;
    }

    //Store value for return
    returnVal = q->val;
    
    //Link the previous node to the next so we can clear memory
    qPrev->next = q->next;
    free(q);

    return returnVal;
}

void removeDuplicates(struct Node *p)
{
    if(!p)
        return;

    struct Node *q = p->next;

    while(q)
    {
        //If values aren't the same, we can update the pointers and move to next node
        if(p->val != q->val)
        {
            p = q;
            q = q->next;
            continue;
        }

        //Otherwise, store p in another pointer so it can be freed
        p->next = q->next;
        free(q);
        q = p->next;    
    }
}

void reverseList(struct Node **p)
{
    struct Node *prev=NULL; 
    struct Node *curr=NULL; 
    struct Node *next = *p;

    while(next)
    {
        prev = curr;
        curr = next;
        next = next->next; //lol

        curr->next = prev; // Link the pointer back
    }

    //Now we need the original pointer to link to our new first node
    if(curr)
        *p = curr;
}
