#ifndef BIN_TREE_H
#define BIN_TREE_H

typedef struct BinNode {
    struct BinNode *lchild;
    struct BinNode *rchild;
    int val;    
} BinNode;

//Create entire tree from list of vals
int bt_createTree(BinNode **rootNode, int* arr, int length);

//Create a single node with its parameters initialized
BinNode* bt_createNode(int val);

#endif