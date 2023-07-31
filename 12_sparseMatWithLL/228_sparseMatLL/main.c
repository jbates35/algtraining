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

    appendSparseMat(mat, 42, 0, 0);
    appendSparseMat(mat, 12, 1, 3);
    appendSparseMat(mat, 55, 2, 0);
    appendSparseMat(mat, 22, 1, 2);
    appendSparseMat(mat, 39, 4, 4);
    
    // printEntries(mat);

    // printf("\nIs it sorted? %d", isSortedMat(mat));

    // printf("\nSorting...\n");
    // mergeSortMat(mat);
    // printEntries(mat);
    // printf("\nIs it sorted? %d\n", isSortedMat(mat));

    displayMatrix(mat);
    freeSparseMat(&mat);
}