#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

#include "linkedlist.h"
#include "rlinkedlist.h"

int main(int argc, char *argv[])
{
    int c;
    opterr = 0;
    char *str;
    char *token;
    const char s[2] = " ";
    int pos = 0;

    while ((c = getopt(argc, argv, "x:")) != -1)
    {
        switch (c)
        {
        case 'x':
            str = optarg;
            break;
        }
    }

    struct Node *valList = NULL;
    struct RNode *valListR = NULL;

    token = strtok(str, s);
    while(token != NULL)
    {
        createNode(&valList, atoi(token));
        createNodeR(&valListR, atoi(token));
        token = strtok(NULL, s);
    }

    printf("------------------------------\n\tNon recursive\n------------------------------");
    printf("\nDisplaying list:");
    displayList(valList);
    
    printf("\nReversing list...");
    reverseList(&valList);

    printf("\nNow displaying list again:");
    displayList(valList);

    printf("\n\n------------------------------\n\t  Recursive\n------------------------------");
    printf("\nDisplaying list:\n");
    displayNodesR(valListR);
    
    printf("\nReversing list...");
    valListR = reverseListR(valListR, valListR->next);
    
    printf("\nNow displaying list again:\n");
    displayNodesR(valListR);

    freeList(valList);
    freeNodesR(valListR);

    printf("\n\n");
}