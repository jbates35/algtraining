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

void initSparseMat(struct SparseMatrix *A, int rows, int cols);
void freeSparseMat(struct SparseMatrix *A);
void appendSparseMat(struct SparseMatrix *A, struct MatrixEntry entry);
struct MatrixEntry deleteSparseMat(struct SparseMatrix *A, int i);
struct MatrixEntry popBackSparseMat(struct SparseMatrix *A);
void sortSparseMat(struct SparseMatrix *A);
void printEntries(struct SparseMatrix *A);
void printMatrix(struct SparseMatrix *A);

//Funcs from lesson
struct SparseMatrix addMatrices(struct SparseMatrix *A, struct SparseMatrix *B);


#endif