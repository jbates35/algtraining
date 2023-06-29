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
         3, 5, 2, 6, 3 
    };

    int tempB[] = {
        4, 9, 12, 5, 7
    };

    struct ArrayInt arr1;
    struct ArrayInt arr2;

    initADT(&arr1, tempA, 20, sizeof(arr1)/sizeof(int));
    initADT(&arr2, tempB, 20, sizeof(arr2)/sizeof(int));
    
    

    freeADT(&arr1);
    freeADT(&arr2);

    printf("\nProcess count: %d\n\n", processCount);

    return 0;
}
