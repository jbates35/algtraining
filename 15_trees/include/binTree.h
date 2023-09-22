#ifndef BIN_TREE_H
#define BIN_TREE_H

typedef struct BinNode {
    int val;
    struct BinNode *lchild;
    struct BinNode *rchild;
} BinNode;

//Create entire tree from list of vals
void bt_createTree(BinNode **rootNode, int* arr, int length);
void bt_free(BinNode **rootNode);
void bt_preOrder(BinNode *rootNode);
void bt_inOrder(BinNode *rootNode);
void bt_postOrder(BinNode *rootNode);
void bt_levelOrder(BinNode *rootNode);
int bt_count(BinNode *rootNode);
int bt_height(BinNode *rootNode);
int student_challenge(BinNode *rootNode);

//Create a single node with its parameters initialized
BinNode* bt_createNode(int val);

#endif