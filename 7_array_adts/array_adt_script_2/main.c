#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

#include "arrayAdt.h"

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

    int tempA[] = { 
         3, 5, 2, 6, 3, 4, 7, 10, 12, 10
    };

    int tempB[] = {
        4, 9, 12, 5, 7, 5, 19, 21, 12, 8
    };

    struct ArrayInt arr1;
    struct ArrayInt arr2;

    initADT(&arr1, tempA, 20, sizeof(tempA)/sizeof(int));
    initADT(&arr2, tempB, 20, sizeof(tempB)/sizeof(int));
    
    printf("\nDisplaying array 1:");
    displayADT(&arr1);

    printf("\nNow sorting array 1:");
    bubbleSortADT(&arr1);
    displayADT(&arr1);

    printf("\nDisplaying array 2:");
    displayADT(&arr1);

    printf("\nNow sorting array 2:");
    dncSortADT(&arr1, 0, arr1.length-1);
    displayADT(&arr1);

    freeADT(&arr1);
    freeADT(&arr2);

    printf("\nProcess count: %d\n\n", processCount);

    return 0;
}
