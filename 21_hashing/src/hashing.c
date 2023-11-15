#include "hashing.h"

#include <stdio.h>
#include <stdlib.h>

Hashnode *makeNode(int key, int val);

void chain_init(Chainhash *hashmap) {
  hashmap = (Chainhash *)malloc(sizeof(Chainhash));
  hashmap->size = 16;
}

void chain_free(Chainhash *hashmap) {
  // need logic to free all the nodes as well

  free(hashmap);
}

void chain_add(Chainhash *hashmap, int key, int val) {
  if (hashmap == NULL) {
    fflush(stdout);
    fprintf(stderr, "Error: null pointer in chain_add\n");
    return;
  }
}

Hashnode *makeNode(int key, int val) {
  Hashnode *retNode = malloc(sizeof(Hashnode));
  retNode->next = NULL;
  retNode->key = key;
  retNode->val = val;
  retNode->cleared = 0;
  return retNode;
}
