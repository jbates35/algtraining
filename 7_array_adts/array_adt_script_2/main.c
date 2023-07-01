#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <time.h>

#include "arrayAdt.h"
#include "sampleArrays.h"
#include "helpFuncs.h"


int processCount;

int main(int argc, char *argv[])
{
    int c, index;
    int x=0;
    int n=0;
    opterr = 0;

    while((c = getopt(argc, argv, "x:n:")) != -1)
    {
        switch(c)
        {
        case 'x':
            x = atoi(optarg);
            break;
        case 'n':
            n = atoi(optarg);
            break;
        }
    }

    // printf("\nx: %d", x);
    // printf("\nn: %d\n", n);

    //For calculating processing time
    clock_t start, end;

    int tempA[] = { 
         3, 5, 2, 6, 3, 4, 7, 10, 12, 10
    };

    int tempB[] = {
        4, 9, 12, 5, 7, 5, 19, 21, 12, 8
    };

    struct ArrayInt arr1;
    struct ArrayInt arr2;
    struct ArrayInt arr3;

    initADT(&arr1, sampleArray0, 6, 6);
    initADT(&arr2, sampleArray1, 6, 6);

    funcShow(displayADT, &arr1, "Showing array 1");
    funcShow(displayADT, &arr2, "Showing array 2");

    funcTime(bubbleSortADT, &arr1, "Bubble-sort");
    funcTime(mergeSortADT, &arr2, "Merge-Sort");
    
    funcShow(displayADT, &arr1, "\nShowing array 1");
    funcShow(displayADT, &arr2, "Showing array 2");

    mergeADT(&arr1, &arr2, &arr3);
    funcShow(displayADT, &arr3, "Merging the two arrays");
    
    initADT(&arr1, tempA, sizeof(tempA)/sizeof(int), sizeof(tempA)/sizeof(int));
    initADT(&arr2, tempB, sizeof(tempB)/sizeof(int), sizeof(tempB)/sizeof(int));

    // funcShow(displayADT, &arr1, "Showing array 1");
    // funcShow(displayADT, &arr2, "Showing array 2");

    // unionADT(&arr1, &arr2, &arr3);
    // mergeSortADT(&arr3);
    // funcShow(displayADT, &arr3, "Showing array 3 after union");

    // intersectADT(&arr1, &arr2, &arr3);
    // mergeSortADT(&arr3);
    // funcShow(displayADT, &arr3, "Showing array 3 after intersect");

    differenceADT(&arr1, &arr2, &arr3);
    mergeSortADT(&arr3);
    funcShow(displayADT, &arr3, "Showing array 3 after difference");

    freeADT(&arr1);
    freeADT(&arr2);
    freeADT(&arr3);

    // printf("\nProcess count: %d\n\n", processCount);

    return 0;
}
