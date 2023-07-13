#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <time.h>
#include <stdbool.h>

#include "arrayAdt.h"
#include "smatrixAdt.h"
#include "helpFuncs.h"

int main(int argc, char *argv[])
{
    int c;
    opterr = 0;
    char *str;

    struct ArrayInt arr;
    arr.length = 0;
    arr.size = 1000;

    int rows;

    struct SRMatInt mat;

    while ((c = getopt(argc, argv, "x:r:")) != -1)
    {
        switch (c)
        {
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
        case 'r':
            rows = atoi(optarg);
            break;
        }
    }

    // Show array for context
    funcShow(displayADT, &arr, "Showing array vals:");

    initSRUpTri(&mat, &arr, rows);
    dispSRUpTri(&mat);

    int rowChange, colChange, xChange;
    printf("\nEnter a row to change:\n");
    scanf("%d", &rowChange);
    printf("\nEnter a col to change:\n");
    scanf("%d", &colChange);
    printf("\nEnter a value to change it to:\n");
    scanf("%d", &xChange);

    setSRUpTri(&mat, rowChange, colChange, xChange);

    printf("\nNew Matrix:\n");
    dispSRUpTri(&mat);

    freeADT(&arr);
    freeSRUpTri(&mat);

    return 0;
}
