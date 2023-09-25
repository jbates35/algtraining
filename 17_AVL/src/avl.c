#include "avl.h"
#include "stackarr.h"

#include <stdio.h>
#include <stdlib.h>

/*
For reference, BinNode is:

typedef struct BinNode {
    int val;
    struct BinNode *lchild;
    struct BinNode *rchild;
} BinNode;
*/

void avl_createNode(BinNode** rootNode, int val) {    
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

void avl_deleteNode(BinNode** rootNode, int val) {
    BinNode *p = *rootNode;

    int lastDir;    

    //First find the node
    //For searching later - GOOD USE CASE OF DOUBLE POINTER
    while(p != NULL && p->val != val) {
        if(p->val > val) {
            rootNode = &p->lchild;
            p = p->lchild;
        } else {
            rootNode = &p->rchild;
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
        *rootNode = NULL;
        free(p);
        return;
    }

    //Situation 2 - one child node
    if(p->rchild == NULL || p->lchild == NULL) {
        if(p->rchild == NULL)
            *rootNode = p->lchild;
        else
            *rootNode = p->rchild;

        free(p);
        return;
    }

    //Situation 3 - both child nodes
    //Need inorder search to find the right most node of lchild
    //Break the link from the previous node, reattach it to the semi-leaf node
    //Assign the new node's lchild to the previously broken link... This is easier to explain with a diagram
    BinNode *keyToDelete = p;

    BinNode **lastPtr = &p->lchild;
    p=p->lchild;

    while(p->rchild!=NULL) {
        lastPtr = &p->rchild;
        p=p->rchild;
    }

    *lastPtr = p->lchild;
    p->rchild=keyToDelete->rchild;
    p->lchild=keyToDelete->lchild;
    free(keyToDelete);
    *rootNode = p;
}

void avl_fromPre(BinNode** rootNode, int *arr, int l) {    
    if(l==0)
        return;
    
    //Init stack for pushing previous nodes in
    Stack *st;
    initStack(&st, 1000);

    //Stuff first node in
    *rootNode = bt_createNode(arr[0]);
    BinNode *p = *rootNode;

    for(int i = 1; i < l; i++) {
        BinNode *next = bt_createNode(arr[i]);

        //If value is lower than previous val
        if(next->val < p->val) {
            p->lchild = next;
            push(st, p);
            p=next;
            continue;
        }

        //Otherwise, value is higher than previous val
        //But we have to see the correct place to assign rchild
        while(!isEmpty(st) && !(p->val < next->val && next->val < peek(st)->val))
            p = pop(st);

        p->rchild = next;
        p = next;
    }

    freeStack(&st);
}

void avl_rotateNode(BinNode* rootNode) {
    void (*rotate[4]) (BinNode *rootNode) = { doNothing, ll, lr, rl, rr };
    (*rotate[checkBSTBalance(rootNode)])(rootNode);
}

int checkBSTBalance(BinNode* rootNode) {
    //0 means is balanced - do nothing
    //1 is LL means pos, pos
    //2 is LR means pos, neg
    //3 is RL means neg, pos
    //4 is RR means neg, neg

    //First check balance of the overall BST. We are looking for results of 2 (L*), -2 (R*), or -1<h<1 (None)
    int rootBalance = bt_height(rootNode->lchild) - bt_height(rootNode->rchild);
    
    if(-1 <= rootBalance && rootBalance <= 1)
        return 0;

    //If imbalanced, go to next according next node and find balance of that so we can make a decision on the overall balance
    if(rootBalance > 1) {
        BinNode* nextNode = rootNode->lchild;
        int nextBalance = bt_height(nextNode->lchild) - bt_height(nextNode->rchild);
        return (nextBalance > 0) ? 1 : 2;
    } else { 
        BinNode* nextNode = rootNode->rchild;
        int nextBalance = bt_height(nextNode->lchild) - bt_height(nextNode->rchild);
        return (nextBalance > 0) ? 3 : 4;
    }
}

void doNothing(BinNode *rootNode) {
}

void ll(BinNode *rootNode) {

}

void lr(BinNode *rootNode) {

}

void rl(BinNode *rootNode) {

}

void rr(BinNode *rootNode) {

}