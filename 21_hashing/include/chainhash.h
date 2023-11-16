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

void chain_init(Chainhash **hashMap);
void chain_free(Chainhash *hashMap);
void chain_add(Chainhash *hashMap, int key, int val);
int chain_get(Chainhash *hashMap, int key, int *val);
int chain_del(Chainhash *hashMap, int key);

#endif
