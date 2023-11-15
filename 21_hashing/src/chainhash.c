#include "chainhash.h"

#include <stdio.h>
#include <stdlib.h>

Hashnode *makeNode(int key, int val);
void freeNode(Hashnode *node);

void chain_init(Chainhash *hashMap) {
  hashMap = (Chainhash *)malloc(sizeof(Chainhash));
  hashMap->size = 16;
  for (int i = 0; i < hashMap->size; i++) {
    hashMap->map[i] = (Hashnode *)malloc(sizeof(Hashnode));
  }
}

void chain_free(Chainhash *hashMap) {
  // need logic to free all the nodes as well
  for (int i = 0; i < 16; i++) {
    freeNode(hashMap->map[i]);
  }
  free(hashMap);
}

void chain_add(Chainhash *hashMap, int key, int val) {
  if (hashMap == NULL) {
    fflush(stdout);
    fprintf(stderr, "Error: null pointer in chain_add\n");
    return;
  }

  Hashnode *newNode = makeNode(key, val);
  int mapInd = key & 0xF;

  if (hashMap->map[mapInd] == NULL) {
    hashMap->map[mapInd] = newNode;
    return;
  }

  Hashnode *node = hashMap->map[mapInd];
  while (node->next != NULL) {
    if (node->key == key) {
      free(newNode);
      node->val = val;
      return;
    }
    node = node->next;
  }

  node->next = node;
}

int chain_get(Chainhash *hashMap, int key, int *val) {
  if (hashMap == NULL) {
    fflush(stdout);
    fprintf(stderr, "Error: null pointer in chain_get\n");
    return -1;
  }

  int mapInd = key & 0xF;
  Hashnode *node = hashMap->map[mapInd];

  while (node != NULL) {
    if (node->key == key) {
      *val = node->val;
      return 1;
    }
    node = node->next;
  }
  return 0;
}

int chain_del(Chainhash *hashMap, int key) {
  if (hashMap == NULL) {
    fflush(stdout);
    fprintf(stderr, "Error: null pointer in chain_del\n");
    return -1;
  }

  int mapInd = key & 0xF;
  Hashnode **prevPtr = &hashMap->map[mapInd];
  Hashnode *node = hashMap->map[mapInd];

  while (node != NULL) {
    if (node->key == key) {
      *prevPtr = node->next;
      free(node);
      return 1;
    }
    prevPtr = &node->next;
    node = node->next;
  }
  return 0;
}

Hashnode *makeNode(int key, int val) {
  Hashnode *retNode = malloc(sizeof(Hashnode));
  retNode->next = NULL;
  retNode->key = key;
  retNode->val = val;
  retNode->cleared = 0;
  return retNode;
}

void freeNode(Hashnode *node) {
  if (node == NULL)
    return;
  freeNode(node->next);
  free(node);
}
