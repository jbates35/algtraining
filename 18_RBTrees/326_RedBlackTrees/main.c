#include <stdio.h>
#include <stdlib.h>

#include "redblack.h"

int main(int argc, char *argv[]) {
  RBTree rb_tree;
  rb_tree.size = 0;
  rb_tree.root = NULL;

  int vars[] = {6, 8, 7};
  for (int i = 0; i < sizeof(vars) / sizeof(int); i++) {
    rb_insertNode(&rb_tree, vars[i]);
  }
  int a = 1;
  rl(&rb_tree, rb_tree.root);
  a=2;
  return 0;

}
