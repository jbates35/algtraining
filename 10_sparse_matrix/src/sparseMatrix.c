#include "sparseMatrix.h"

void initSparseMat(struct SparseMatrix *mat, int rows, int cols)
{
    if(mat==NULL) 
    {
        fprintf(stderr, "Error: Null pointer in initSparseMat");
        return;
    }

    mat->m = rows;
    mat->n = cols;
    mat->entries = 0;
    mat->size=10;
    mat->mat = (struct MatrixEntry*) malloc(sizeof(struct MatrixEntry) * mat->size);
}

void freeSparseMat(struct SparseMatrix *mat)
{
    if(mat==NULL)
    {
        fprintf(stderr, "Error: Null pointer in freeSparseMat");
        return;
    }

    free(mat->mat);
}

void appendSparseMat(struct SparseMatrix *mat, struct MatrixEntry entry)
{
    if(mat==NULL)
    {
        fprintf(stderr, "Error: Null pointer in appendSparseMat");
        return;
    }   

    if(mat->entries == mat->size)
    {
        mat->size *= 2;
        mat->mat = (struct MatrixEntry*) realloc(mat->mat, sizeof(struct MatrixEntry) * mat->size);
        
        if (mat->mat == NULL)
        {
            fprintf(stderr, "Error: Memory reallocation failed\n");
            return;
        }
    }

    mat->mat[mat->entries++] = entry;
}

struct MatrixEntry deleteSparseMat(struct SparseMatrix *mat, int i)
{
    struct MatrixEntry emptyEntry;

    if(mat==NULL)
    {
        fprintf(stderr, "Error: Null pointer in deleteSparseMat");
        return emptyEntry;
    }      

    if(i < 0 || i >= mat->entries)
    {
        fprintf(stderr, "Error: i is out of range.");
        return emptyEntry;
    }

    //Store deleted entry for return
    struct MatrixEntry entry = mat->mat[i];
    
    //Move remaining entries back an entry
    mat->entries--;
    for(int j = i; j < mat->entries; j++)
        mat->mat[j] = mat->mat[j+1];

    return entry;
}

struct MatrixEntry popBackSparseMat(struct SparseMatrix *mat)
{
    struct MatrixEntry emptyEntry;

    if(mat==NULL)
    {
        fprintf(stderr, "Error: Null pointer in deleteSparseMat");
        return emptyEntry;
    }

    return mat->mat[--mat->entries]; 
}

void sortSparseMat(struct SparseMatrix *mat)
{

}

//Funcs from lesson
struct SparseMatrix* addMatrices(struct SparseMatrix *A, struct SparseMatrix *B)
{

}