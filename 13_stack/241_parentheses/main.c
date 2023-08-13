#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

#include "stackarr.h"

int parenthMatches(struct stack *st, char *exp);

int main(int argc, char *argv[])
{
    struct stack *st;
    initStack(&st, 20);

    int c;
    opterr = 0;
    char *str;
    while ((c = getopt(argc, argv, "x:")) != -1)
    {
        switch (c)
        {
        case 'x':
            str = optarg;
            break;
        }
    }

    printf("Analyzing expression: %s", str);
    if(parenthMatches(st, str))
        printf("\nParentheses match\n");
    else
        printf("\nParentheses don't match\n");

    freeStack(&st);
}

int parenthMatches(struct stack *st, char *exp)
{
    for(int i = 0; exp[i] != '\0'; i++)
    {
        if(exp[i] != '(' && exp[i] != ')')
            continue;

        if(exp[i] == '(')
        {
            push(st, 1);
            continue;
        }

        //At this point, it means the character is ')'
        if(isEmpty(st))
            return 0;
        
        pop(st);
    }

    return isEmpty(st);
}