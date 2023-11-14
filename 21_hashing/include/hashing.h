#ifndef HASHING_H
#define HASHING_H

typedef struct Hashnode {
  struct Hashnode *next;
  int key;
  int val;
} Hashnode;

typedef struct Chainhash {
  Hashnode *map;
  int size;
} Chainhash;

void chain_init(Chainhash *map);

#endif
