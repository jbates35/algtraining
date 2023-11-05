#include "redblack.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  RBTree rb_tree;
  rb_tree.size = 0;
  rb_tree.root = NULL;

  int vars[] = {70, 40, 100, 20, 50, 80, 110, 10, 30, 60, 90, 120};
  for (int i = 0; i < sizeof(vars) / sizeof(int); i++)
    rb_insertNode(&rb_tree, vars[i]);
  int asdf = 1;
  rb_deleteNode(&rb_tree, 100);
  asdf = 1;
  rb_deleteNode(&rb_tree, 110);
  asdf = 1;
  rb_deleteNode(&rb_tree, 80);
  asdf = 1;
  rb_deleteNode(&rb_tree, 120);
  asdf = 1;
  rb_deleteNode(&rb_tree, 90);
  asdf = 1;
  return 0;
}
