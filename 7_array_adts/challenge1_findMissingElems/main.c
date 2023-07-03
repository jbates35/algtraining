#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <time.h>
#include <stdbool.h>

#include "arrayAdt.h"
#include "helpFuncs.h"

int processCount;

int main(int argc, char *argv[])
{
    int c, index;
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

    // Lets make sure it's sorted first
    if (!isSortedADT(&arr))
    {
        mergeSortADT(&arr);
    }

    // Show array for context
    funcShow(displayADT, &arr, "Showing array vals:");

    // General idea is -
    //   Should start at val 0 in array, end at length-1
    //   Then when the val doesn't equal the indexing integer, we know it's the missing value.
    //   Since only one value is required, we can break from there and end the program
    int missingVal = -1;
    int compareVal = arr.A[0];

    for (int i = 0; i < arr.length; i++)
    {
        if (arr.A[i] == compareVal)
            continue;

        compareVal++;

        if (arr.A[i] != compareVal)
        {
            missingVal = compareVal;
            break;
        }
    }

    if (missingVal == -1)
        printf("\nNo value was missing\n\n");
    else
        printf("\nMissing value was %d\n\n", missingVal);

    freeADT(&arr);

    return 0;
}
