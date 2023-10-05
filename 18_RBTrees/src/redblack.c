#include "redblack.h"

#include <stdio.h>
#include <stdlib.h>

RBNode* _rb_createNode(int val);

void switchColor(RBNode *rootNode);
void doNothing(RBNode **rootNode);
void ll(RBNode **rootNode);
void lr(RBNode **rootNode);
void rl(RBNode **rootNode);
void rr(RBNode **rootNode);


/**
 * @brief Create a new node but only in the sense that it initializes the node
 * 
 * @param val Value the node to represent
 * @return RBNode* Pointer of node which can be used for further implementation
 */
RBNode* _rb_createNode(int val) {
    RBNode *newNode = (RBNode*) malloc(sizeof(RBNode));
    
    newNode->color = RED;
    newNode->val = val;

    newNode->lchild = NULL;
    newNode->rchild = NULL;
    newNode->parent = NULL;

    return newNode;
}

void ll(RBNode **rootNode) { 
    RBNode *prevRoot = *rootNode;

    *rootNode = (*rootNode)->lchild;
    prevRoot->lchild = (*rootNode)->rchild;
    (*rootNode)->rchild = prevRoot;
}

void lr(RBNode **rootNode) {
    RBNode *prevRoot = *rootNode;
    
    *rootNode = (prevRoot->lchild)->rchild;
    (prevRoot->lchild)->rchild = (*rootNode)->lchild;
    (*rootNode)->lchild = prevRoot->lchild;
    prevRoot->lchild = (*rootNode)->rchild;
    (*rootNode)->rchild = prevRoot;
}

void rl(RBNode **rootNode) {
    RBNode *prevRoot = *rootNode;
    
    *rootNode = (prevRoot->rchild)->lchild;
    (prevRoot->rchild)->lchild = (*rootNode)->rchild;
    (*rootNode)->rchild = prevRoot->rchild;
    prevRoot->rchild = (*rootNode)->lchild;
    (*rootNode)->lchild = prevRoot;
}

void rr(RBNode **rootNode) {
    RBNode *prevRoot = *rootNode;

    *rootNode = (*rootNode)->rchild;
    prevRoot->rchild = (*rootNode)->lchild;
    (*rootNode)->lchild = prevRoot;
}