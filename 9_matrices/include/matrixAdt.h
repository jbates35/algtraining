#ifndef MATRIX_ADT_H
#define MATRIX_ADT_H

#include <stdio.h>
#include <stdlib.h>

#include "arrayAdt.h"

struct MatrixInt 
{
    int **A;
    int rows;
    int cols;
};

int initMat(struct MatrixInt *mat, int rows, int cols);
int freeMat(struct MatrixInt *mat);
void displayMat(struct MatrixInt *mat);
int getMatEntry(struct MatrixInt *mat, int i, int j);
void setMatEntry(struct MatrixInt *mat, int i, int j, int x);
void setMatDiag(struct MatrixInt *mat, struct ArrayInt *arr);

#endif