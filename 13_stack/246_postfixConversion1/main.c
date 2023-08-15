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

char *postfix(struct stack *st, char *infix)
{
    char *postfixExpr = (char*) malloc(50);
    int cnt = 0;
    
    //Variables for creating regex and then storing value after using regex
    regex_t reg1, reg2;
    int value1 = regcomp(&reg1, "[-+]", REG_EXTENDED);
    int value2 = regcomp(&reg2, "[*/]", REG_EXTENDED);

    for(int i = 0; infix[i] != '\0'; i++) {

        char outerTempStr[2] = {infix[i], '\0'};

        //First is if multiplication or division is found
        if(!regexec(&reg2, outerTempStr, 0, NULL, 0)) {
                        
            //Get value of last part of stack so we can check if to push it or add it to string
            char innerTempStr[2] = {' ', '\0'};
            if(!isEmpty(st))
                innerTempStr[0] = peek(st) + '\0';

            if(!regexec(&reg1, innerTempStr, 0, NULL, 0))
                push(st, infix[i]);

            else
                postfixExpr[cnt++] = infix[i];
        }

        //Second is if addition or subtraction is found
        else if(!regexec(&reg1, outerTempStr, 0, NULL, 0)){
            
            //Should empty stack as we came across a level 1
            while(!isEmpty(st))
                postfixExpr[cnt++] = pop(st);

            push(st, infix[i]);
        }

        //Otherwise, it's a variable, so write it to the return string
        else 
            postfixExpr[cnt++] = infix[i];
    }

    regfree(&reg1);
    regfree(&reg2);

    while(!isEmpty(st))
        postfixExpr[cnt++] = pop(st);

    postfixExpr[cnt] = '\0';
    return postfixExpr;
}