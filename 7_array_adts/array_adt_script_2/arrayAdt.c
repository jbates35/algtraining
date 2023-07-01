#include "arrayAdt.h"
#include <string.h>

int initADT(struct ArrayInt *arr, int *val, int size, int length)
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

int freeADT(struct ArrayInt *arr)
{
    // Detect null pointer
    if (arr == NULL)
        return -2;

    if (arr->A == NULL || arr->size == 0)
        return -1;

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

int displayADT(struct ArrayInt *arr)
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

int appendADT(struct ArrayInt *arr, int val)
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

int insertADT(struct ArrayInt *arr, int val, int pos)
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

int deleteADT(struct ArrayInt *arr, int pos)
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

int linSearchADT(struct ArrayInt *arr, int val)
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

int binSearchADT(struct ArrayInt *arr, int val, int lo, int hi)
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

    return binSearchADT(arr, val, newLo, newHi);
}

int bubbleSortADT(struct ArrayInt *arr) 
{
    // Detect null pointer
    if (arr == NULL)
        return -2;

    // Operation is pointless if there's 0 or 1 elements
    if (arr->length<=1)
        return -1;    

    for(int i = arr->length-1; i > 0; i--)
    {
        for(int j = arr->length-1; j > (arr->length - i - 1); j--)
        {
            if(arr->A[j] < arr->A[j-1])
                swap(&arr->A[j], &arr->A[j-1], sizeof(int));
        }
    }
}

int mergeSortADT(struct ArrayInt *arr)
{
    // Can't do nuthin with a null pointer!
    if (arr == NULL)
        return -2;

    // No need to do anything (This means only one value in the array is able to be inspected with this call)
    if (arr->length <= 1)
    {
        return -1;
    }

    int mid = arr->length / 2;

    //Make two new arrays
    //low should go from 0 - mid-1
    //high should go from mid - length-1
    struct ArrayInt arrLow = { 
        NULL, mid, mid
    };

    if(mid != 0)
        arrLow.A = (int*) malloc(sizeof(int) * arrLow.size);

    struct ArrayInt arrHigh = {
        NULL, arr->length - mid, arr->length - mid
    };
    
    if(mid != 0)
        arrHigh.A = (int*) malloc(sizeof(int) * arrHigh.size);

    // Now dump data into array
    for(int i = 0; i < mid; i++) 
    {
        arrLow.A[i] = arr->A[i];
        arrHigh.A[i] = arr->A[i+mid];
    }

    if(arr->length%2 == 1)
        arrHigh.A[arrHigh.length-1] = arr->A[arr->length-1];

    //Recursively call until only one or two values are left
    mergeSortADT(&arrLow);
    mergeSortADT(&arrHigh);

    //Merging arrays in order of number
    int i = 0, j = 0, k = 0;

    //Walk through the arrays depositing the lowest number in either array
    //Keep in mind, these arrays are sorted
    while(i < arrLow.length && j < arrHigh.length)
    {
        if(arrLow.A[i] < arrHigh.A[j])
            arr->A[k++] = arrLow.A[i++];
        else
            arr->A[k++] = arrHigh.A[j++];
    }

    //Parse through remaining values and add them
    while(i < arrLow.length)
        arr->A[k++] = arrLow.A[i++];
    while(j < arrHigh.length)
        arr->A[k++] = arrHigh.A[j++];
    
    //Return the memory to the computer like a good person
    freeADT(&arrLow);
    freeADT(&arrHigh);

    return 0;
}

int getADT(struct ArrayInt *arr, int pos)
{
    if (arr == NULL || pos >= arr->length || pos < 0)
        return 0;

    return arr->A[pos];
}

int setADT(struct ArrayInt *arr, int val, int pos)
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

int maxADT(struct ArrayInt *arr)
{
    // Can't do much with a null pointer
    if (arr == NULL || arr->length == 0)
        return 0;

    int maxval = arr->A[0];

    for (int i = 1; i < arr->length; i++)
        maxval = (arr->A[i] > maxval) ? arr->A[i] : maxval;

    return maxval;
}

int minADT(struct ArrayInt *arr)
{
    // Can't do much with a null pointer
    if (arr == NULL || arr->length == 0)
        return 0;

    int minval = arr->A[0];

    for (int i = 1; i < arr->length; i++)
        minval = (arr->A[i] < minval) ? arr->A[i] : minval;

    return minval;
}

int reverseADT(struct ArrayInt *arr)
{
    // Can't do much with a null pointer
    if (arr == NULL)
        return -2;

    int midval = arr->length / 2;

    for (int i = 0, j = arr->length - 1; i < midval; i++, j--)
        swap(&arr->A[i], &arr->A[j], sizeof(int));
}

int shiftADT(struct ArrayInt *arr, int n, int dir)
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

int rotateADT(struct ArrayInt *arr, int n, int dir)
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


int insertInSortedADT(struct ArrayInt *arr, int val)
{
    // Can't do much with a null pointer
    if (arr == NULL)
        return -2;

    for(int i = 0; i < arr->length; i++)
        if(val<=arr->A[i])
        {
            insertADT(arr, val, i);
            return 0;
        }

    appendADT(arr, val);
    return 0;
}

bool isSortedADT(struct ArrayInt *arr)
{
    // Can't do much with a null pointer
    if (arr == NULL || arr->length==0)
        return false;

    if(arr->length == 1)
        return true;
        
    for(int i=1; i<arr->length; i++)
    {
        if(arr->A[i] < arr->A[i-1])
            return false;
    }
    return true;
}

int moveNegsLeftADT(struct ArrayInt *arr) 
{
    // Can't do much with a null pointer
    if (arr == NULL)
        return -2;

    int i = 0, j = arr->length-1;

    while(i < j) 
    {
        if(arr->A[i] >= 0)
            swap(&arr->A[i], &arr->A[j], sizeof(int));
        else
            i++;

        if(arr->A[j] < 0)
            swap(&arr->A[i], &arr->A[j], sizeof(int));
        else
            j--;
    }

    return 0;
}

int mergeADT(struct ArrayInt *arr1, struct ArrayInt *arr2, struct ArrayInt *arr)
{    // Can't do much with a null pointer
    if (arr1 == NULL || arr2 == NULL)
        return -2;

    int i = 0;
    int j = 0;
    int k = 0;

    int *tempArr;
    tempArr = (int*) malloc(sizeof(int) * (arr1->size + arr2->size));

    while(i<arr1->length && j<arr2->length)
    {
        if(arr1->A[i] < arr2->A[j]) 
            tempArr[k++] = arr1->A[i++];
        else
            tempArr[k++] = arr2->A[j++];
    }

    while(i < arr1->length)
        tempArr[k++] = arr1->A[i++];
    while(j < arr2->length)
        tempArr[k++] = arr2->A[j++];

    if(arr->A != NULL)
        freeADT(arr);

    arr->A = tempArr;
    arr->size = arr1->size + arr2->size;
    arr->length = arr1->length + arr2->length;
    
    tempArr = NULL;

    return 0;
}