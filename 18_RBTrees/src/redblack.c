#include "redblack.h"

#include <stdio.h>
#include <stdlib.h>

RBNode *rb_createNode(int val);

// Local functions
void sortNode(RBTree *tree, RBNode *root);
void switchColor(RBNode *rootNode);
int findRotate(RBNode *rootNode);
void doNothing(RBTree *tree, RBNode *rootNode);
/*
void ll(RBTree *tree, RBNode *newNode);
void lr(RBTree *tree, RBNode *newNode);
void rl(RBTree *tree, RBNode *newNode);
void rr(RBTree *tree, RBNode *newNode);
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
  tree->size++;

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

  if(parent->color==BLACK) 
    return;

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
    (*fp[findRotate(rootNode)])(tree, rootNode); 
  }

  tree->root->color = BLACK;
}

void switchColor(RBNode *rootNode) {
  //Add some protection against uncle being null - esp for recursive call
  RBNode *parent = rootNode->parent;
  RBNode *grandparent = parent->parent;
  RBNode *uncle = (parent->val < parent->parent->val) ? parent->parent->rchild 
                                                      : parent->parent->lchild;

  parent->color = BLACK;
  grandparent->color = RED;
  if(uncle != NULL)
    uncle->color = BLACK;

  //Make sure that tree starts with blk clr
  if(grandparent->parent == NULL)
    grandparent->color = BLACK;

  //Make sure we don't have two consecutive reds
  else if(grandparent->parent->color == RED)
    switchColor(parent);
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

int findRotate(RBNode *rootNode) {
  RBNode *parent = rootNode->parent;
  if(parent==NULL)
    return 0;

  RBNode *grandparent = parent->parent;
  if(grandparent == NULL)
    return 0;

  int returnVal = 0;
  if(parent->val > grandparent->val)
    returnVal = rootNode->val > parent->val ? 1 : 2; 
  else 
    returnVal = rootNode->val > parent->val ? 3 : 4;

  return returnVal;
}

void doNothing(RBTree *tree, RBNode *node) {}

void ll(RBTree *tree, RBNode *newNode) {
  RBNode *parent = newNode->parent;
  RBNode *grandparent = parent->parent;

  RBNode **newRootLink; 
  RBNode *ggrandparent = grandparent->parent;

  if(ggrandparent == NULL) 
    newRootLink = &tree->root;
  else 
    newRootLink = grandparent->val < ggrandparent->val ? &ggrandparent->lchild : &ggrandparent->rchild;
  
  *newRootLink = parent; 
  parent->parent = ggrandparent;

  parent->lchild = grandparent;
  grandparent->parent = parent;

  grandparent->rchild = NULL; //this might have to get fixed

  parent->color = BLACK;
  grandparent->color = RED;


  /*
  RBNode *prevRoot = rootNode;

  RBNode *parentNode = rootNode->parent;
  RBNode **pNodeLink;

  if (parentNode == NULL) 
    pNodeLink = &tree->root;
  else
    pNodeLink = (rootNode->val < parentNode->val) ? &parentNode->lchild
                                                  : &parentNode->rchild;

  *pNodeLink = rootNode->lchild;
  prevRoot->lchild = (*pNodeLink)->rchild;

  if (*pNodeLink != NULL) {
    (*pNodeLink)->parent = parentNode;
    (*pNodeLink)->rchild = prevRoot;
  }

  prevRoot->parent = (*pNodeLink);

  if (prevRoot->lchild != NULL)
    (prevRoot->lchild)->parent = prevRoot;
    */
}

void lr(RBTree *tree, RBNode *newNode) {
  RBNode *parent = newNode->parent;
  RBNode *grandparent = parent->parent;

  RBNode **newRootLink; 
  RBNode *ggrandparent = grandparent->parent;

  if(ggrandparent == NULL) 
    newRootLink = &tree->root;
  else 
    newRootLink = grandparent->val < ggrandparent->val ? &ggrandparent->lchild : &ggrandparent->rchild;
  
  *newRootLink = newNode;
  newNode->parent = ggrandparent;

  newNode->lchild = grandparent;
  newNode->rchild = parent;
  parent->parent = newNode;
  grandparent->parent = newNode;

  parent->lchild = NULL; //This might have to be fixed
  grandparent->rchild = NULL; //This might also have to get fixed

  newNode->color = BLACK;
  grandparent->color = RED;
/*
  RBNode *prevRoot = rootNode;

  RBNode *parentNode = rootNode->parent;
  RBNode **pNodeLink;

  if (parentNode == NULL)
    pNodeLink = &tree->root;
  else
    pNodeLink = (rootNode->val < parentNode->val) ? &parentNode->lchild
                                                  : &parentNode->rchild;

  (*pNodeLink) = (rootNode->lchild)->rchild;
  (*pNodeLink)->parent = parentNode;

  (rootNode->lchild)->rchild = (*pNodeLink)->lchild;
  if((*pNodeLink)->lchild!=NULL)
    (*pNodeLink)->lchild->parent = rootNode->lchild;

  (*pNodeLink)->lchild = rootNode->lchild;
  rootNode->lchild->parent = (*pNodeLink);

  rootNode->lchild = (*pNodeLink)->rchild;
  if((*pNodeLink)->rchild != NULL)
    (*pNodeLink)->rchild->parent = rootNode;

  (*pNodeLink)->rchild = rootNode;
  rootNode->parent = (*pNodeLink);
  */
}


void rl(RBTree *tree, RBNode *newNode) {
  /*
  RBNode *prevRoot = rootNode;

  RBNode *parentNode = rootNode->parent;
  RBNode **pNodeLink;

  if (parentNode == NULL)
    pNodeLink = &tree->root;
  else
    pNodeLink = (rootNode->val < parentNode->val) ? &parentNode->lchild
                                                  : &parentNode->rchild;

  (*pNodeLink) = (rootNode->rchild)->lchild;
  (*pNodeLink)->parent = parentNode;

  (rootNode->rchild)->lchild = (*pNodeLink)->rchild;
  if((*pNodeLink)->rchild != NULL)
    (*pNodeLink)->rchild->parent = rootNode->rchild;

  (*pNodeLink)->rchild = rootNode->rchild;
  rootNode->rchild->parent = (*pNodeLink);

  rootNode->rchild = (*pNodeLink)->lchild;
  if((*pNodeLink)->lchild != NULL)
    (*pNodeLink)->lchild->parent = rootNode;

  (*pNodeLink)->lchild = rootNode;
  rootNode->parent = (*pNodeLink);
*/
}

void rr(RBTree *tree, RBNode *newNode) {
  /*
  RBNode *prevRoot = rootNode;

  RBNode *parentNode = rootNode->parent;
  RBNode **pNodeLink;

  if (parentNode == NULL)
    pNodeLink = &tree->root;
  else
    pNodeLink = (rootNode->val < parentNode->val) ? &parentNode->lchild
                                                  : &parentNode->rchild;

  *pNodeLink = rootNode->rchild;
  prevRoot->rchild = (*pNodeLink)->lchild;

  if (*pNodeLink != NULL) {
    (*pNodeLink)->parent = parentNode;
    (*pNodeLink)->lchild = prevRoot;
  }

  prevRoot->parent = (*pNodeLink);

  if (prevRoot->rchild != NULL)
    (prevRoot->rchild)->parent = prevRoot;
    */
}
