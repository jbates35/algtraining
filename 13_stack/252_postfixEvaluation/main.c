#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
#include <regex.h>

#include "stackarr.h"

int solve (char exp[50][50]);

int main(int argc, char *argv[])
{
    int c;
    opterr = 0;
    char *str;
    char *token;
    const char s[2] = " ";

    while ((c = getopt(argc, argv, "x:")) != -1) {
        switch (c) {
        case 'x':
            str = optarg;
            break;
        }
    }

    printf("%s\n", str);
    char expression[50][50];

    token = strtok(str, s);
    int cnt = 0;
    while(token != NULL) {
        int i = 0;
        for(i = 0; token[i] != '\0'; i++) {
            expression[cnt][i] = token[i];
        }
        expression[cnt][i] = '\0';
        cnt++;
        token = strtok(NULL, s);
    }
    expression[cnt][0] = '\0';
    
    printf("Answer for expression:\n%s\n\nis:\n%d\n", str, solve(expression));
    
}


/**
 * char *postfix - This function uses a stack to re-order an
 * infix expression into a postfix, leading to easier evaluation.
*/
int solve (char exp[50][50]) {
    
    struct stack *st;
    int answer = 0;
    initStack(&st, 50);

    freeStack(&st);

    return answer;
}
