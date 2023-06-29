#ifndef ARRAY_ADT_H
#define ARRAY_ADT_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define RIGHT   1
#define LEFT    0

typedef struct arrayint {
    int* A;
    int length;
    int size;
    int initialized;
} ArrayInt;

typedef struct arrayfloat {
    float* A;
    int length;
    int size;
    int initialized;
} ArrayFloat;

int init_intArrayAdt(ArrayInt *arr, int* val, int size, int length);
int deinit_intArrayAdt(ArrayInt *arr);

void swap(void *x, void *y, size_t size);

int display_intArrayAdt(ArrayInt *arr);
int append_intArrayAdt(ArrayInt *arr, int val);
int insert_intArrayAdt(ArrayInt *arr, int val, int pos);
int delete_intArrayAdt(ArrayInt *arr, int pos);
int linSearch_intArrayAdt(ArrayInt *arr, int val);
int binSearch_intArrayAdt(ArrayInt *arr, int val, int lo, int hi);
int get_intArrayAdt(ArrayInt *arr, int pos);
int set_intArrayAdt(ArrayInt *arr, int val, int pos);
int max_intArrayAdt(ArrayInt *arr);
int min_intArrayAdt(ArrayInt *arr);
int reverse_intArrayAdt(ArrayInt *arr);
int shift_intArrayAdt(ArrayInt *arr, int n, int dir);
int rotate_intArrayAdt(ArrayInt *arr, int n, int dir);
int insertInSorted_intArrayAdt(ArrayInt *arr, int val);
bool isSorted_intArrayAdt(ArrayInt *arr);
int moveNegsLeft_intArrayAdt(ArrayInt *arr);
int moveNegsLeft(int *arr, int N);


int fDisplay(ArrayFloat *arr);
int fAppend(ArrayFloat *arr, int val);
int fInsert(ArrayFloat *arr, int val, int pos);
int fDelete(ArrayFloat *arr, int pos);
int fSearch(ArrayFloat *arr, int val);
int fGet(ArrayFloat *arr, int pos);
int fSet(ArrayFloat *arr, int val, int pos);
int fMax(ArrayFloat *arr);
int fMin(ArrayFloat *arr);
int fReverse(ArrayFloat *arr);
int fShift(ArrayFloat *arr, int n, int dir);
int fRotate(ArrayFloat *arr, int n, int dir);

#endif