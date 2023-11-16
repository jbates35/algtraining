#ifndef LINPROBE_H
#define LINPROBE_H

typedef struct Hashnode {
  int key;
  int val;
  int cleared;
} Hashnode;

typedef struct Linhash {
  Hashnode map[16];
  int size;
} Linhash;

int linprobe_add(Linhash *map, int key, int val);
int linprobe_del(Linhash *map, int key, int val);
int linprobe_get(Linhash *map, int key, int *val);

#endif
