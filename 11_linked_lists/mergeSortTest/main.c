#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

#include "linkedlist.h"
#include "helpFuncs.h"
#include "valList.h"

int main(int argc, char *argv[])
{

    struct Node *valList1 = NULL;
    struct Node *valList2 = NULL;
    struct Node *valList3 = NULL;
    struct Node *valList4 = NULL;

    char *token;
    const char s[2] = " ";

    char str[] = "1 3 12 21 9 5 10 15 9 13 14 24 10 25 1 19 17 1 3 12 21 9 5 10 15 9 13 14 24 10 25 1 19 17 1 3 12 21 9 5 10 15 9 13 14 24 10 25 1 19 17 1 3 12 21 9 5 10 15 9 13 14 24 10 25 1 19 17";

    token = strtok(str, s);
    while(token != NULL)
    {
        createNode(&valList1, atoi(token));
        createNode(&valList2, atoi(token));
        token = strtok(NULL, s);
    }

    printf("\nDisplaying list 1:");
    displayList(valList1);

    funcTime(mergeSortList, valList1, "merge sort");

    printf("\nDisplaying list after merge sort:");
    displayList(valList1);

    printf("\nDisplaying list 1:");
    displayList(valList2);

    funcTime(sortList, valList2, "bubble sort");

    printf("\nDisplaying list after bubble sort:");
    displayList(valList2);

    fflush(stdout);

    // for(int i = 0; i < 100000; i++)
    // {
    //     createNode(&valList3, valArr[i]);
    //     createNode(&valList4, valArr[i]);
    // }

    // // printf("\n\nNow timing it with list of size 1E5");
    // // funcTime(mergeSortList, valList3, "mergeSortList");
    // // fflush(stdout);
    // // funcTime(sortList, valList4, "sortList (bubble sort)");
    // // fflush(stdout);

    printf("\n\n");

    freeList(valList1);
    freeList(valList2);

}