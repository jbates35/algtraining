#include "arrayAdt.h"
#include <string.h>

int init_intArrayAdt(struct ArrayInt *arr, int *val, int size, int length)
{
    // Detect null pointer
    if (arr == NULL)
        return -2;

    arr->A = (int *)malloc(sizeof(int) * size);

    // Dump all the values into the struct's array
    for (int i = 0; i < length; i++)
    {
        // Prevent overflow error
        if (i == size)
            break;

        arr->A[i] = val[i];
    }

    arr->size = size;
    arr->length = length;

    return 0;
}

int free_intArrayAdt(struct ArrayInt *arr)
{
    // Detect null pointer
    if (arr == NULL)
        return -2;

    free(arr->A);
    arr->A = NULL;
}

void swap(void *x, void *y, size_t size)
{
    void *temp = malloc(size);
    memcpy(temp, y, size);
    memcpy(y, x, size);
    memcpy(x, temp, size);
    free(temp);
}

int swap_intArrayAdt(struct ArrayInt *arr, int ind1, int ind2)
{
    // Detect null pointer
    if (arr == NULL)
        return -2;

    if(ind1 >= arr->length || ind1 < 0 || ind2 >= arr->length || ind2 < 0)
        return -4;

    int temp = arr->A[ind1];
    arr->A[ind1] = arr->A[ind2];
    arr->A[ind2] = temp;
}

int display_intArrayAdt(struct ArrayInt *arr)
{
    // Detect null pointer
    if (arr == NULL)
        return -2;

    // Parse through array and display
    printf("\n");

    for (int i = 0; i < arr->length; i++)
        printf("%d ", arr->A[i]);

    printf("\n");

    return 0;
}

int append_intArrayAdt(struct ArrayInt *arr, int val)
{
    // Detect null pointer
    if (arr == NULL)
        return -2;

    // Make sure there's enough room
    if (arr->size == arr->length)
        return -3;

    // Append
    arr->A[arr->length] = val;
    arr->length++;

    return 0;
}

int insert_intArrayAdt(struct ArrayInt *arr, int val, int pos)
{
    // Detect null pointer
    if (arr == NULL)
        return -2;

    // Make sure there's enough room
    if (arr->size == arr->length)
        return -3;

    // If the position is out of these ranges, it's incompatible
    if (pos < 0 || pos > arr->length)
        return -4;

    // Shift array values up and then insert
    for (int i = arr->length; i > pos; i--)
        arr->A[i] = arr->A[i - 1];

    arr->A[pos] = val;
    arr->length++;

    return 0;
}

int delete_intArrayAdt(struct ArrayInt *arr, int pos)
{
    // Detect null pointer
    if (arr == NULL)
        return 0;

    // If the position is out of these ranges, it's incompatible
    if (pos < 0 || pos >= arr->length)
        return 0;

    // Shift array values down, make last one null
    int delVal = arr->A[pos];
    arr->length--;

    for (int i = pos; i < arr->length; i++)
        arr->A[i] = arr->A[i + 1];

    arr->A[arr->length] = 0;

    return delVal;
}

int linSearch_intArrayAdt(struct ArrayInt *arr, int val)
{
    // Detect null pointer
    if (arr == NULL)
        return -2;

    // Search for place in array that val can be found
    for (int i = 0; i < arr->length; i++)
    {
        if (val == arr->A[i])
            return i;
    }

    // Unsuccessful
    return -1;
}

int binSearch_intArrayAdt(struct ArrayInt *arr, int val, int lo, int hi)
{
    // Detect null pointer
    if (arr == NULL)
        return -2;

    // do housekeeping to return if we found value
    if (arr->A[lo] == val)
        return lo;
    if (arr->A[hi - 1] == val)
        return hi - 1;

    if ((hi - lo) <= 2)
        return -1;

    // If value hasn't been found, or has been discovered to be non-existent, recurse thy value
    int mid = (lo + hi) / 2;
    int newHi, newLo;

    if (val >= arr->A[lo] && val < arr->A[mid])
    {
        newHi = mid;
        newLo = lo;
    }
    else
    {
        newHi = hi;
        newLo = mid;
    }

    return binSearch_intArrayAdt(arr, val, newLo, newHi);
}

