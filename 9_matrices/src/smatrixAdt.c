#include "smatrixAdt.h"

void initSRLowTri(struct SRMatInt *mat, struct ArrayInt *arr, int rows)
{
    if(mat==NULL)
    {
        fprintf(stderr, "Error: Null pointer in initSRLowTri");
        return;
    }

    mat->rows = rows;

    //Need to get number of values to a lower triangle of said rows
    int length = 0;
    while(rows != 0)
    {
        length += rows;
        rows--;
    }
    mat->length = length;

    int tempX[0] = {};
    initADT(&mat->arr, tempX, 1000, 0);

    int i;
    for(i = 0; i < arr->length; i++)
    {
        if(i == mat->length)
            break;

        appendADT(&mat->arr, arr->A[i]);
    }

    for(; i < mat->length; i++)
        appendADT(&mat->arr, 0);
}

void freeSRLowTri(struct SRMatInt *mat)
{
    if(mat==NULL)
    {
        fprintf(stderr, "Error: Arr is a null pointer in getSCLowTri");
        return;
    }

    freeADT(&mat->arr);
}

int getSRLowTri(struct SRMatInt *mat, int row, int col)
{
    if(mat==NULL)
    {
        fprintf(stderr, "Error: Arr is a null pointer in getSCLowTri");
        return 0;
    }

    if(row < col)
    {
        fprintf(stderr, "Error: in a lower triangle, x (rows) cannot be lower than y (cols)");
        return 0;
    }

    if(row > mat->rows)
    {
        fprintf(stderr, "Error: Specified row out of bounds");
        return 0;
    }

    int index = 0;

    for(int i = 0; i < row; i++)
    {
        index += i;
    }

    index += col;

    return mat->arr.A[index];
}

void setSRLowTri(struct SRMatInt *mat, int row, int col, int val)
{
    if(mat==NULL)
    {
        fprintf(stderr, "Error: Arr is a null pointer in getSCLowTri");
        return;
    }

    if(row < col)
    {
        fprintf(stderr, "Error: in a lower triangle, x (rows) cannot be lower than y (cols)");
        return;
    }

    if(row > mat->rows)
    {
        fprintf(stderr, "Error: Specified x (rows) out of bounds");
        return;
    }

    int index = 0;

    for(int i = 0; i < row; i++)
    {
        index += i;
    }

    index += col-1;

    mat->arr.A[index] = val;
}

void dispSRLowTri(struct SRMatInt *mat)
{
    if(mat==NULL)
    {
        fprintf(stderr, "Error: Arr is a null pointer in getSCLowTri");
        return;
    }

    int startInd = 0;

    printf("Lower matrix:\n");
    for (int row = 0; row < mat->rows; row++)
    {
        if(row==0)
            printf("[ ");
        else
            printf("  ");

        startInd += row;

        for (int i = 0; i <= row; i++)
        {
            printf("%d", mat->arr.A[startInd + i]);            
            if(i != mat->rows - 1)
                printf(", ");
        }

        for (int j = row + 1; j < mat->rows; j++)
        {
            printf("0");
            if(j != mat->rows - 1)
                printf(", ");
        }
        
        if(row != mat->rows-1)
            printf("\n");
        else
            printf(" ]\n\n");
    }
}