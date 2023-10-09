#ifndef RED_BLACK_H
#define RED_BLACK_H

typedef enum {
    BLACK,
    RED
} Color_t;

typedef struct RBNode {
    int val;
    Color_t color;
    struct RBNode *parent;
    struct RBNode *lchild;
    struct RBNode *rchild;
} RBNode;

typedef struct RBTree {
    int size;
    struct RBNode *root;
} RBTree;

#endif

void rb_init(RBTree *tree);
void rb_free(RBTree *tree);

void rb_insertNode(RBTree *tree, int val);
void rb_deleteNode(RBTree *tree, int val);

