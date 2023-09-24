#ifndef BST_H
#define BST_H

#include "binTree.h"

void bst_createNode(BinNode** rootNode, int val);
void bst_deleteNode(BinNode** rootNode, int val);
void bst_fromPre(BinNode** rootNode, int *arr, int l);

#endif