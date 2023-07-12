#include "matrixAdt.h"

int initMat(struct MatrixInt *mat, int rows, int cols)
{
    if(mat==NULL)
    {
        fprintf(stderr, "Error: Could not initialize Matrix ADT");
        return -1;
    }

    mat->rows = rows;
    mat->cols = cols;

    mat->A = (int**) malloc(sizeof(int*) * mat->rows);

    for(int i = 0; i < mat->rows; i++)
        mat->A[i] = (int*) malloc(sizeof(int) * mat->cols);

    return 0;
}

int freeMat(struct MatrixInt *mat) 
{
    if(mat==NULL)
    {
        fprintf(stderr, "Error: Could not initialize Matrix ADT");
        return -1;
    }

    for(int i = 0; i < mat->rows; i++)
    {
        free(mat->A[i]);
        mat->A[i] = NULL;
    }

    free(mat->A);
    mat->A = NULL;

    return 0;       
}

void displayMat(struct MatrixInt *mat)
{
    if(mat==NULL)
    {
        fprintf(stderr, "Error: Null pointer in displayMat");
        return;
    }

    printf("\nMatrix:\n");

    for(int i = 0; i < mat->rows; i++)
    {
        printf("\t");

        if(i == 0) 
            printf("[ ");
        else
            printf("  ");

        for(int j = 0; j < mat->cols; j++)
        {
            printf("%d", mat->A[i][j]);
            
            if(j < mat->cols-1)
                printf(", ");
        }

        if(i == mat->rows-1) 
            printf(" ]");
        
        printf("\n");
    }
}

int getMatEntry(struct MatrixInt *mat, int i, int j)
{
    if(mat==NULL)
    {
        fprintf(stderr, "Error: Null pointer in getMatEntry");
        return 0;
    }

    return mat->A[i][j];
}

void setMatEntry(struct MatrixInt *mat, int i, int j, int x)
{
    if(mat==NULL)
    {
        fprintf(stderr, "Error: Null pointer in setMatEntry");
        return;
    }

    mat->A[i][j] = x;
}

void setMatDiag(struct MatrixInt *mat, struct ArrayInt *arr)
{
    if(mat==NULL || arr==NULL)
    {
        fprintf(stderr, "Error: Null pointer in either mat or arr");
        return;
    }

    if(mat->cols != mat->rows) 
    {
        fprintf(stderr, "Error: Mat rows must equal mat cols");
        return;
    }

    if(arr->length != mat->rows)
    {
        fprintf(stderr, "Error: Array length does not match matrix diagonal length");
        return;
    }

    for(int i = 0; i < arr->length; i++)
        mat->A[i][i] = arr->A[i];
    
    return;
}
