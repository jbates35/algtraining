#include "sparseMatrix.h"
#include "helpFuncs.h" 

void initSparseMat(struct SparseMatrix **A, int rows, int cols)
{
    *A = (struct SparseMatrix*) malloc(sizeof(struct SparseMatrix));
    (*A)->first = NULL;
    (*A)->m = rows;
    (*A)->n = cols;
}

void freeSparseMat(struct SparseMatrix **A)
{
    if ((*A) == NULL)
    {
        fprintf(stderr, "\nError: Null pointer in freeSparseMat");
        return;
    }

    struct SMNode *p = (*A)->first;
    struct SMNode *q = NULL;

    while(p)
    {
        q = p;
        p = p->next;
        free(q);
    }

    free(*A);
    *A = NULL;
}

void appendSparseMat(struct SparseMatrix *A, int val, int row, int col)
{
    if(!A)
    {
        fflush(stdout);
        fprintf(stderr, "\nNULL POINTER being fed into appendSparseMat");
    }

    struct MatrixEntry matEntry = {
        row,
        col,
        val
    };

    struct SMNode *new = (struct SMNode*) malloc(sizeof(struct SMNode));
    new->next = NULL;
    new->val = matEntry;
    
    //if first entry, need to deal w that
    if(A->first == NULL)
    {
        A->first = new;
        return;
    }

    struct SMNode *p = A->first;

}



int isSortedList(struct Node *p)
{
    int x = INT_MIN; // Keeps track of current lowest value. Needed since it's a linked list, not array

    //Checks last value to see if it's higher than the current val
    while(p)
    {
        //If x is greater than p val, then not sorted
        if(p->val < x)
            return 0;

        x = p->val;
        p = p->next;
    }

    return 1;
}



// void appendSparseMat(struct SparseMatrix *A, struct MatrixEntry entry)
// {
//     if (A == NULL)
//     {
//         fprintf(stderr, "\nError: Null pointer in appendSparseMat");
//         return;
//     }

//     if (A->entries == A->size)
//     {
//         A->size *= 2;
//         A->mat = (struct MatrixEntry *)realloc(A->mat, sizeof(struct MatrixEntry) * A->size);

//         if (A->mat == NULL)
//         {
//             fprintf(stderr, "\nError: Memory reallocation failed\n");
//             return;
//         }
//     }

//     // Want to make sure we aren't putting a duplicate entry in, but instead simply updating the old entry
//     for (int i = 0; i < A->entries; i++)
//     {
//         if (A->mat[i].row == entry.row && A->mat[i].col == entry.col)
//         {
//             A->mat[i].val = entry.val;
//             return;
//         }
//     }

//     A->mat[A->entries++] = entry;
// }

// struct MatrixEntry deleteSparseMat(struct SparseMatrix *A, int i)
// {
//     struct MatrixEntry emptyEntry;

//     if (A == NULL)
//     {
//         fprintf(stderr, "\nError: Null pointer in deleteSparseMat");
//         return emptyEntry;
//     }

//     if (i < 0 || i >= A->entries)
//     {
//         fprintf(stderr, "\nError: i is out of range.");
//         return emptyEntry;
//     }

//     // Store deleted entry for return
//     struct MatrixEntry entry = A->mat[i];

//     // Move remaining entries back an entry
//     A->entries--;
//     for (int j = i; j < A->entries; j++)
//         A->mat[j] = A->mat[j + 1];

//     return entry;
// }

// struct MatrixEntry popBackSparseMat(struct SparseMatrix *A)
// {
//     struct MatrixEntry emptyEntry;

//     if (A == NULL)
//     {
//         fprintf(stderr, "\nError: Null pointer in deleteSparseMat");
//         return emptyEntry;
//     }

//     return A->mat[--A->entries];
// }

// void sortSparseMat(struct SparseMatrix *A)
// {
//     // We are just going to do a simple bubble sort for this
//     // First make sure no null pointer
//     if (A == NULL)
//     {
//         fprintf(stderr, "\nError: Null pointer in sortSparseMat");
//         return;
//     }

//     // Get a multiplier for the m vals so we can more easily sort
//     /*
//     Why we need this is is because we want to sort both the row and col
//     Therefore, if we have:
//     Index 1: row == 3, col == 4
//     Index 2: row == 2, col == 5
//     We then want index 2 to come before index 1.
//     An easy way to solve this is if we multiply the row by mFact, which will be either 1, 10, 100...10^i
//     based on whatever the matrix column width (i.e. n) is.
//     In this case, it'd be 10.
//     Therefore Index 1 would be 34, and Index 2 would be 25.
//     */
//     int mFact = 1;
//     while (A->n / mFact > 1)
//         mFact *= 10;

