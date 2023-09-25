#ifndef AVL_H
#define AVL_H

#include "binTree.h"

void avl_createNode(BinNode** rootNode, int val);
void avl_deleteNode(BinNode** rootNode, int val);
void avl_fromPre(BinNode** rootNode, int *arr, int l);
int checkBSTBalance(BinNode* rootNode);

#endif