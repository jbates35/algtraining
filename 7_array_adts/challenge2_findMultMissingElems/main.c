#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <time.h>
#include <stdbool.h>

#include "arrayAdt.h"
#include "helpFuncs.h"

int processCount;

struct ArrayInt *findMissingVals(struct ArrayInt *arr);

int main(int argc, char *argv[])
{
    int c;
    opterr = 0;

    struct ArrayInt arr;
    arr.length = 0;
    arr.size = 1000;

    while ((c = getopt(argc, argv, "s:l:x:")) != -1)
    {
        switch (c)
        {
        case 's':
            arr.size = atoi(optarg);
            break;
        case 'x':
            char *x = optarg;
            arr.A = (int *)malloc(sizeof(int) * arr.size);
            bool isSpaced = false; // Needed to make sure "4  5", for example, isn't parsed as { 4, 0, 0, 5 }

            // Delimit by ' ' or ','
            for (int i = 0;; i++)
            {
                // If ',' or ' ', then dump into array
                if (x[i] == ',' || x[i] == ' ')
                {
                    // If statement prevents having unnecessary 0's in array
                    if (!isSpaced)
                        arr.length++;
                    isSpaced = true;
                    continue;
                }

                isSpaced = false;

                // Finish up array - just doing the for loop this way so I don't have to have trailing commands after the for loop
                if (x[i] == '\0')
                {
                    arr.length++;
                    break;
                }

                // Pity the foo who don't put a number here
                if (x[i] < 48 || x[i] > 57)
                    continue;

                // Shift the number in there to the left, and then take in the current LSD
                arr.A[arr.length] *= 10;
                arr.A[arr.length] += x[i] - 48;
            }

            break;
        }
    }

    // Program start, make sure we have enough values
    if (arr.length < 2)
    {
        printf("\nERROR: Not enough values in array for this exercise to be meaningful");
        freeADT(&arr);
        return -1;
    }

    // Show array for context
    funcShow(displayADT, &arr, "Showing array vals:");

    struct ArrayInt *missingVals = findMissingVals(&arr);

    if (missingVals->length == 0)
        printf("\nNo value was missing\n\n");
    else
        funcShow(displayADT, missingVals, "Missing values are:");

    getADT(missingVals, 50);

    freeADT(missingVals);
    freeADT(&arr);
    free(missingVals);

    return 0;
}

struct ArrayInt *findMissingVals(struct ArrayInt *arr)
{
    struct ArrayInt *missingVals = (struct ArrayInt*) malloc(sizeof(struct ArrayInt));
    initADT(missingVals, NULL, 10, 0);

    if(arr==NULL)
    {    
        fprintf(stderr, "\nError: Null pointer in findMissingVals");
        return NULL;
    }

    // Lets make sure it's sorted first
    if (!isSortedADT(arr))
    {
        mergeSortADT(arr);
    }

    // General idea is -
    //   Should start at val 0 in array, end at length-1
    //   Then when the val doesn't equal the indexing integer, we know it's the missing value.
    //   We need to make sure that there is a while loop which keeps track of when numbers have been missed
    //   This way, we catch all the numbers that are missing
    int compareVal = arr->A[0];

    for (int i = 0; i < arr->length; i++)
    {
        if (arr->A[i] == compareVal)
            continue;

        compareVal++;

        while (arr->A[i] != compareVal)
        {
            appendADT(missingVals, compareVal);
            compareVal++;
        }
    }
    
    return missingVals;
}