int dncSort_intArrayAdt(struct ArrayInt *arr, int lo, int hi)
{
    // Detect null pointer
    if (arr == NULL)
        return -2;

    // No need to do anything
    if (lo == hi)
    {
        printf("\n<%d, %d>\n", lo, arr->A[lo]);
        return -1;
    }

    int mid = (hi + lo) / 2;

    dncSort_intArrayAdt(arr, lo, mid);
    dncSort_intArrayAdt(arr, mid + 1, hi);

    printf("\n<");
    for (int i = lo; i <= mid; i++)
    {
        printf("%d: %d", i, arr->A[i]);
        if (i != mid)
            printf(", ");
    }
    printf(">\n");

    return 0;
}

int get_intArrayAdt(struct ArrayInt *arr, int pos)
{
    if (arr == NULL || pos >= arr->length || pos < 0)
        return 0;

    return arr->A[pos];
}

int set_intArrayAdt(struct ArrayInt *arr, int val, int pos)
{
    // Can't do much with a null pointer
    if (arr == NULL)
        return -2;

    // If the position is out of these ranges, it's incompatible
    if (pos < 0 || pos >= arr->length)
        return -4;

    arr->A[pos] = val;

    return 0;
}

int max_intArrayAdt(struct ArrayInt *arr)
{
    // Can't do much with a null pointer
    if (arr == NULL || arr->length == 0)
        return 0;

    int maxval = arr->A[0];

    for (int i = 1; i < arr->length; i++)
        maxval = (arr->A[i] > maxval) ? arr->A[i] : maxval;

    return maxval;
}

int min_intArrayAdt(struct ArrayInt *arr)
{
    // Can't do much with a null pointer
    if (arr == NULL || arr->length == 0)
        return 0;

    int minval = arr->A[0];

    for (int i = 1; i < arr->length; i++)
        minval = (arr->A[i] < minval) ? arr->A[i] : minval;

    return minval;
}

int reverse_intArrayAdt(struct ArrayInt *arr)
{
    // Can't do much with a null pointer
    if (arr == NULL)
        return -2;

    int midval = arr->length / 2;

    for (int i = 0, j = arr->length - 1; i < midval; i++, j--)
        swap_intArrayAdt(arr, i, j);
}

int shift_intArrayAdt(struct ArrayInt *arr, int n, int dir)
{
    // Can't do much with a null pointer
    if (arr == NULL)
        return -2;

    if (n == 0)
        return 0;

    if (n > arr->length)
        n = arr->length;

    if (dir == RIGHT)
    {
        for (int i = arr->length - 1; i >= n; i--)
            arr->A[i] = arr->A[i - n];

        for (int i = 0; i < n; i++)
            arr->A[i] = 0;
    }

    else
    {
        for (int i = 0; i < arr->length - n; i++)
            arr->A[i] = arr->A[i + n];

        for (int i = arr->length - 1; i >= arr->length - n; i--)
            arr->A[i] = 0;
    }

    return 0;
}

int rotate_intArrayAdt(struct ArrayInt *arr, int n, int dir)
{
    // Can't do much with a null pointer
    if (arr == NULL)
        return -2;

    if (n == 0)
        return 0;

    if (n > arr->length)
        n = n % arr->length;

    int *temparr;
    temparr = (int *)malloc(sizeof(int) * n);

    if (dir == RIGHT)
    {
        for (int i = 0; i < n; i++)
            temparr[i] = arr->A[arr->length - n + i];

        for (int i = arr->length - 1; i >= n; i--)
            arr->A[i] = arr->A[i - n];

        for (int i = 0; i < n; i++)
            arr->A[i] = temparr[i];
    }

    else
    {
        for (int i = 0; i < n; i++)
            temparr[i] = arr->A[i];

        for (int i = 0; i < arr->length - n; i++)
            arr->A[i] = arr->A[i + n];

        for (int i = 0; i < n; i++)
            arr->A[arr->length - n + i] = temparr[i];
    }

    free(temparr);
    temparr = NULL;

    return 0;
}