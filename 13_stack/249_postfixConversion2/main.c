#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
#include <regex.h>

#include "stackarr.h"

char *postfix (char *infix);

int main(int argc, char *argv[])
{
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

    char *postfixExpr = postfix(str);

    printf("Postfix version of:\n\t%s\nis:\n\t%s\n", str, postfixExpr);

    free(postfixExpr);
}

//Some helper functions for postfix
int inLevel(char x) {
    const char lvl[10][30] = {
        "(",    // 0
        "",     // 1
        "+-",   // 2
        "",     // 3
        "*/",   // 4
        "^",    // 5
        "",     // 6
        "",     // 7
        "",     // 8
        ""      // 9
    };

    for(int i = 0; i < sizeof(lvl)/sizeof(lvl[0]); i++) {
        for(int j = 0; lvl[i][j] != '\0'; j++) {
            if(x == lvl[i][j])
                return i;
        }
    }

    return -1;
}

int outLevel(char x) {
    const char lvl[10][30] = {
        ")",    // 0
        "+-",   // 1
        "",     // 2
        "/*",   // 3
        "",     // 4
        "",     // 5
        "^",    // 6
        "(",    // 7
        "",     // 8
        ""      // 9
    };

    for(int i = 0; i < sizeof(lvl)/sizeof(lvl[0]); i++) {
        for(int j = 0; lvl[i][j] != '\0'; j++) {
            if(x == lvl[i][j])
                return i;
        }
    }

    return -1;
}

/**
 * char *postfix - This function uses a stack to re-order an
 * infix expression into a postfix, leading to easier evaluation.
*/
char *postfix(char *infix) {
    
    struct stack *st;
    initStack(&st, 50);

    char *postfixExpr = (char*) malloc(50);
    int cnt = 0;

    for(int i = 0; infix[i] != '\0'; i++) {
        char curr = infix[i];
        int currLevel = outLevel(curr);
        
        //If variable, which is level -1
        if(currLevel == -1) {
            postfixExpr[cnt++] = curr;
            continue;
        }

        if(isEmpty(st)) {
            push(st, curr);
            continue;
        }

        //If encountering right-side bracket
        if(currLevel == 0) {
            while(inLevel(peek(st)) != 0)
                postfixExpr[cnt++] = pop(st); 
            pop(st);
            continue;
        }

        char top = peek(st);
        int topLevel = inLevel(top);

        if(currLevel < topLevel) {
            while(currLevel < inLevel(peek(st)))
            {
                postfixExpr[cnt++] = pop(st);
                if(isEmpty(st))
                    break;
            }
            push(st, curr);
        } else {
            push(st, curr);
        }
    }

    while(!isEmpty(st))
        postfixExpr[cnt++] = pop(st);

    postfixExpr[cnt] = '\0';

    freeStack(&st);

    return postfixExpr;
}
