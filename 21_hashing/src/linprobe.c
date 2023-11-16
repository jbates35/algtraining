#include "linprobe.h"
#include <stdio.h>
#include <stdlib.h>

Hashnode makeNode(int key, int val);
int linprobe_add(Linhash *map, int key, int val) {
  if (map == NULL) {
    fflush(stdout);
    fprintf(stderr, "Error: Null pointer in linprobe_add\n");
    return -1;
  }

  int mapInd = key & 0xF;
}

int linprobe_del(Linhash *map, int key, int val) {
  if (map == NULL) {
    fflush(stdout);
    fprintf(stderr, "Error: Null pointer in linprobe_del\n");
    return -1;
  }
}
int linprobe_get(Linhash *map, int key, int *val) {
  if (map == NULL) {
    fflush(stdout);
    fprintf(stderr, "Error: Null pointer in linprobe_get\n");
    return -1;
  }
}

Hashnode makeNode(int key, int val) {
  Hashnode node;
  node.key = key;
  node.val = val;
  node.cleared = 0;
  return node;
}
