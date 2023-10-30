#include <stdio.h>
#include <stdlib.h>

#include "redblack.h"

int main(int argc, char *argv[]) {
  RBTree rb_tree;
  rb_tree.size = 0;
  rb_tree.root = NULL;

  int vars[] = {10, 20, 30, 50, 40, 60, 70, 80, 4, 8};
  for (int i = 0; i < sizeof(vars) / sizeof(int); i++)
    rb_insertNode(&rb_tree, vars[i]);
  
  return 0;
}
