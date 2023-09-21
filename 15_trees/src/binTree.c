#include "binTree.h"

#include <stdio.h>
#include <stdlib.h>

int bt_createTree(BinNode **rootNode, int* arr, int length) {

}

//Create a single node with its parameters initialized
BinNode* bt_createNode(int val) {
    BinNode *retNode;
    retNode = (BinNode*) malloc(sizeof(BinNode));

    retNode->lchild = NULL;
    retNode->rchild = NULL;
    retNode->val = val;

    return retNode;
}
