#include "bst.h"

#include <stdio.h>
#include <stdlib.h>

void bst_createNode(BinNode** rootNode, int val) {    
    //Create new node which will get assigned
    BinNode *newNode = bt_createNode(val);    

    //If nodes doesn't exist, new node should be the first node in the tree
    if(*rootNode == NULL) {
        *rootNode = newNode;
        return;
    }
    
    //Create placeholder nodes
    BinNode *p = *rootNode;
    BinNode *pPrev;

    //Now we have to compare the values until we get to the right spot
    while(1) {
        if(newNode->val == p->val)
            return;

        if(newNode->val < p->val) {
            if(p->lchild == NULL) {
                p->lchild = newNode;
                return;
            } 
            else
                p = p->lchild;
        }
        else {
            if(p->rchild == NULL) {
                p->rchild = newNode; 
                return;
            }
            else
                p = p->rchild;
        }    
    }
} 

void bst_deleteNode(BinNode** rootNode, int val) {
    BinNode *p = *rootNode;
    BinNode **lastPtr = rootNode;

    int lastDir;    

    //First find the node
    //For searching later - GOOD USE CASE OF DOUBLE POINTER
    while(p != NULL && p->val != val) {
        if(p->val > val) {
            lastPtr = &p->lchild;
            p = p->lchild;
        } else {
            lastPtr = &p->rchild;
            p = p->rchild;
        }
    }

    //If null pointer, then a node with that val doesn't exist
    if(p==NULL) {
        printf("Node with %d not found.\n", val);
        return;
    }

    //Three situations:
    //1 - no child nodes
    //2 - one child node
    //3 - two child nodes

    //Situation 1 - no child nodes
    if(p->rchild == NULL && p->lchild == NULL) {
        *lastPtr = NULL;
        free(p);
        return;
    }

    //Situation 2 - one child node
    if(p->rchild == NULL || p->lchild == NULL) {
        if(p->rchild == NULL)
            *lastPtr = p->lchild;
        else
            *lastPtr = p->rchild;

        free(p);
        return;
    }

    //Situation 3 - both child nodes
    //Need inorder search to find the right most node of lchild
    //Break the link from the previous node, reattach it to the semi-leaf node
    //Assign the new node's lchild to the previously broken link... This is easier to explain with a diagram
    BinNode *keyToDelete = p;

    BinNode **changingPtr = &p->lchild;
    p=p->lchild;

    while(p->rchild!=NULL) {
        changingPtr = &p->rchild;
        p=p->rchild;
    }

    *changingPtr = p->lchild;
    p->rchild=keyToDelete->rchild;
    p->lchild=keyToDelete->lchild;
    free(keyToDelete);
    *lastPtr = p;
}