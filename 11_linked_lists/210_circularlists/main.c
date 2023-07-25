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

    struct Node *valList = NULL;

    char *token;
    const char s[2] = " ";
    char str[] = "1 3 2 9 3 1 7";
    token = strtok(str, s);

    while(token != NULL)
    {
        createNode(&valList, atoi(token));
        token = strtok(NULL, s);
    }

    printf("\nDisplaying list:");
    displayList(valList);
    
    if(checkCircular(valList))
        printf("\nList is circular.");
    else
        printf("\nList is not circular.");

    printf("\n\nMaking circular list now.");
    makeCircular(valList);

    if(checkCircular(valList))
        printf("\nList is circular.");
    else
        printf("\nList is not circular.");

    printf("\nDisplaying circular list:");
    displayCircular(valList);

    printf("\n\nInserting value 19 into position 4");
    insertCircular(&valList, 19, 4);

    printf("\nDeleting position 3");
    deleteCircular(&valList, 3);

    printf("\nDisplaying circular list:");
    displayCircular(valList);
    
    printf("\n\nDeleting position 0");
    deleteCircular(&valList, 0);

    printf("\nInserting value 21 into position 0");
    insertCircular(&valList, 21, 0);

    printf("\nDisplaying circular list:");
    displayCircular(valList);
    
    printf("\n\n");

    freeCircular(valList);
}