#ifndef SPARSE_MATRIX_H
#define SPARSE_MATRIX_H

#include <stdio.h>
#include <stdlib.h>

struct MatrixEntry {
    int row;
    int col;
    int val;
};

struct SparseMatrix {
    int m; //rows
    int n; //columns
    int size; //for malloc
    int entries; //number of entries
    struct MatrixEntry *mat;
};

void initSparseMat(struct SparseMatrix *mat, int rows, int cols);
void freeSparseMat(struct SparseMatrix *mat);
void appendSparseMat(struct SparseMatrix *mat, struct MatrixEntry entry);
struct MatrixEntry deleteSparseMat(struct SparseMatrix *mat, int i);
struct MatrixEntry popBackSparseMat(struct SparseMatrix *mat);
void sortSparseMat(struct SparseMatrix *mat);

//Funcs from lesson
struct SparseMatrix* addMatrices(struct SparseMatrix *A, struct SparseMatrix *B);


#endif