#include <stdio.h>
#include <stdlib.h>

#include "avl.h"
#include "bst.h"
#include "arrayOfInts.h"

int main(int argc, char *argv[])
{
    BinNode *avl = NULL;
    BinNode *bst = NULL;

    //Make array
    for(int i = 0; i < sizeof(intArray)/sizeof(int); i++) {
        avl_createNode(&avl, intArray[i]);
        bst_createNode(&bst, intArray[i]);
    }

    printf("Height of tree for AVL after inserting all:\n%d\n", bt_height(avl));
    printf("Height of tree for BST after inserting all:\n%d\n", bt_height(bst));

    printf("\nCount of nodes for AVL after inserting all:\n%d\n", bt_count(avl));
    printf("Count of nodes for AVL after inserting all:\n%d\n", bt_count(bst));

    //Make array
    for(int i=0; i<sizeof(intArray)/sizeof(int); i=i+2) {
        avl_deleteNode(&avl, intArray[i]);
        bst_deleteNode(&bst, intArray[i]);
    }

    printf("\nHeight of tree for AVL after deleting half the values:\n%d\n", bt_height(avl));
    printf("\nHeight of tree for BST after deleting half the values:\n%d\n", bt_height(bst));

    printf("\nCount of nodes for AVL after deleting half the values:\n%d\n", bt_count(avl));
    printf("Count of nodes for BST after deleting half the values:\n%d\n", bt_count(bst));

    bt_free(&bst);
    bt_free(&avl);
}