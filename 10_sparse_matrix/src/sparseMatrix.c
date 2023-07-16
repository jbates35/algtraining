#include "sparseMatrix.h"
#include "helpFuncs.h"

void initSparseMat(struct SparseMatrix *A, int rows, int cols)
{
    if (A == NULL)
    {
        fprintf(stderr, "Error: Null pointer in initSparseMat");
        return;
    }

    A->m = rows;
    A->n = cols;
    A->entries = 0;
    A->size = 10;
    A->mat = (struct MatrixEntry *)malloc(sizeof(struct MatrixEntry) * A->size);
}

void freeSparseMat(struct SparseMatrix *A)
{
    if (A == NULL)
    {
        fprintf(stderr, "Error: Null pointer in freeSparseMat");
        return;
    }

    free(A->mat);
}

void appendSparseMat(struct SparseMatrix *A, struct MatrixEntry entry)
{
    if (A == NULL)
    {
        fprintf(stderr, "Error: Null pointer in appendSparseMat");
        return;
    }

    if (A->entries == A->size)
    {
        A->size *= 2;
        A->mat = (struct MatrixEntry *)realloc(A->mat, sizeof(struct MatrixEntry) * A->size);

        if (A->mat == NULL)
        {
            fprintf(stderr, "Error: Memory reallocation failed\n");
            return;
        }
    }

    A->mat[A->entries++] = entry;
}

struct MatrixEntry deleteSparseMat(struct SparseMatrix *A, int i)
{
    struct MatrixEntry emptyEntry;

    if (A == NULL)
    {
        fprintf(stderr, "Error: Null pointer in deleteSparseMat");
        return emptyEntry;
    }

    if (i < 0 || i >= A->entries)
    {
        fprintf(stderr, "Error: i is out of range.");
        return emptyEntry;
    }

    // Store deleted entry for return
    struct MatrixEntry entry = A->mat[i];

    // Move remaining entries back an entry
    A->entries--;
    for (int j = i; j < A->entries; j++)
        A->mat[j] = A->mat[j + 1];

    return entry;
}

struct MatrixEntry popBackSparseMat(struct SparseMatrix *A)
{
    struct MatrixEntry emptyEntry;

    if (A == NULL)
    {
        fprintf(stderr, "Error: Null pointer in deleteSparseMat");
        return emptyEntry;
    }

    return A->mat[--A->entries];
}

void sortSparseMat(struct SparseMatrix *A)
{
    // We are just going to do a simple bubble sort for this
    // First make sure no null pointer
    if (A == NULL)
    {
        fprintf(stderr, "Error: Null pointer in sortSparseMat");
        return;
    }

    // Get a multiplier for the m vals so we can more easily sort
    /*
    Why we need this is is because we want to sort both the row and col
    Therefore, if we have:
    Index 1: row == 3, col == 4
    Index 2: row == 2, col == 5
    We then want index 2 to come before index 1.
    An easy way to solve this is if we multiply the row by mFact, which will be either 1, 10, 100...10^i
    based on whatever the matrix column width (i.e. n) is.
    In this case, it'd be 10.
    Therefore Index 1 would be 34, and Index 2 would be 25.
    */
    int mFact = 1;
    while ((float)A->n / mFact > 1.0)
        mFact *= 10;

    // Parse through every entry
    for (int i = 0; i < A->entries - 1; i++)
    {
        for (int j = A->entries - 1; j > i; j--)
        {
            int ind1 = A->mat[j - 1].row * mFact + A->mat[j - 1].col;
            int ind2 = A->mat[j].row * mFact + A->mat[j].col;

            if (ind1 > ind2)

                swap(&A->mat[j - 1], &A->mat[j], sizeof(struct MatrixEntry));
        }
    }
}

void printEntries(struct SparseMatrix *A)
{
    if (A == NULL)
    {
        fprintf(stderr, "Error: Null pointer in printEntries");
        return;
    }

    for (int i = 0; i < A->entries; i++)
        printf("\n| Row %d\t| Col %d\t| Val %d", A->mat[i].row, A->mat[i].col, A->mat[i].val);
}

void printMatrix(struct SparseMatrix *A)
{
}

// Funcs from lesson
struct SparseMatrix *addMatrices(struct SparseMatrix *A, struct SparseMatrix *B)
{
}