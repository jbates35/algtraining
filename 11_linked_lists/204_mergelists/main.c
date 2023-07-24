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

    char str3[] = "1 3 6 2 9";
    char str4[] = "2 6 19 2 5";

    token = strtok(str3, s);
    while(token != NULL)
    {
        createNode(&valList1, atoi(token));
        token = strtok(NULL, s);
    }

    token = strtok(str4, s);
    while(token != NULL)
    {
        createNode(&valList2, atoi(token));
        token = strtok(NULL, s);
    }

    printf("\nDisplaying list 1:");
    displayList(valList1);
    
    if(merge && !isSortedList(valList1))
    {
        printf("\nList not sorted.\nSorting...");
        sortList(&valList1);
        printf("\nDisplaying list 1:");
        displayList(valList1);
    }

    printf("\n\nDisplaying list 2:");
    displayList(valList2);

    if(merge && !isSortedList(valList2))
    {
        printf("\nList not sorted.\nSorting...");
        sortList(&valList2);
        printf("\nDisplaying list 2:");
        displayList(valList2);
    }

    if(merge)
    {
        printf("\n\nMerging lists");
        struct Node *valList3 = mergeLists(valList1, valList2);
        printf("\nDisplaying merged list:");
        displayList(valList3);
    }
    else
    {
        printf("\n\nConcatenating lists");
        concatLists(&valList1, &valList2);
        printf("\nDisplaying concat list:");
        displayList(valList1);
    }

    freeList(valList1);
    freeList(valList2);

    printf("\n\n");
}