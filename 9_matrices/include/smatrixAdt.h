#ifndef S_MATRIX_ADT_H
#define S_MATRIX_ADT_H

#include "arrayAdt.h"
#include <stdlib.h>
#include <stdio.h>

//Row major single dimension matrix ADT
struct SRMatInt {
    struct ArrayInt arr;
    int rows;
    int length;
};

//Col major single dimension matrix ADT
struct SCMatInt {
    struct ArrayInt arr;
    int cols;
    int length;
};

void initSRLowTri(struct SRMatInt *mat, struct ArrayInt *arr, int rows);
void freeSRLowTri(struct SRMatInt *mat);
int getSRLowTri(struct SRMatInt *mat, int row, int col);
void setSRLowTri(struct SRMatInt *mat, int row, int col, int val);
void dispSRLowTri(struct SRMatInt *mat);

void initSCLowTri(struct SCMatInt *mat, struct ArrayInt *arr, int cols);
void freeSCLowTri(struct SCMatInt *mat);
int getSCLowTri(struct SCMatInt *mat, int row, int col);
void setSCLowTri(struct SCMatInt *mat, int row, int col, int val);
void dispSCLowTri(struct SCMatInt *mat);

void initSRUpTri(struct SRMatInt *mat, struct ArrayInt *arr, int rows);
void freeSRUpTri(struct SRMatInt *mat);
int getSRUpTri(struct SRMatInt *mat, int row, int col);
void setSRUpTri(struct SRMatInt *mat, int row, int col, int val);
void dispSRUpTri(struct SRMatInt *mat);

void initSCUpTri(struct SCMatInt *mat, struct ArrayInt *arr, int cols);
void freeSCUpTri(struct SCMatInt *mat);
int getSCUpTri(struct SCMatInt *mat, int row, int col);
void setSCUpTri(struct SCMatInt *mat, int row, int col, int val);
void dispSCUpTri(struct SCMatInt *mat);

#endif