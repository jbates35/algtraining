#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <time.h>
#include <stdbool.h>

#include "arrayAdt.h"
#include "helpFuncs.h"

int processCount;

struct Point {
    int point;
    int index;
};

int minMax(struct ArrayInt *arr, struct Point* min, struct Point* max);

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

    struct Point min, max;
    minMax(&arr, &min, &max);

    printf("\nMinimum point is %d at index %d", min.point, min.index);
    printf("\nMaximum point is %d at index %d\n\n", max.point, max.index);

    freeADT(&arr);
    return 0;
}

int minMax(struct ArrayInt *arr, struct Point* min, struct Point* max)
{
    if(arr==NULL)
    {    
        fprintf(stderr, "\nError: Null pointer in findMissingVals");
        return -1;
    }

    min->point = arr->A[0];
    min->index = 0;
    max->point = arr->A[0];
    max->index = 0;

    for(int i = 1; i < arr->length; i++)
    {
        if(arr->A[i] < min->point)
        {
            min->point = arr->A[i];
            min->index = i;
        }

        if(arr->A[i] > max->point)
        {
            max->point = arr->A[i];
            max->index = i;
        }
    }

    return 0;
}