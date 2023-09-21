#include "binTree.h"
#include "queueCircular.h"
#include "stackarr.h"

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

    while(!queueIsEmpty(q) && cnt<length) {
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

//TODO: Do this later
void bt_free(BinNode **rootNode) {

}

void bt_preOrder(BinNode *rootNode){
    printf("Pre-order tree traversal: ");
    
    BinNode* p = rootNode;
    //For stuffing pointers in
    Stack *s;
    initStack(&s, 1000);

    while(p != NULL || !isEmpty(s)) {
        if(p != NULL) {
            printf("%d ", p->val);
            push(s, p);
            p = p->lchild;
        } else {
            p = pop(s);
            p = p->rchild;
        }
    }

    printf("\n");
    freeStack(&s);
}

void bt_inOrder(BinNode *rootNode){
    printf("In-order tree traversal: ");
    
    BinNode* p = rootNode;
    //For stuffing pointers in
    Stack *s;
    initStack(&s, 1000);
    
    while(p != NULL || !isEmpty(s)) {
        if(p != NULL) {
            push(s, p);
            p = p->lchild;
        } else {
            p = pop(s);
            printf("%d ", p->val);
            p = p->rchild;
        }
    }

    printf("\n");
    freeStack(&s);
}

void bt_levelOrder(BinNode *rootNode) {

    printf("Level-order tree traversal: ");
    
    BinNode* p = rootNode;

    //For stuffing pointers in
    Queue *q;
    initQueue(&q, 1000);
    enqueue(q, p);

    while(!queueIsEmpty(q)) {
        p = dequeue(q);

        printf("%d ", p->val);

        if(p->lchild != NULL)
            enqueue(q, p->lchild);

        if(p->rchild != NULL)
            enqueue(q, p->rchild);
    }

    printf("\n");
    freeQueue(&q);
}

void bt_count(BinNode *rootNode) {
    
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

