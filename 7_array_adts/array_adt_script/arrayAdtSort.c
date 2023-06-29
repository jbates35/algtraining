#include "arrayAdtSort.h"

int mergeSort_intArrayAdt(ArrayInt *arr, int lo, int hi)
{
    // Can't do nuthin with a null pointer!
    if (arr == NULL)
        return -2;

    // No need to do anything (This means only one value in the array is able to be inspected with this call)
    if (lo == hi)
    {
        return -1;
    }

    int mid = (hi + lo) / 2;

    //Recursively call until only one or two values are left
    mergeSort_intArrayAdt(arr, lo, mid);
    mergeSort_intArrayAdt(arr, mid + 1, hi);

    int i = lo, j = mid+1, k = 0;

    //Make new array to dump new vals in
    int* tempArr = malloc(sizeof(int) * (hi - lo + 1));

    //Incrementally compare and load lowest value between the two sections of the array
    while(i <= mid && j <= hi)
        if(arr->A[i] < arr->A[j])
            tempArr[k++] = arr->A[i++];
        else 
            tempArr[k++] = arr->A[j++];

    //Only one of these while loops will be activated, and we need the rest of the values
    while(i <= mid)
        tempArr[k++] = arr->A[i++];

    while(j <= hi)
        tempArr[k++] = arr->A[j++];

    //The temp array is sorted, but we need to replace the values in the original array with them
    for(i = lo, j=0; i<=hi; i++, j++)
        arr->A[i] = tempArr[j];

    free (tempArr);
    tempArr = NULL;

    return 0;
}