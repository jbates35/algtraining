#ifndef LINPROBE_H
#define LINPROBE_H

typedef struct Hashnode {
  int key;
  int val;
  int cleared;
} Hashnode;

typedef struct Linhash {
  Hashnode map[100];
  int entries;
  int size;
} Linhash;

int linprobe_add(Linhash *hashmap, int key, int val);
int linprobe_del(Linhash *hashmap, int key);
int linprobe_get(Linhash *hashmap, int key, int *val);

#endif
