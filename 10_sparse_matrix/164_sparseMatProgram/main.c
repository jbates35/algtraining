#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <time.h>
#include <stdbool.h>

#include "sparseMatrix.h"

void sortMatProgram(void);
void addMats(void);

int main(int argc, char *argv[])
{
    void (*fps[2])(void) = {
        &sortMatProgram,
        &addMats};

    int option = -1;

    while (option != 0)
    {
        printf("\n\nSelect options, or enter 0 to exit:");
        printf("\n\t(1) Enter one matrix and sort it");
        printf("\n\t(2) Add two matrices\n");

        scanf("%d", &option);

        // Execute function based on argument
        if (option != 0)
            fps[option - 1]();
    }

    return 0;
}

void sortMatProgram(void)
{
    struct SparseMatrix *mat;
    mat = (struct SparseMatrix*) malloc(sizeof(struct SparseMatrix));
    
    int rows = -1;
    int cols = -1;
    int elems = -1;

    typedef struct userInput {
        int val;
        char name[50];
    } userInput;

    userInput matInput[3] = {
        { -1, "rows" },
        { -1, "columns" },
        { -1, "entries" }
    };

    printf("\nSingle matrix only.");

    for(int i = 0; i < 2; i++)
    {
        do
        {
            printf("\nEnter number of %s:\n", matInput[i].name);
            scanf("%d", &matInput[i].val);
            if(matInput[i].val < 1) 
                fprintf(stderr, "\nWarning: %s must be a positive integer above 0\n", matInput[i].name);  
        }
        while(matInput[i].val < 1);
    }

    int maxVal = matInput[0].val * matInput[1].val;

    do
    {
        printf("\nEnter number of %s. Note the bounds has to be between 1 and %d (inclusive):\n", matInput[2].name, maxVal);
        scanf("%d", &matInput[2].val);
        if(matInput[2].val < 1) 
            fprintf(stderr, "\nWarning: %s must be between 1 and %d (inclusive)\n", matInput[2].name, maxVal);  
    }
    while(matInput[2].val < 1 || matInput[2].val > maxVal);

    initSparseMat(mat, matInput[0].val, matInput[1].val);
    printf("\nGreat! Generating a sparse matrix of %d rows and %d columns.", matInput[0].val, matInput[1].val); 
    printf("\n\nPlease enter the information for %d values:\n", matInput[2].val);

    //Need an array to keep of previous entered indices
    int *prevEntries = (int*) malloc(sizeof(int) * matInput[2].val);
    
    //Need multiplier to help keep track of row/col 
    int mFact = 1;
    while(matInput[1].val/mFact > 1)
        mFact *= 10;

    for(int i = 0; i < matInput[2].val; i++)
    {
        struct MatrixEntry entry;
        
        userInput entryInput[3] = {
            { -1, "row" },
            { -1, "column" },
            { -1, "value" }
        };

        for(int j = 0; j < 2; j++)
        {
            do
            {
                printf("\nEnter %s:\n", entryInput[j].name);
                scanf("%d", &entryInput[j].val);
                if(entryInput[j].val < 0 || entryInput[j].val >= matInput[j].val)
                    fprintf(stderr, "\nWarning: %s must be between 0 and %d\n", entryInput[j].name, matInput[j].val-1);  
            }
            while(entryInput[j].val < 0 || entryInput[j].val >= matInput[j].val);
        }

        //Need to make sure the value hasn't been added before
        int moddedIndex = mFact * entryInput[0].val + entryInput[1].val;
        bool indexExists = false;

        for(int j = 0; j < i; j++)
        {
            if(prevEntries[j] == moddedIndex)
            {
                indexExists=true;
                break;
            }
        }
        
        if(indexExists)
        {
            fprintf(stderr, "\nEntry already exists at that index.\n");
            i--;
            continue;
        }

        //Now add the modified index to the list of arrays to keep track in later iterations
        prevEntries[i] = moddedIndex;

        printf("\nEnter %s:\n", entryInput[2].name);
        scanf("%d", &entryInput[2].val);

        entry.row = entryInput[0].val;
        entry.col = entryInput[1].val;
        entry.val = entryInput[2].val;

        printf("\nAppending matrix with entry for row %d, column %d, with value %d\n", entry.row, entry.col, entry.val);

        appendSparseMat(mat, entry);
    }   

    printf("\nDisplaying matrix:\n");
    printEntries(mat);

    printf("\nSorting matrix...\n");
    sortSparseMat(mat);

    printf("\nDisplaying matrix:\n");
    printEntries(mat);

    free(prevEntries);
    prevEntries = NULL;

    freeSparseMat(mat);
    free(mat);
    mat = NULL;
}

void addMats(void)
{
}