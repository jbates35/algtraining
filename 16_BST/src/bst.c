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