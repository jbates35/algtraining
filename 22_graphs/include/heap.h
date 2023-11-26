#include <stdio.h>
#include <stdlib.h>

#include "graphs.h"

void heap_print(Edge A[], int N);
void heap_sort(Edge A[], int N);
void heap_insert(Edge A[], int N, int n);
void heap_create(Edge A[], int N);
Edge heap_delete(Edge A[], int *N);
