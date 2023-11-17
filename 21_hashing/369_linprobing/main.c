#include "linprobe.h"

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  Linhash map;
  map.size = 5;
  map.entries = 0;

  // Make a set of 20 random keys
  int keys[10] = {0x4,  0x14, 0x24, 0x34, 0x44, 0x54,
                  0x64, 0x74, 0x84, 0x94}; // Make a set of 20 random values
  int vals[10] = {102, 523, 643, 153, 262, 193, 253, 206, 234, 392};

  printf("Adding 7 key/vals into a hashmap of size 5...");
  for (int i = 0; i < 7; i++)
    linprobe_add(&map, keys[i], vals[i]);

  int val;

  if (linprobe_get(&map, 0x14, &val) == 1)
    printf("Showing value for key 0x14: \t%d\n", val);
  else
    printf("Key 0x14 does not exist.\n");

  printf("Now deleting val for key 0x14\n");
  linprobe_del(&map, 0x14);

  if (linprobe_get(&map, 0x14, &val) == 1)
    printf("Showing value for key 0x14: \t%d\n", val);
  else
    printf("Key 0x14 does not exist.\n");
}
