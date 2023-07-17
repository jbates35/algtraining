#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

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

    struct RNode *valList = NULL;

    token = strtok(str, s);
    while(token != NULL)
    {
        createNodeR(&valList, atoi(token));
        token = strtok(NULL, s);
    }

    printf("Displaying list:\n\t");
    displayNodesR(valList);
    freeNodesR(valList);
    printf("\n\n");
}