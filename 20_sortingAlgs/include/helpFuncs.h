#ifndef HELP_FUNCS_H
#define HELP_FUNCS_H

#include <memory.h>
#include <stdlib.h>

void swap(void *x, void *y, size_t varSize) {
  void *temp = malloc(varSize);
  memcpy(temp, y, varSize);
  memcpy(y, x, varSize);
  memcpy(x, temp, varSize);
  free(temp);
}

#endif
