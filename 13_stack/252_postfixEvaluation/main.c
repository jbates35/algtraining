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

    printf("Answer for expression:\n%s\n", str);
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
    
    printf("\nis:\n%d\n", solve(expression));
    
}

int level(char x) {

    if(x=='+') 
        return 1;
    if(x=='-') 
        return 2;
    if(x=='*') 
        return 3;
    if(x=='/') 
        return 4;
    if(x=='^')
        return 5;
    
    return 0;
}

int add(int x, int y) {
    return x + y;
}

int sub(int x, int y) {
    return x - y;
}

int mult(int x, int y) {
    return x * y;
}

int divide(int x, int y) {
    return x / y;
}

int exponent(int x, int y) {
    int retVal = 1;
    for(int i = 0; i < y; i++)
        retVal *= x;
    return retVal;
}

/**
 * char *postfix - This function uses a stack to re-order an
 * infix expression into a postfix, leading to easier evaluation.
*/
int solve (char exp[50][50]) {    
    struct stack *st;
    int answer = 0;
    initStack(&st, 50);
    
    int (*fp[5])(int, int) = {
        &add,
        &sub,
        &mult,
        &divide,
        &exponent
    };

    for(int i = 0; exp[i][0] != '\0'; i++) {

        //If operator, do some math and return the val to the stack
        if(level(exp[i][0])) {
            int y = pop(st);
            int x = pop(st);    

            int val = fp[level(exp[i][0])-1](x, y);

            push(st, val);
            continue;
        }

        //Else, push value to stack
        int val = atoi(exp[i]);
        push(st, val);
    }

    answer = pop(st);

    freeStack(&st);

    return answer;
}
