#ifndef HASHING_H
#define HASHING_H

typedef struct Hashnode {
  struct Hashnode *next;
  int key;
  int val;
  int cleared;
} Hashnode;

typedef struct Chainhash {
  Hashnode *map[16];
  int size;
} Chainhash;

void chain_init(Chainhash *hashmap);
void chain_free(Chainhash *hashmap);
void chain_add(Chainhash *hashmap, int key, int val);

#endif
