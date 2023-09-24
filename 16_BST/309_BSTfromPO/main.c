#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>

#include "bst.h"

int main(int argc, char *argv[])
{
    int c;
    opterr = 0;
    char *str;
    char *token;
    const char s[2] = " ";
    int size=100;
    int deleteKey = 0;

    while ((c = getopt(argc, argv, "x:d:")) != -1) {
        switch (c) {
        case 'x':
            str = optarg;
            break;
        }
    }

    BinNode *bst = NULL;
    int A[100];
    int l = 0;
    token = strtok(str, s);
    while(token != NULL) {
        A[l++] = atoi(token);    
        token = strtok(NULL, s);
    }

    bst_fromPre(&bst, A, l);

    bt_levelOrder(bst);
    bt_preOrder(bst);
    bt_inOrder(bst);

    bt_free(&bst);
}
