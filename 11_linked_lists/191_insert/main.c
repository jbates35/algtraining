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
    int val = 0;
    int sorted = 0;

    while ((c = getopt(argc, argv, "x:p:v:s")) != -1)
    {
        switch (c)
        {
        case 'x':
            str = optarg;
            break;
        case 'p':
            pos = atoi(optarg);
            break;
        case 'v':
            val = atoi(optarg);
            break;
        case 's':
            sorted = 1;
            break;
        }
    }

    struct Node *valList = NULL;
    
    token = strtok(str, s);
    while(token != NULL)
    {
        createNode(&valList, atoi(token));
        token = strtok(NULL, s);
    }

    printf("Displaying list:");
    displayList(valList);
    fflush(stdout);

    if(sorted) 
    {
        if(isSortedList(valList))
        {
            printf("\nSort-inserting value %d", val);
            insertNodeS(&valList, val);
            printf("\nSorted-insert result:");
            displayList(valList);
        }
        else
            fprintf(stderr, "\nList is not sorted, but sort boolean is specified");
    }
    else
    {
        printf("\nInserting value %d at position %d (0 indexed)", val, pos);
        insertNode(&valList, val++, pos);
        printf("\nInsert result:");
        displayList(valList);
    }

    freeList(valList);
    printf("\n\n");
}