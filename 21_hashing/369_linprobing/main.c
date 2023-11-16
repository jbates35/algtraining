#include "linprobe.h"

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  Linhash map;
  map.size = 5;
  map.entries = 0;

  // Make a set of 20 random keys
  int keys[17] = {0x4,  0x14, 0x24, 0x34, 0x44, 0x54, 0x64, 0x74, 0x84,
                  0x94, 0xA4, 0xB4, 0xC4, 0xD4, 0xE4, 0xF4, 0x104};
  // Make a set of 20 random values
  int vals[17] = {102, 523, 643, 153, 262, 193, 253, 206, 234,
                  156, 142, 523, 364, 153, 253, 162, 623};

  for (int i = 0; i < 17; i++)
    linprobe_add(&map, keys[i], vals[i]);
}
