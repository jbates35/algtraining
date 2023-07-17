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
    int key = 0;

    while ((c = getopt(argc, argv, "x:k:")) != -1)
    {
        switch (c)
        {
        case 'x':
            str = optarg;
            break;
        case 'k':
            key = atoi(optarg);
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

    struct Node *keyedNode = searchNode(valList, key);
    if (keyedNode != NULL) {
        printf("\nNode at location %p, with val %d\n", (void*)&keyedNode, keyedNode->val);
    } else {
        printf("\nNode with the specified key was not found.\n");
    }

    printf("\nNow doing quicksearch:");
    keyedNode = qsearchNode(&valList, key);
    printf("\nDisplaying list again (note different order):");
    displayList(valList);
    
    printf("\n\nDisplaying list recursively:\n");
    displayNodesR(valListR);
    printf("\nFinding node with key=%d", key);

    struct RNode *keyedNodeR = searchNodeR(valListR, key);
    
    if (keyedNodeR != NULL) {
        printf("\nNode at location %p, with val %d\n", (void*)&keyedNodeR, keyedNodeR->val);
    } else {
        printf("\nNode with the specified key was not found.\n");
    }

    freeList(valList);
    freeNodesR(valListR);
    printf("\n\n");
}