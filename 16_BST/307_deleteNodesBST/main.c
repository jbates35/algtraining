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
        case 'd':
            deleteKey = atoi(optarg);
            break;
        }
    }

    BinNode *bst = NULL;
    
    token = strtok(str, s);
    while(token != NULL) {
        bst_createNode(&bst, atoi(token));
        token = strtok(NULL, s);
    }

    printf("BEFORE DELETING:\n");
    bt_levelOrder(bst);
    bt_inOrder(bst);

    printf("\nDELETING NODE WITH KEY==%d\n", deleteKey);
    bst_deleteNode(&bst, deleteKey);

    bt_levelOrder(bst);
    bt_inOrder(bst);

    bt_free(&bst);
}