#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>

#include "avl.h"

int main(int argc, char *argv[])
{
    int c;
    opterr = 0;
    char *str;
    char *token;
    const char s[2] = " ";
    int size=100;

    while ((c = getopt(argc, argv, "x:")) != -1) {
        switch (c) {
        case 'x':
            str = optarg;
            break;
        }
    }

    BinNode *avl = NULL;

    token = strtok(str, s);
    while(token != NULL) {
        avl_createNode(&avl, atoi(token));
        token = strtok(NULL, s);
    }

    printf("Balance is ... %d\n", checkBSTBalance(avl));
}