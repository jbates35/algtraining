#include "binTree.h"
#include "queueCircular.h"

#include <stdio.h>
#include <stdlib.h>

void bt_createTree(BinNode **rootNode, int* arr, int length) {
    if(rootNode == NULL || arr == NULL) {
        fflush(stdout);
        fprintf(stderr, "ERROR: Null pointer in bt_createTree\n");
        return;
    }

    if (length==0) {
        fflush(stdout);
        fprintf(stderr, "ERROR: Not enough values in bt_createTree arr");
        return;
    }
    
    int cnt = 0;

    //For stuffing pointers in
    Queue *q;
    initQueue(&q, length);

    //First, create root node
    *rootNode = bt_createNode(arr[cnt++]);
    enqueue(q, (*rootNode));

    BinNode *p;

    while(!queueIsEmpty(q)) {
        p = dequeue(q);

        int leftVal = arr[cnt++];
        int rightVal = arr[cnt++];

        if(leftVal >= 0) {
            p->lchild = bt_createNode(leftVal);
            enqueue(q, p->lchild);
        }

        if(rightVal >= 0) {
            p->rchild = bt_createNode(rightVal);
            enqueue(q, p->rchild);
        }
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

