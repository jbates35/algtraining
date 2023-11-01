#include "redblack.h"

#include <stdio.h>
#include <stdlib.h>

RBNode *rb_createNode(int val);

// Local functions
void insertSortNode(RBTree *tree, RBNode *node);
void deleteSortNode(RBTree *tree, RBNode *node);

int insertFindRotate(RBNode *node);
int deleteFindRotate(RBNode *node);

void doNothing(RBTree *tree, RBNode *newNode);
void ll(RBTree *tree, RBNode *newNode);
void lr(RBTree *tree, RBNode *newNode);
void rl(RBTree *tree, RBNode *newNode);
void rr(RBTree *tree, RBNode *newNode);
void switchColor(RBTree *tree, RBNode *newNode);

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

  insertSortNode(tree, newNode);
}

void rb_deleteNode(RBTree *tree, int val) {
  if (tree == NULL) {
    fflush(stdout);
    fprintf(stderr, "\nError in rb_deleteNode: NULL PTR\n");
    return;
  }

  RBNode *node = tree->root;
  RBNode **parentLink_ptr;

  while (node != NULL && node->val != val) {
    node = node->val > val ? node->lchild : node->rchild;
    parentLink_ptr = node->val > val ? &node->lchild : &node->rchild;
  }
  if (node == NULL)
    return;

  // Can dump this into a function which returns an int
  // for instance, if the node is red in this scenario, we can return 0 for
  // doNothing
  RBNode *delNode = node;

  if (node->lchild != NULL && node->rchild != NULL) {
    delNode = node->lchild;
    parentLink_ptr = &node->lchild;

    while (delNode->rchild != NULL) {
      delNode = delNode->rchild;
      parentLink_ptr = &delNode->rchild;
    }

    (*parentLink_ptr) = delNode->lchild;
    if ((*parentLink_ptr) != NULL)
      (*parentLink_ptr)->parent = delNode->parent;

  } else if (node->lchild != NULL || node->rchild != NULL) {
    delNode = node->lchild != NULL ? node->lchild : node->rchild;

    node->lchild = delNode->lchild;
    if (node->lchild)
      node->lchild->parent = node;

    node->rchild = delNode->rchild;
    if (node->rchild)
      node->rchild->parent = node;
  }

  node->val = delNode->val;
  free(delNode);

  /*
    // Node is red, can delete and find in-order left, and all the way right
    if (node->color == RED) {

      // If node has no children, just delete node
      if (node->lchild == NULL && node->rchild == NULL) {
        *parentLink = NULL;
        free(node);
        return;
        // If node has one child, change parent/child and delete node
      } else if (node->lchild == NULL || node->rchild == NULL) {
        *parentLink = node->lchild == NULL ? node->rchild : node->lchild;
        (*parentLink)->parent = node->parent;
        free(node);
        return;
      } else {
        // This is now when there are two childnodes
        RBNode *replaceNode = node->lchild;

        if (replaceNode->rchild != NULL) {
          node->lchild = replaceNode->lchild;
          node->lchild->parent = node;
          node->lchild->color = BLACK; } else {
          while (replaceNode->rchild != NULL)
            replaceNode = replaceNode->rchild;
          replaceNode->parent->rchild = replaceNode->lchild;
          if (replaceNode->lchild)
            replaceNode->lchild->parent = replaceNode->parent;
        }

        node->val = replaceNode->val;
        free(replaceNode);
        return;
      }
    }
    */
  //  deleteSortNode(tree, node);
}

void insertSortNode(RBTree *tree, RBNode *node) {
  if (node == NULL) {
    fflush(stdout);
    fprintf(stderr, "\nError in insertSortNode: Null pointer\n");
    return;
  }

  RBNode *parent = node->parent;

  if (parent->color == BLACK)
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
    switchColor(tree, node);
  else {
    void (*fp[5])(RBTree *, RBNode *) = {doNothing, ll, lr, rl, rr};
    (*fp[insertFindRotate(node)])(tree, node);
    tree->root->color = BLACK;
  }
}

void deleteSortNode(RBTree *tree, RBNode *node) {
  if (node == NULL) {
    fflush(stdout);
    fprintf(stderr, "\nError in insertSortNode: Null pointer\n");
    return;
  }
}

