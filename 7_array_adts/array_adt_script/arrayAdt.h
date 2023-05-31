#include <stdio.h>
#include <stdlib.h>

struct ArrayInt {
    int* A;
    int length;
    int size;
};

struct ArrayFloat {
    float* A;
    int length;
    int size;
};

int init_intArrayAdt(struct ArrayInt *arr, int* val, int size, int length);
int free_intArrayAdt(struct ArrayInt *arr);

int display_intArrayAdt(struct ArrayInt *arr);
int append_intArrayAdt(struct ArrayInt *arr, int val);
int insert_intArrayAdt(struct ArrayInt *arr, int val, int pos);
int delete_intArrayAdt(struct ArrayInt *arr, int pos);
int search_intArrayAdt(struct ArrayInt *arr, int val);
int get_intArrayAdt(struct ArrayInt *arr, int pos);
int set_intArrayAdt(struct ArrayInt *arr, int val, int pos);
int max_intArrayAdt(struct ArrayInt *arr);
int min_intArrayAdt(struct ArrayInt *arr);
int reverse_intArrayAdt(struct ArrayInt *arr);
int shift_intArrayAdt(struct ArrayInt *arr, int n, int dir);
int rotate_intArrayAdt(struct ArrayInt *arr, int n, int dir);

int fDisplay(struct ArrayFloat *arr);
int fAppend(struct ArrayFloat *arr, int val);
int fInsert(struct ArrayFloat *arr, int val, int pos);
int fDelete(struct ArrayFloat *arr, int pos);
int fSearch(struct ArrayFloat *arr, int val);
int fGet(struct ArrayFloat *arr, int pos);
int fSet(struct ArrayFloat *arr, int val, int pos);
int fMax(struct ArrayFloat *arr);
int fMin(struct ArrayFloat *arr);
int fReverse(struct ArrayFloat *arr);
int fShift(struct ArrayFloat *arr, int n, int dir);
int fRotate(struct ArrayFloat *arr, int n, int dir);