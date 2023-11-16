#include "chainhash.h"

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  Chainhash *map;
  int asdf = 0;
  chain_init(&map);
  asdf = 2;
  // Make a set of 20 random keys
  int keys[20] = {30, 20, 59, 2,  95, 23, 25, 29, 21, 12,
                  67, 56, 70, 15, 66, 42, 7,  77, 24, 53};
  // Make a set of 20 random values
  int vals[20] = {102, 523, 643, 153, 262, 193, 253, 206, 234, 156,
                  142, 523, 364, 153, 253, 162, 623, 253, 206, 234};

  for (int i = 0; i < 20; i++)
    chain_add(map, keys[i], vals[i]);

  int sampleKeys[4] = {20, 2, 95, 23};
  for (int i = 0; i < 4; i++) {
    int val;
    chain_get(map, sampleKeys[i], &val);
    printf("Value for key %d is:\t%d\n", sampleKeys[i], val);
  }

  int val;
  printf("Value for key 66 is:\t%d\n", val);

  if (!chain_del(map, 66))
    printf("Deleting key 66 unsuccessful\n");

  if (!chain_get(map, 66, &val))
    printf("Unable to get key 66\n");
  else
    printf("Value for key 66 is:\t%d\n", val);

  chain_free(map);
}
