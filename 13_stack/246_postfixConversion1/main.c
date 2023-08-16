#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
#include <regex.h>

#include "stackarr.h"

char *postfix (struct stack *st, char *infix);

int main(int argc, char *argv[])
{
    struct stack *st;
    initStack(&st, 50);

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

    char *postfixExpr = postfix(st, str);

    printf("Postfix version of:\n\t%s\nis:\n\t%s\n", str, postfixExpr);

    free(postfixExpr);
    freeStack(&st);
}

//Some helper functions for postfix
int level(char x) {
    const char* lvl2 = "*/";
    const char* lvl1 = "+-";

    for(int i = 0; lvl2[i] != '\0'; i++) {
        if(x == lvl2[i])
            return 2;
    }

    for(int i = 0; lvl1[i] != '\0'; i++) {
        if(x == lvl1[i])
            return 1;
    }

    return 0;
}

/**
 * char *postfix - This function uses a stack to re-order an
 * infix expression into a postfix, leading to easier evaluation.
*/
char *postfix(struct stack *st, char *infix) {
    
    char *postfixExpr = (char*) malloc(50);
    int cnt = 0;

    for(int i = 0; infix[i] != '\0'; i++) {
        char curr = infix[i];
        int currLevel = level(curr);

        if(currLevel == 0) {
            postfixExpr[cnt++] = curr;
            continue;
        }

        if(isEmpty(st)) {
            push(st, curr);
            continue;
        }

        char top = peek(st);
        if(currLevel < level(top)) {
            postfixExpr[cnt++] = pop(st);
            postfixExpr[cnt++] = curr;
        } else {
            push(st, curr);
        }
    }

    while(!isEmpty(st))
        postfixExpr[cnt++] = pop(st);

    postfixExpr[cnt] = '\0';
    return postfixExpr;
}
