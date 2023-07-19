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

    printf("Displaying list:");
    displayList(valList);
    printf("\nMax val: %d", maxNode(valList));

    printf("\n\nDisplaying list recursively:\n");
    displayNodesR(valListR);
    printf("\nMax val: %d", maxNodeR(valListR));
    
    freeList(valList);
    freeNodesR(valListR);
    printf("\n\n");
}