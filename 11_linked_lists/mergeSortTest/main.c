#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

#include "linkedlist.h"
#include "helpFuncs.h"

int main(int argc, char *argv[])
{

    struct Node *valList1 = NULL;
    struct Node *valList2 = NULL;

    char *token;
    const char s[2] = " ";

    char str[] = "1 3 12 21 9 5 10 15 9 13 14 24 10 25 1 19 17";

    token = strtok(str, s);
    while(token != NULL)
    {
        createNode(&valList1, atoi(token));
        createNode(&valList2, atoi(token));
        token = strtok(NULL, s);
    }

    printf("\nDisplaying list 1:");
    displayList(valList1);

    // mergeSortList(&valList1);
    funcTime(mergeSortList, valList1, "mergeSortList");

    printf("\nDisplaying list after merge sort:");
    displayList(valList1);

    printf("\nDisplaying list 1:");
    displayList(valList2);

    sortList(&valList2);

    printf("\nDisplaying list after bubble sort:");
    displayList(valList2);

    printf("\n\nNow timing it with list of size 1E7");


    printf("\n\n");

    freeList(valList1);
    freeList(valList2);

}