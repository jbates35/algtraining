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

    printf("Lower single-dimension row-major matrix:\n");
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

void initSCLowTri(struct SCMatInt *mat, struct ArrayInt *arr, int cols)
{
    if(mat==NULL)
    {
        fprintf(stderr, "Error: Null pointer in initSRLowTri");
        return;
    }

    mat->cols = cols;

    //Need to get number of values to a lower triangle of said rows
    int length = 0;
    while(cols != 0)
    {
        length += cols;
        cols--;
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

void freeSCLowTri(struct SCMatInt *mat)
{
    if(mat==NULL)
    {
        fprintf(stderr, "Error: Arr is a null pointer in getSCLowTri");
        return;
    }

    freeADT(&mat->arr);
}

int getSCLowTri(struct SCMatInt *mat, int row, int col)
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

    if(col > mat->cols)
    {
        fprintf(stderr, "Error: Specified x (rows) out of bounds");
        return 0;
    }

    if(row==0 || col==0)
    {
        fprintf(stderr, "Error: cols and rows are one-indexed here.");
        return 0;
    }
    
    row--;
    col--;

    int index = 0;
    for(int i = 0; i < col; i++)
        index += (mat->cols - i);
    index += row-col;

    return mat->arr.A[index];
}

void setSCLowTri(struct SCMatInt *mat, int row, int col, int val)
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

    if(col > mat->cols)
    {
        fprintf(stderr, "Error: Specified x (rows) out of bounds");
        return;
    }

    if(row==0 || col==0)
    {
        fprintf(stderr, "Error: cols and rows are one-indexed here.");
        return;
    }

    row--;
    col--;

    int index = 0;
    for(int i = 0; i < col; i++)
        index += (mat->cols - i);
    index += row-col;

    mat->arr.A[index] = val;
}

void dispSCLowTri(struct SCMatInt *mat)
{
    if(mat==NULL)
    {
        fprintf(stderr, "Error: Arr is a null pointer in getSCLowTri");
        return;
    }

    int altRows = mat->cols - 1;

    printf("Lower single-dimension col-major matrix:\n");
    for (int row = 0; row < mat->cols; row++)
    {
        if(row==0)
            printf("[ ");
        else
            printf("  ");

        printf("%d", mat->arr.A[row]);
        
        if(1 != mat->cols)
            printf(", ");
        else  
        {
            printf(" ]\n\n");
            break;
        }

        int endInd = 0;
        int i;
        for(i = 0; i < row; i++) 
        {   
            endInd += altRows - i;
            printf("%d", mat->arr.A[row + endInd]);

            if(i != mat->cols-2)
                printf(", ");
            else
                printf(" ]\n\n");
        }

        for(; i < mat->cols-1; i++)
        {
            printf("0");

            if(i != mat->cols-2)
                printf(", ");
            else
                printf("\n");            
        }
    }
}
