#ifndef HELP_FUNCS_H
#define HELP_FUNCS_H

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "linkedlist.h"

void swap(void *x, void *y, size_t size)
{
    void *temp = malloc(size);
    memcpy(temp, y, size);
    memcpy(y, x, size);
    memcpy(x, temp, size);
    free(temp);
}

void funcTime(void (*fp)(struct Node **list), struct Node *lclList, char *funcName)
{
    clock_t start = clock();
    fp(&lclList);
    clock_t end = clock();
    printf("\nTime taken to execute %s: %0.3f ms", funcName, (double) 1000 * (end-start)/CLOCKS_PER_SEC);
}

#endif