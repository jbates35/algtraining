#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

#include "linkedlist.h"

int main(int argc, char *argv[])
{

    struct Node *valList = NULL;

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

    token = strtok(str, s);
    while(token != NULL)
    {
        createNode(&valList, atoi(token));
        token = strtok(NULL, s);
    }

    printf("\nDisplaying list:");
    displayList(valList);
    
    //One will move at normal speed, the other will move double. Once q is at end, we see what p is.
    struct Node *p = valList, *q = valList;
    int counter = 0; //helper var for making it so we can modulo
    
    if(p==NULL)
    {
        printf("\nError, no values entered\n\n");
        return -1;
    }

    while(q) 
    {
        if((counter++)%2 == 1)
            p = p->next;
        q = q->next;
    }

    printf("\nMiddle value is %d at position %d", p->val, counter/2);

    printf("\n\n");

    freeList(valList);
}