//     // Parse through every entry
//     for (int i = 0; i < A->entries - 1; i++)
//     {
//         for (int j = A->entries - 1; j > i; j--)
//         {
//             int ind1 = A->mat[j - 1].row * mFact + A->mat[j - 1].col;
//             int ind2 = A->mat[j].row * mFact + A->mat[j].col;

//             if (ind1 > ind2)

//                 swap(&A->mat[j - 1], &A->mat[j], sizeof(struct MatrixEntry));
//         }
//     }
// }

// void printEntries(struct SparseMatrix *A)
// {
//     if (A == NULL)
//     {
//         fprintf(stderr, "\nError: Null pointer in printEntries");
//         return;
//     }

//     for (int i = 0; i < A->entries; i++)
//         printf("| Row %d\t| Col %d\t| Val %d\n", A->mat[i].row, A->mat[i].col, A->mat[i].val);
// }

// void printMatrix(struct SparseMatrix *A)
// {
//     if (A == NULL)
//     {
//         fprintf(stderr, "\nError: null pointer in printMatrix");
//         return;
//     }

//     // Note, this only works with a sorted matrix
//     int currInd = 0;

//     printf("\n");

//     for (int i = 0; i < A->m; i++)
//     {
//         for (int j = 0; j < A->n; j++)
//         {
//             if (currInd < A->entries && A->mat[currInd].row == i && A->mat[currInd].col == j)
//                 printf("%d\t", A->mat[currInd++].val);
//             else
//                 printf("0\t");
//         }
//         printf("\n");
//     }
// }

// // Funcs from lesson
// struct SparseMatrix addMatrices(struct SparseMatrix *A, struct SparseMatrix *B)
// {
//     struct SparseMatrix returnMat;

//     if (A == NULL || B == NULL)
//     {
//         fprintf(stderr, "\nError: null pointer in addMatrices");
//         return returnMat;
//     }

//     // Need to make sure mats are of equal size, then initiate next mat
//     if (A->m != B->m || A->n != B->n)
//     {
//         fprintf(stderr, "\nError: Mat A and Mat B are of different dimensions, therefore addMatrices will not work");
//         return returnMat;
//     }

//     // Initialize returnMat so be proper size
//     initSparseMat(&returnMat, A->m, A->n);

//     // Eh everything is easier with this multiplying factor
//     int mFact = 1;
//     while (A->n / mFact > 1)
//         mFact *= 10;

//     // Need two indices to keep track of two arrays. NOTE, arrays must both be sorted
//     int i = 0, j = 0;
//     struct MatrixEntry entry;

//     while (i < A->entries && j < B->entries)
//     {
//         int Aind = mFact * A->mat[i].row + A->mat[i].col;
//         int Bind = mFact * B->mat[j].row + B->mat[j].col;

//         // Scenario 1: value exists for index in both A and B
//         if (Aind == Bind)
//         {
//             entry.row = A->mat[i].row;
//             entry.col = A->mat[i].col;
//             entry.val = A->mat[i].val + B->mat[j].val;

//             // Increase both i and j because we've just taken care of both entries
//             i++;
//             j++;
//         }
//         // Scenario 2: index is smaller for A mat and therefore it should be appended to return array
//         else if (Aind < Bind)
//         {
//             entry.row = A->mat[i].row;
//             entry.col = A->mat[i].col;
//             entry.val = A->mat[i].val;

//             i++;
//         }
//         // Scenario 3: index is smaller for B mat and therefore it should be appended to return array
//         else
//         {
//             entry.row = B->mat[j].row;
//             entry.col = B->mat[j].col;
//             entry.val = B->mat[j].val;

//             j++;
//         }

//         appendSparseMat(&returnMat, entry);
//     }

//     // Get last entries in for both arrays
//     for (; i < A->entries; i++)
//     {
//         entry.row = A->mat[i].row;
//         entry.col = A->mat[i].col;
//         entry.val = A->mat[i].val;
//         appendSparseMat(&returnMat, entry);
//     }

//     for (; j < B->entries; j++)
//     {
//         entry.row = B->mat[j].row;
//         entry.col = B->mat[j].col;
//         entry.val = B->mat[j].val;
//         appendSparseMat(&returnMat, entry);
//     }

//     return returnMat;
// }