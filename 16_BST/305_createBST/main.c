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

    while ((c = getopt(argc, argv, "x:")) != -1) {
        switch (c) {
        case 'x':
            str = optarg;
            break;
        }
    }

    BinNode *bst = NULL;

    token = strtok(str, s);
    while(token != NULL) {
        bst_createNode(&bst, atoi(token));
        token = strtok(NULL, s);
    }

    bt_preOrder(bst);
    bt_inOrder(bst);
    bt_postOrder(bst);
    bt_levelOrder(bst);
}