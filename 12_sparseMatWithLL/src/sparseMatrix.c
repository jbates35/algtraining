#include "sparseMatrix.h"
#include "helpFuncs.h" 

#define CALC_NEW_INDEX(node, factor) ((node)->entry.row * factor + (node)->entry.col)

void _mergeSortNodes(struct SMNode **first, int mFact);

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
        return;
    }

    struct MatrixEntry matEntry = {
        row,
        col,
        val
    };

    struct SMNode *new = (struct SMNode*) malloc(sizeof(struct SMNode));
    new->next = NULL;
    new->entry = matEntry;
    
    //if first entry, need to deal w that
    if(A->first == NULL)
    {
        A->first = new;
        return;
    }

    struct SMNode *p = A->first;

}

void printEntries(struct SparseMatrix *A)
{
    if (A == NULL)
    {
        fprintf(stderr, "\nError: Null pointer in printEntries");
        return;
    }

    struct SMNode *p = A->first;

    while(p)
    {
        printf("| Row %d\t| Col %d\t| Val %d\n", p->entry.row, p->entry.col, p->entry.val);
        p = p->next;
    }
}

void displayMatrix(struct SparseMatrix *A)
{
    if (A == NULL)
    {
        fprintf(stderr, "\nError: null pointer in displayMatrix");
        return;
    }

    // Sort matrix if need be
    if(!isSortedMat(A))
        mergeSortMat(A);

    struct SMNode *p = A->first;
    int currInd = 0;

    printf("\n");

    for (int i = 0; i < A->m; i++)
    {
        for (int j = 0; j < A->n; j++)
        {
            if (p->entry.row == i && p->entry.col == j)
            {
                printf("%d\t", p->entry.val);
                p = p->next;
            }
            else
                printf("0\t");
        }
        printf("\n");
    }
}

int isSortedMat(struct SparseMatrix *A)
{
    if(!A)
    {
        fflush(stdout);
        fprintf(stderr, "\nNULL POINTER being fed into isSortedList");
        return;
    }    

    int x = INT_MIN; // Keeps track of current lowest value. Needed since it's a linked list, not array
    struct SMNode *p = A->first;

    //Get multiplier to have a better way to index rows and cols
    int mFact = 1;
    while(A->n % mFact >= 1)
        mFact *= 10;

    //Checks last value to see if it's higher than the current val
    while(p)
    {
        int newInd = p->entry.row * mFact + p->entry.col;

        //If x is greater than p val, then not sorted
        if(newInd < x)
            return 0;

        x = newInd;
        p = p->next;
    }

    return 1;
}

void mergeSortMat(struct SparseMatrix *A)
{
    if(!A)
    {
        fflush(stdout);
        fprintf(stderr, "\nNULL POINTER being fed into mergeSortMat");
        return;
    }    

    //simply return in these next two conditionals as this list cannot possibly be sorted
    if(A->first == NULL || (A->first)->next == NULL)
        return;
    
    //Need index modifier for comparing entry indices
    int mFact = 1;
    while(A->n % mFact >= 1)
        mFact *= 10;
    
    _mergeSortNodes(A->first, mFact);        
}

void _mergeSortNodes(struct SMNode **first, int mFact)
{
    if(*first == NULL || (*first)->next == NULL)
        return;
    
    //to get halfway, q runs at double the speed as p
    struct SMNode *p = *first;
    struct SMNode *q = p;
    int counter = 0; //helper for tracking list with modulus
    
    while(q)
    {
        q = q->next;
        
        if(!q)
            break;
            
        if((counter++)%2 == 1)
            p = p->next;
    }

    //Now break up list into two
    q = p->next;
    p->next = NULL;
    p = *first;

    _mergeSortNodes(&p, mFact);
    _mergeSortNodes(&q, mFact);

    struct SMNode *r;

    //Need to get modified index, this is what we are actually comparing
    int pInd = CALC_NEW_INDEX(p, mFact);
    int qInd = CALC_NEW_INDEX(q, mFact);

    // Get the first node
    if(pInd < qInd)
    {
        r = p;
        p = p->next;
    }
    else
    {
        r = q;
        q = q->next;
    }
    *first = r;

    // Now we can merge the two lists while both p and q are not null
    while(p && q)
    {
        pInd = CALC_NEW_INDEX(p, mFact);
        qInd = CALC_NEW_INDEX(q, mFact);

        if(pInd < qInd)
        {
            r->next = p;
            p = p->next;
        }
        else
        {
            r->next = q;
            q = q->next;
        }

        r = r->next;
    }

    // Dump the rest of the list into r, whichever one is left
    if(p)
        r->next = p;
    else
        r->next = q;
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
