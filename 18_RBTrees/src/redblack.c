#include "redblack.h"

#include <stdio.h>
#include <stdlib.h>

RBNode *rb_createNode(int val);

// Local functions
void sortNode(RBTree *tree, RBNode *root);
void switchColor(RBNode *rootNode);
void doNothing(RBTree *tree, RBNode *rootNode);
/*void ll(RBTree *tree, RBNode *rootNode);
void lr(RBTree *tree, RBNode *rootNode);
void rl(RBTree *tree, RBNode *rootNode);
void rr(RBTree *tree, RBNode *rootNode);
*/
void rb_init(RBTree *tree) {}

void rb_free(RBTree *tree) {}

void rb_insertNode(RBTree *tree, int val) {
  if (tree == NULL) {
    fflush(stdout);
    fprintf(stderr, "\nError in rb_insertNode: NULL PTR\n");
    return;
  }

  RBNode *newNode = rb_createNode(val);

  // If tree is empty, we know it's first node so fill it in
  if (tree->root == NULL) {
    newNode->color = BLACK;
    tree->root = newNode;
    tree->size++;
    return;
  }

  RBNode *p = tree->root;
  RBNode **q_ptr;

  while (p != NULL) {
    if (newNode->val == p->val) {
      free(newNode);
      return;
    }

    newNode->parent = p;
    q_ptr = (newNode->val < p->val) ? &(p->lchild) : &(p->rchild);
    p = *q_ptr;
  }

  *q_ptr = newNode;

  sortNode(tree, newNode);
}

void rb_deleteNode(RBTree *tree, int val) {}

void sortNode(RBTree *tree, RBNode *rootNode) {
  if (rootNode == NULL) {
    fflush(stdout);
    fprintf(stderr, "\nError in sortNode: Null pointer\n");
    return;
  }

  RBNode *parent = rootNode->parent;
  RBNode *uncle = NULL;

  // Direction of uncle from grandparent - 0 is left, 1 is right
  int uncle_direction = 0;

  Color_t parent_color = BLACK;
  Color_t uncle_color = BLACK;

  if (parent != NULL && parent->parent != NULL) {
    uncle = (parent->val < parent->parent->val) ? (parent->parent)->rchild
                                                : (parent->parent)->lchild;
    // might not need this
    uncle_direction = (parent->val < (parent->parent)->val) ? 1 : 0;
    parent_color = parent->color;
  }

  uncle_color = BLACK;
  if (uncle != NULL)
    uncle_color = uncle->color;

  if (uncle_color == RED)
    switchColor(rootNode);
  else {
    void (*fp[5])(RBTree *, RBNode *) = {doNothing, ll, lr, rl, rr};
  }
}

void switchColor(RBNode *rootNode) {
  RBNode *p = rootNode->parent;

  if (rootNode->color == BLACK) {
  }
}

/**
 * @brief Create a new node but only in the sense that it initializes the node
 *
 * @param val Value the node to represent
 * @return RBNode* Pointer of node which can be used for further implementation
 */
RBNode *rb_createNode(int val) {
  RBNode *newNode = (RBNode *)malloc(sizeof(RBNode));

  newNode->color = RED;
  newNode->val = val;

  newNode->lchild = NULL;
  newNode->rchild = NULL;
  newNode->parent = NULL;

  return newNode;
}

void doNothing(RBTree *tree, RBNode *node) {}

void ll(RBTree *tree, RBNode *rootNode) {
  RBNode *prevRoot = rootNode;

  printf("Hello???");

  RBNode *parentNode = rootNode->parent;
  RBNode **pNodeLink;

  if (parentNode == NULL)
    pNodeLink = &tree->root;
  else
    pNodeLink = (rootNode->val < parentNode->val) ? &parentNode->lchild
                                                  : &parentNode->rchild;

  /// START FROM EHRE NOW - NEED TO REDESIGN FUNCTION SO PARENT NODES CAN
  /// RESPOND TO CHILD NODES
  *pNodeLink = rootNode->lchild;
  (*pNodeLink)->parent = parentNode;

  prevRoot->lchild = (*pNodeLink)->rchild;
  (*pNodeLink)->rchild = prevRoot;

  prevRoot->parent = (*pNodeLink);
  (prevRoot->lchild)->parent = prevRoot;

  /*
  rootNode = rootNode->lchild;
  prevRoot->lchild = rootNode->rchild;
  rootNode->rchild = prevRoot;
  */
}

void lr(RBTree *tree, RBNode *rootNode) {
  /*
  RBNode *prevRoot = *rootNode;

  *rootNode = (prevRoot->lchild)->rchild;
  (prevRoot->lchild)->rchild = (*rootNode)->lchild;
  (*rootNode)->lchild = prevRoot->lchild;
  prevRoot->lchild = (*rootNode)->rchild;
  (*rootNode)->rchild = prevRoot;
*/
}

void rl(RBTree *tree, RBNode *rootNode) {
  /*
   RBNode *prevRoot = *rootNode;

   *rootNode = (prevRoot->rchild)->lchild;
   (prevRoot->rchild)->lchild = (*rootNode)->rchild;
   (*rootNode)->rchild = prevRoot->rchild;
   prevRoot->rchild = (*rootNode)->lchild;
   (*rootNode)->lchild = prevRoot;
   */
}

void rr(RBTree *tree, RBNode *rootNode) {
  /*
  RBNode *prevRoot = *rootNode;

  *rootNode = (*rootNode)->rchild;
  prevRoot->rchild = (*rootNode)->lchild;
  (*rootNode)->lchild = prevRoot;
*/
}
