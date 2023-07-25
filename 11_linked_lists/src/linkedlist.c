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

//Recursive function that wasn't taught, but I wanted something that could pull this off
void sortList(struct Node **p)
{
    if(*p == NULL)
        return;

    int minVal = INT_MAX;

    struct Node *q = *p;
    struct Node *r = NULL, *curr = NULL, *prev = NULL;

    while(q)
    {
        //Keep track of node which is lowest in val
        if(q->val < minVal)
        {
            minVal = q->val;
            curr = q;
            prev = r;
        }

        //Advance list
        r = q;
        q = q->next;
    }

    //If the beginning of the list is the lowest val, then no need to change
    if(curr != *p)
    {
        prev->next = curr->next;
        curr->next = *p;
        *p = curr;
    }

    sortList(&(*p)->next);
}

void concatLists(struct Node **p, struct Node **q)
{
    if(!*p) 
    {
        *p = *q;
        *q = NULL;
        return;
    }  

    struct Node *temp = *p;

    while(temp->next)
        temp = temp->next;
    
    temp->next = *q;
    *q = NULL;
}

struct Node *mergeLists(struct Node **p, struct Node **q)
{
    struct Node *r = NULL;
    struct Node *first = NULL;
    struct Node *pCurr = NULL, *qCurr = NULL;

    if(*p == NULL)
        r = *q;
    else if(*q == NULL)
        r = *p;
    else
    {
        pCurr = *p;
        qCurr = *q;

        if(pCurr->val < qCurr->val)
        {
            r = pCurr;
            pCurr = pCurr->next;
        }
        else
        {
            r = qCurr;
            qCurr = qCurr->next;
        }

        first = r;

        while(pCurr && qCurr)
        {
            if(pCurr->val < qCurr->val)
            {
                r->next = pCurr;
                pCurr = pCurr->next;
            }
            else
            {
                r->next = qCurr;
                qCurr = qCurr->next;
            }

            //Following line prevents trying to assign r->next when we just started building our LL
            r = r->next;
        }

        if(pCurr)
            r->next = pCurr;
        else
            r->next = qCurr;
    }
    
    *p = NULL;
    *q = NULL;

    return first;
}

void makeCircular(struct Node *p)
{
    struct Node *first = p;

    if(p == NULL)
        return;
    
    while(p->next)
        p = p->next;
    
    p->next = first;
}

int checkCircular(struct Node *p)
{
    struct Node *p2xSpeed = p;
    int isCircular = 0;

    do
    {
        p = p->next;

        p2xSpeed = p2xSpeed->next;
        if(p2xSpeed)
            p2xSpeed = p2xSpeed->next;

        if(p == p2xSpeed)
        {
            isCircular = 1;
            break;
        }
    } while (p2xSpeed);
    
    return isCircular;
}

void insertCircular(struct Node **p, int val, int pos)
{
    struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->val = val;
    newNode->next = NULL;
    
    struct Node *curr = *p;
    struct Node *first = *p;

    //Couple possibilities
    //Possibility 1: val inserted at beginning of list
    if(pos == 0 || curr==NULL)
    {
        if(curr)
            newNode->next = curr;

        *p = newNode;

        //Just make circular from here
        while(curr->next && curr->next != first)
            curr = curr->next;
        curr->next = *p;

        return;
    }

    struct Node *prev = NULL;

    //Possibility 2&3: val inserted at end of list, or middle
    int currPos = 0;
    do
    {
        prev = curr;
        curr = curr->next;
        currPos++;
    } 
    while(currPos < pos && curr != first);

    if(curr == first) 
    {
        newNode->next = first;
        prev->next = newNode;
    }
    else
    {
        newNode->next = prev->next;
        prev->next = newNode;
    }
}

int deleteCircular(struct Node **p, int pos)
{
    int returnVal = 0;
    
    //Need a node to allow operations while also having the pointer to free
    struct Node *q = *p, *qPrev;
    struct Node *first = *p;

    if(*p == NULL)
    {
        fflush(stdout);
        fprintf(stderr, "\nError: in deleteNode, can't delete a null pointer");
        return returnVal;            
    }

    if(pos==0)
    {        
        //Store the value, and change where the pointer points to
        returnVal = q->val; 
        *p = q->next;
        
        //Don't need entry anymore but need to clear from heap
        free(q);

        //Have to remake being circular from here
        q = *p;
        while(q->next && q->next != first)
            q = q->next;
        q->next = *p;   

        return returnVal;
    }

    int currPos = 0;
    do 
    {  
        qPrev = q;
        q = q->next;
        currPos++;
    } while(currPos < pos && q != (*p));

    //If a null pointer, well, obviously nothing to delete
    if(!q || q == (*p))
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

void displayCircular(struct Node *p)
{
    if(p == NULL)
        return;
    
    struct Node *first = p;

    printf("\n[ ");
    do 
    {
        printf("%d ", p->val);
        p = p->next;
    } while(p != first);

    printf("]");
}

void freeCircular(struct Node *p)
{
    struct Node *q;
    struct Node *first = p;

    if (p == NULL)
        return;
    
    do
    {
        q = p->next;
        
        if (q == NULL)
            break;

        free(p);
        p = q;
    } while (p != first);    
}