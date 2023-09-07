#include "queueLL.h"

#include <stdio.h>
#include <stdlib.h>

void enqueue(Node **first, int val) {
    // We first need to create the node which will store the value
    // This will get then placed into the last node of our linked list
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->val = val;
    newNode->next = NULL; 
    
    // First node of linked list gets treated differently in function
    // Due to having to link to the pointer variable calling this function in the first place
    if((*first) == NULL) {
        *first = newNode;
        return;
    }

    // Need new node so we don't over-write value of our argument pointer
    Node *p = *first;

    // Find the last link in the linked list and link it to our new node
    while(p->next)
        p = p->next;
    p->next = newNode;
    return;
}

int dequeue(Node **first) {
    int retVal = -1;

    if(*first==NULL)
        return retVal;

    Node *p = *first;

    retVal = p->val;
    *first = p->next;
    p->next = NULL;
    free(p);    
    return retVal;
}

int queueIsEmpty(Node *first) {
    return first==NULL;
}