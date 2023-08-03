#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

#include "stackarr.h"

int main(int argc, char *argv[])
{
    struct stack *st;
    initStack(&st, 5);

    char str[] = "1 3 2 4 9 3";
    char* token;
    char s[2] = " ";

    token = strtok(str, s);
    while(token != NULL)
    {
        printf("\nPushing %d...", atoi(token));
        if(!push(st, atoi(token)))
            printf("\nLast entry: %d", peek(st));
        token = strtok(NULL, s);
    }

    while(!isEmpty(st))
        printf("\nPopped %d", pop(st));

    printf("\nAttempting to pop one more time...");
    pop(st);
    printf("\n\n");

    freeStack(&st);
}