#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void swap(void *x, void *y, size_t size)
{
    void *temp = malloc(size);
    memcpy(temp, y, size);
    memcpy(y, x, size);
    memcpy(x, temp, size);
    free(temp);
}