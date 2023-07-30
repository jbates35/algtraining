#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

#include "sparseMatrix.h"

int main(int argc, char *argv[])
{
    struct SparseMatrix *mat;

    initSparseMat(&mat, 5, 5);

    freeSparseMat(&mat);
}