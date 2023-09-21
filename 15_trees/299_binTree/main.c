#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>

#include "queueCircular.h"
#include "binTree.h"
#include "arrayAdt.h"

int isAllOnes(int num);

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

    ArrayInt arr;
    int initarr[1] = {-1};
    initADT(&arr, initarr, 10, 0);
    
    char str2[50] = "1 3 -1 4 6 -1 8 -1 4";
    
    //We need 2^n - 1 elements in this array. Therefore,
    //we need a binary integer which is all 1's
    int treeFull = 0;

    token = strtok(str2, s);
    while(token != NULL) {
        treeFull++;
        appendADT(&arr, atoi(token));
        token = strtok(NULL, s);
    }

    while(!isAllOnes(treeFull++))
        appendADT(&arr, -1);

    BinNode *binTree;
    bt_createTree(&binTree, arr.A, arr.length);
   
    freeADT(&arr);
}

int isAllOnes(int num) {
    int retVal = 1;

    if(num == 0)
        return 0;

    while(num > 0) {
        if(num%2 == 0) {
            retVal = 0;
            break;
        }
        num = num>>1;
    }

    return retVal;
}