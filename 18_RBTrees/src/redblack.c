#include "redblack.h"

#include <stdio.h>
#include <stdlib.h>

RBNode* rb_createNode(int val);

//Local functions
void sortNode(RBTree *tree, RBNode *root);
void switchColor(RBNode *rootNode);
void doNothing(RBNode **rootNode);
void ll(RBNode **rootNode);
void lr(RBNode **rootNode);
void rl(RBNode **rootNode);
void rr(RBNode **rootNode);

void rb_init(RBTree *tree) {
     
}


void rb_free(RBTree *tree) {

}



void rb_insertNode(RBTree *tree, int val) {
    if(tree==NULL) {
        fflush(stdout);
        fprintf(stderr, "\nError in rb_insertNode: NULL PTR\n");
        return;
    }

    RBNode *newNode = rb_createNode(val);

    //If tree is empty, we know it's first node so fill it in
    if(tree->root == NULL) {
        newNode->color = BLACK;
        tree->root = newNode;
        tree->size++;
        return;
    }

    RBNode *p = tree->root;
    RBNode **q_ptr;
    RBNode *q;

    while(p != NULL) {
        if(newNode->val == p->val) {
            free(newNode);
            return;
        }

        q = p;
        q_ptr = (newNode->val < p->val) ? &(p->lchild) : &(p->rchild);
        p = (newNode->val < p->val) ? p->lchild : p->rchild;
    }

    *q_ptr = newNode;
    newNode->parent = q;
    
    sortTree(tree, newNode);
}


void rb_deleteNode(RBTree *tree, int val) {

}



void switchColor(RBNode *rootNode) {
    
}

/**
 * @brief Create a new node but only in the sense that it initializes the node
 * 
 * @param val Value the node to represent
 * @return RBNode* Pointer of node which can be used for further implementation
 */
RBNode* rb_createNode(int val) {
    RBNode *newNode = (RBNode*) malloc(sizeof(RBNode));
    
    newNode->color = RED;
    newNode->val = val;

    newNode->lchild = NULL;
    newNode->rchild = NULL;
    newNode->parent = NULL;

    return newNode;
}


void sortNode(RBTree *tree, RBNode *root) {

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