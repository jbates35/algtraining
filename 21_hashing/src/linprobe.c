#include "linprobe.h"
#include <stdio.h>
#include <stdlib.h>

Hashnode makeNode(int key, int val);
int linprobe_add(Linhash *hashmap, int key, int val) {
  if (hashmap == NULL) {
    fflush(stdout);
    fprintf(stderr, "Error: Null pointer in linprobe_add\n");
    return -1;
  }

  int mapInd = key % hashmap->size;

  for (int i = 0; i < hashmap->size; i++) {
    int entryBit = (1 << (mapInd + i) % hashmap->size |
                    1 >> (hashmap->size - mapInd - i) % hashmap->size);

    if ((hashmap->entries & entryBit) != 0 &&
        hashmap->map[(mapInd + i) % hashmap->size].key != key)
      continue;

    hashmap->map[(mapInd + i) % hashmap->size] = makeNode(key, val);
    hashmap->entries |= entryBit;
    printf("TESTING: Entry added at %d\n", (mapInd + i) % hashmap->size);
    return 1;
  }
  fflush(stdout);
  fprintf(stderr, "Error: Hashmap is full (in linprobe_add)\n");
  return 0;
}

int linprobe_del(Linhash *hashmap, int key) {
  if (hashmap == NULL) {
    fflush(stdout);
    fprintf(stderr, "Error: Null pointer in linprobe_del\n");
    return -1;
  }

  int mapInd = key % hashmap->size;

  for (int i = 0; i < hashmap->size; i++) {
    if (hashmap->map[(mapInd + i) % hashmap->size].key != key)
      continue;

    hashmap->map[(mapInd + i) % hashmap->size].cleared = 1;
    return 1;
  }

  return 0;
}
int linprobe_get(Linhash *hashmap, int key, int *val) {
  if (hashmap == NULL) {
    fflush(stdout);
    fprintf(stderr, "Error: Null pointer in linprobe_get\n");
    return -1;
  }

  int mapInd = key % hashmap->size;

  for (int i = 0; i < hashmap->size; i++) {
    int ind = (mapInd + i) % hashmap->size;

    if (hashmap->map[ind].cleared == 1 || hashmap->map[ind].key != key)
      continue;

    *val = hashmap->map[ind].val;
    return 1;
  }
  return 0;
}

Hashnode makeNode(int key, int val) {
  Hashnode node;
  node.key = key;
  node.val = val;
  node.cleared = 0;
  return node;
}
