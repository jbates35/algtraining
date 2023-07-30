#ifndef SPARSE_MATRIX_H
#define SPARSE_MATRIX_H

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct MatrixEntry {
    int row;
    int col;
    int val;
};

struct SMNode {
    struct SMNode *next;
    struct MatrixEntry entry;
};

struct SparseMatrix {
    int m; //rows
    int n; //columns
    struct SMNode *first;
};

void initSparseMat(struct SparseMatrix **A, int rows, int cols);
void freeSparseMat(struct SparseMatrix **A);
void appendSparseMat(struct SparseMatrix *A, int val, int row, int col);
void printEntries(struct SparseMatrix *A);
void displayMatrix(struct SparseMatrix *A);
int isSortedMat(struct SparseMatrix *A);
void mergeSortMat(struct SparseMatrix *A);

#endif