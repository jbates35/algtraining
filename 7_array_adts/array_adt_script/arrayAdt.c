#include "arrayAdt.h"

int init_intArrayAdt(struct ArrayInt *arr, int *val, int size, int length)
{
    arr->A = (int*) malloc(sizeof(int) * size);

    //Dump all the values into the struct's array
    for(int i=0; i<length; i++)
    {
        //Prevent overflow error
        if(i==size) 
            break;

        arr->A[i] = val[i];
    }

    arr->size = size;
    arr->length = length;

    return 0;
}

int free_intArrayAdt(struct ArrayInt *arr)
{
    free(arr->A);
    arr->A = NULL;
}

int display_intArrayAdt(struct ArrayInt *arr)
{
    //Detect null pointer   
    if(arr == NULL) 
        return -1;

    //Parse through array and display
    printf("\n");

    for(int i = 0; i<arr->length; i++)
        printf("%d ", arr->A[i]);

    printf("\n");

    return 0;
}

int append_intArrayAdt(struct ArrayInt *arr, int val)
{
    //Detect null pointer
    if(arr == NULL) 
        return -1;

    //Make sure there's enough room
    if(arr->size == arr->length)
        return -2;

    //Append
    arr->A[arr->length] = val;
    arr->length++;
    
    return 0;
}

int insert_intArrayAdt(struct ArrayInt *arr, int val, int pos)
{
    //Detect null pointer
    if(arr == NULL) 
        return -1;

    //Make sure there's enough room
    if(arr->size == arr->length)
        return -2;

    //If the position is out of these ranges, it's incompatible
    if(pos < 0 || pos > arr->length)
        return -3;

    //Shift array values up and then insert
    for(int i = arr->length; i > pos; i--)
        arr->A[i] = arr->A[i-1];

    arr->A[pos] = val;
    arr->length++;

    return 0;
}
