#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

#include "linkedlist.h"

int main(int argc, char *argv[])
{

    struct Node *valList1 = NULL;
    struct Node *valList2 = NULL;
    struct Node *p = NULL;
    struct Node *q = NULL;

    char *token;
    const char s[2] = " ";

    char str1[] = "1 3 6 2";
    char str2[] = "2 6 2 9";
    char str3[] = "10 14 152 193";

    token = strtok(str1, s);
    while(token != NULL)
    {
        createNode(&valList1, atoi(token));
        token = strtok(NULL, s);
    }

    token = strtok(str2, s);
    while(token != NULL)
    {
        createNode(&valList2, atoi(token));
        token = strtok(NULL, s);
    }  

    p = valList1;
    while(p->next)
        p = p->next;

    q = valList2;
    while(q->next)
        q = q->next;
        
    token = strtok(str3, s);
    while(token != NULL)
    {
        struct Node *new = (struct Node*) malloc(sizeof(struct Node));
        new->val = atoi(token);
        new->next = NULL;

        p->next = new;
        q->next = new;

        p = p->next;
        q = q->next;
        
        token = strtok(NULL, s);
    }

    printf("\nDisplaying list 1:");
    displayList(valList1);
    
    printf("\nDisplaying list 2:");
    displayList(valList2);
    
    struct Node* nodeStack1[100]; 
    struct Node* nodeStack2[100];

    p = valList1;
    q = valList2;

    int pi = 0, qi = 0;

    for(pi = 0; p && pi < 99; pi++)
    {
        nodeStack1[pi] = p;
        p = p->next;
    }

    for(qi = 0; q && qi < 99; qi++)
    {
        nodeStack2[qi] = q;
        q = q->next;
    }

    nodeStack1[pi] = NULL;
    nodeStack2[qi] = NULL;

    while(--pi >= 0 && --qi >= 0)
    {
        if(nodeStack1[pi] != nodeStack2[qi])
            break;
    }

    if(qi == -1 || pi == -1)
        printf("\n\nComplete intersect");
    else
    {
        struct Node *newList = nodeStack1[pi + 1];

        if(newList == NULL)
        {
            printf("\n\nNo intersection");
        }
        else
        {
            printf("\n\nIntersecting nodes are:");
            displayList(newList);
        }
    }
    
    printf("\n\n");

    freeList(valList1);

    //Memory leak due to the nature of this post but it's not a big deal so i'm not going to trouble myself w solving it
}