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

    if(row >= A->m)
    {
        printf("\nError: Cannot append node, row out of range");
        return;
    }

    if(col >= A->n)
    {
        printf("\nError: Cannot append node, col out of range");
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
    while(p->next)
        p = p->next;

    p->next = new;
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
        return -1;
    }    

    int x = INT_MIN; // Keeps track of current lowest value. Needed since it's a linked list, not array
    struct SMNode *p = A->first;

    //Get multiplier to have a better way to index rows and cols
    int mFact = 1;
    while(A->n / mFact >= 1)
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
    while(A->n / mFact >= 1)
        mFact *= 10;
    
    _mergeSortNodes(&(A->first), mFact);        
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