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
    char *str1;
    char *str2;
    char *token;
    const char s[2] = " ";
    int pos = 0;
    int merge = 0;

    while ((c = getopt(argc, argv, "x:y:m")) != -1)
    {
        switch (c)
        {
        case 'x':
            str1 = optarg;
            break;
        case 'y':
            str2 = optarg;
        case 'm':
            merge = 1;
            break;
        }
    }

    struct Node *valList1 = NULL;
    struct Node *valList2 = NULL;

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

    printf("\nDisplaying list 1:");
    displayList(valList1);
    
    printf("\n\nDisplaying list 2:");
    displayList(valList2);

    freeList(valList1);
    freeList(valList2);

    printf("\n\n");
}