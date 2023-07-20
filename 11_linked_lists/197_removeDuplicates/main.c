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
    
    token = strtok(str, s);
    while(token != NULL)
    {
        createNode(&valList, atoi(token));
        token = strtok(NULL, s);
    }

    printf("Displaying list:");
    displayList(valList);
    
    if(isSortedList(valList))
    {
        printf("\n\nRemoving duplicate nodes from linked list");
        removeDuplicates(valList);
    }
    else 
    {
        fflush(stdout);
        fprintf(stderr, "Error: list isn't sorted");
    }
    
    printf("\n\nNow displaying list again:");
    displayList(valList);
    
    freeList(valList);
    printf("\n\n");
}