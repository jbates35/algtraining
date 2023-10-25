#include <stdio.h>
#include <stdlib.h>

#include "redblack.h"

int main(int argc, char *argv[]) {
  RBTree rb_tree;
  rb_tree.size = 0;
  rb_tree.root = NULL;

  int vars[] = {5, 6, 7/*, 9, 10, 11, 12, 2, 3, 1*/};
  int asdf=0;
  for (int i = 0; i < sizeof(vars) / sizeof(int); i++) {
    rb_insertNode(&rb_tree, vars[i]);
  }
  asdf=1;
  ll(&rb_tree, rb_tree.root->lchild->lchild);
  asdf=2;
  return 0;

}
