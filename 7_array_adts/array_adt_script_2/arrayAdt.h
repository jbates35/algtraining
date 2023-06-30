#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define RIGHT   1
#define LEFT    0

struct ArrayInt {
    int* A;
    int length;
    int size;
};

int initADT(struct ArrayInt *arr, int* val, int size, int length);
int freeADT(struct ArrayInt *arr);

void swap(void *x, void *y, size_t size);

int displayADT(struct ArrayInt *arr);
int appendADT(struct ArrayInt *arr, int val);
int insertADT(struct ArrayInt *arr, int val, int pos);
int deleteADT(struct ArrayInt *arr, int pos);
int linSearchADT(struct ArrayInt *arr, int val);
int binSearchADT(struct ArrayInt *arr, int val, int lo, int hi);
int bubbleSortADT(struct ArrayInt *arr);
int mergeSortADT(struct ArrayInt *arr);
int getADT(struct ArrayInt *arr, int pos);
int setADT(struct ArrayInt *arr, int val, int pos);
int maxADT(struct ArrayInt *arr);
int minADT(struct ArrayInt *arr);
int reverseADT(struct ArrayInt *arr);
int shiftADT(struct ArrayInt *arr, int n, int dir);
int rotateADT(struct ArrayInt *arr, int n, int dir);
int insertInSortedADT(struct ArrayInt *arr, int val);
bool isSortedADT(struct ArrayInt *arr);
int moveNegsLeftADT(struct ArrayInt *arr);
