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
    
    printf("\n\nDeleting linked list node at position %d", pos);
    int valDel = deleteNode(&valList, pos);
    printf("\nDeleted value is %d", valDel);

    printf("\n\nNow displaying list again:");
    displayList(valList);
    
    freeList(valList);
    printf("\n\n");
}