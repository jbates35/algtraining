#include "binTree.h"
#include "queueCircular.h"

#include <stdio.h>
#include <stdlib.h>

int bt_createTree(BinNode **rootNode, int* arr, int length) {
    if(rootNode == NULL || arr == NULL) {
        fflush(stdout);
        fprintf(stderr, "ERROR: Null pointer in bt_createTree\n");
    }

    if (length==0) {
        fflush(stdout);
        fprintf(stderr, "ERROR: Not enough values in bt_createTree arr");
    }
    
    int cnt = 0;

    //For stuffing pointers in
    Queue *q;
    initQueue(&q, length);

    //First, create root node
    *rootNode = bt_createNode(arr[cnt++]);
    enqueue(q, (*rootNode));

    BinNode *p, *t;

    while(!queueIsEmpty(q)) {

    }
    
    //Then, add dem elements
    freeQueue(&q); 
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

