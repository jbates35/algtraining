#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

#include "stackll.h"

int main(int argc, char *argv[])
{
    struct sNode *st = NULL;

    char str[] = "1 3 2 4 9 3";
    char* token;
    char s[2] = " ";

    token = strtok(str, s);
    while(token != NULL)
    {
        printf("\nPushing %d...", atoi(token));
        push(&st, atoi(token));
        token = strtok(NULL, s);
    }

    while(!isEmpty(st))
        printf("\nPopped %d", pop(&st));

    printf("\nAttempting to pop one more time...");
    pop(&st);
    printf("\n\n");

    freeStack(st);
}