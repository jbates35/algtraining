#ifndef S_MATRIX_ADT_H
#define S_MATRIX_ADT_H

#include "arrayAdt.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

//Row major single dimension matrix ADT
struct SRMatInt {
    struct ArrayInt arr;
    int rows;
    int length;
};

void initSRLowTri(struct SRMatInt *mat, struct ArrayInt *arr, int rows);
void freeSRLowTri(struct SRMatInt *mat);
int getSRLowTri(struct SRMatInt *mat, int row, int col);
void setSRLowTri(struct SRMatInt *mat, int row, int col, int val);
void dispSRLowTri(struct SRMatInt *mat);

#endif