/**
 * @brief Create a new node but only in the sense that it initializes the node
 *
 * @param val Value the node to represent
 * @return RBNode* Pointer of node which can be used for further
 * implementation
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

int insertFindRotate(RBNode *rootNode) {
  RBNode *parent = rootNode->parent;
  if (parent == NULL)
    return 0;

  RBNode *grandparent = parent->parent;
  if (grandparent == NULL)
    return 0;

  int returnVal = 0;
  if (parent->val < grandparent->val)
    returnVal = rootNode->val < parent->val ? 1 : 2;
  else
    returnVal = rootNode->val < parent->val ? 3 : 4;

  return returnVal;
}

void doNothing(RBTree *tree, RBNode *newNode) {}

void ll(RBTree *tree, RBNode *newNode) {
  RBNode *parent = newNode->parent;
  RBNode *grandparent = parent->parent;

  RBNode **newRootLink;
  RBNode *ggrandparent = grandparent->parent;

  if (ggrandparent == NULL)
    newRootLink = &tree->root;
  else
    newRootLink = grandparent->val < ggrandparent->val ? &ggrandparent->lchild
                                                       : &ggrandparent->rchild;

  *newRootLink = parent;
  parent->parent = ggrandparent;

  grandparent->lchild = parent->rchild;
  if (grandparent->lchild)
    grandparent->lchild->parent = grandparent;

  parent->rchild = grandparent;
  grandparent->parent = parent;

  parent->color = BLACK;
  grandparent->color = RED;
}

void lr(RBTree *tree, RBNode *newNode) {
  RBNode *parent = newNode->parent;
  RBNode *grandparent = parent->parent;

  RBNode **newRootLink;
  RBNode *ggrandparent = grandparent->parent;

  if (ggrandparent == NULL)
    newRootLink = &tree->root;
  else
    newRootLink = grandparent->val < ggrandparent->val ? &ggrandparent->lchild
                                                       : &ggrandparent->rchild;

  *newRootLink = newNode;
  newNode->parent = ggrandparent;

  grandparent->lchild = newNode->rchild;
  if (grandparent->lchild)
    grandparent->lchild->parent = grandparent;

  parent->rchild = newNode->lchild;
  if (parent->rchild)
    parent->rchild->parent = parent;

  newNode->rchild = grandparent;
  newNode->lchild = parent;
  parent->parent = newNode;
  grandparent->parent = newNode;

  newNode->color = BLACK;
  grandparent->color = RED;
}

void rl(RBTree *tree, RBNode *newNode) {
  RBNode *parent = newNode->parent;
  RBNode *grandparent = parent->parent;

  RBNode **newRootLink;
  RBNode *ggrandparent = grandparent->parent;

  if (ggrandparent == NULL)
    newRootLink = &tree->root;
  else
    newRootLink = grandparent->val < ggrandparent->val ? &ggrandparent->lchild
                                                       : &ggrandparent->rchild;

  *newRootLink = newNode;
  newNode->parent = ggrandparent;

  grandparent->rchild = newNode->lchild;
  if (grandparent->rchild)
    grandparent->rchild->parent = grandparent;

  parent->lchild = newNode->rchild;
  if (parent->lchild)
    parent->lchild->parent = parent;

  newNode->lchild = grandparent;
  newNode->rchild = parent;
  parent->parent = newNode;
  grandparent->parent = newNode;

  newNode->color = BLACK;
  grandparent->color = RED;
}

void rr(RBTree *tree, RBNode *newNode) {
  RBNode *parent = newNode->parent;
  RBNode *grandparent = parent->parent;

  RBNode **newRootLink;
  RBNode *ggrandparent = grandparent->parent;

  if (ggrandparent == NULL)
    newRootLink = &tree->root;
  else
    newRootLink = grandparent->val < ggrandparent->val ? &ggrandparent->lchild
                                                       : &ggrandparent->rchild;

  *newRootLink = parent;
  parent->parent = ggrandparent;

  grandparent->rchild = parent->lchild;
  if (grandparent->rchild)
    grandparent->rchild->parent = grandparent;

  parent->lchild = grandparent;
  grandparent->parent = parent;

  parent->color = BLACK;
  grandparent->color = RED;
}

void switchColor(RBTree *tree, RBNode *newNode) {
  // Add some protection against uncle being null - esp for recursive call
  RBNode *parent = newNode->parent;
  RBNode *grandparent = parent->parent;
  RBNode *uncle = (parent->val < parent->parent->val) ? parent->parent->rchild
                                                      : parent->parent->lchild;

  parent->color = BLACK;
  grandparent->color = RED;
  if (uncle != NULL)
    uncle->color = BLACK;

  // Make sure that tree starts with blk clr
  if (grandparent->parent == NULL)
    grandparent->color = BLACK;

  // Make sure we don't have two consecutive reds
  else if (grandparent->parent->color == RED)
    insertSortNode(tree, grandparent);
}
