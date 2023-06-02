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

    struct ArrayInt arr;

    init_intArrayAdt(&arr, tempA, 20, 5);

    printf("\nInitial array is");
    display_intArrayAdt(&arr);
    
    printf("\nAppending 8 to end of array");
    append_intArrayAdt(&arr, 8);
    display_intArrayAdt(&arr);

    printf("\nInserting 10 into the 7th element of array");
    insert_intArrayAdt(&arr, 10, 6);
    display_intArrayAdt(&arr);

    printf("\nInserting 7 into the 7th element of array");
    insert_intArrayAdt(&arr, 7, 6);
    display_intArrayAdt(&arr);

    printf("\nDeleting 6th element of array");
    delete_intArrayAdt(&arr, 5);
    display_intArrayAdt(&arr);

    printf("\nSearching for val==6");
    int key = linSearch_intArrayAdt(&arr, 6);
    printf("\nKey==%d\n", key);

    //Make new array
    printf("\nMaking new array...");
    int tempB[] = { 
         4, 8, 10, 15, 18, 21, 24, 27, 29, 33, 34, 37, 39, 41, 43
    };
    init_intArrayAdt(&arr, tempB, 20, sizeof(tempB)/sizeof(int));    
    display_intArrayAdt(&arr);

    printf("\nBinary search for value 18");
    key = binSearch_intArrayAdt(&arr, 18, 0, arr.length);
    printf("\nKey for 18 is %d\n", key);
    
    printf("\nBinary search for value 43");
    key = binSearch_intArrayAdt(&arr, 43, 0, arr.length);
    printf("\nKey for 43 is %d\n", key);

    printf("\nBinary search for value 33");
    key = binSearch_intArrayAdt(&arr, 33, 0, arr.length);
    printf("\nKey for 33 is %d\n", key);

    printf("\nBinary search for value 35");
    key = binSearch_intArrayAdt(&arr, 35, 0, arr.length);
    printf("\nKey for 35 is %d\n", key);

    printf("\nMaking new array...");
    int tempC[] = {
        5, 29, 3, 206, 495, 10, 106, 4, 693, 40, 20, 5, 105, 106, 604, 602, 105, 6, 50, 55, 1
    };
    init_intArrayAdt(&arr, tempC, 40, sizeof(tempC)/sizeof(int));    
    display_intArrayAdt(&arr);

    printf("\nReversing array");
    reverse_intArrayAdt(&arr);
    display_intArrayAdt(&arr);

    printf("\nShifting to the right, 3 spots");
    shift_intArrayAdt(&arr, 3, RIGHT);  
    display_intArrayAdt(&arr);

    printf("\nReinitializing array");
    init_intArrayAdt(&arr, tempC, 40, sizeof(tempC)/sizeof(int));    
    display_intArrayAdt(&arr);

    printf("\nShifting to the left, 3 spots");
    shift_intArrayAdt(&arr, 3, LEFT);  
    display_intArrayAdt(&arr);
    
    printf("\nShifting to the left, 1 spot");
    shift_intArrayAdt(&arr, 1, LEFT);  
    display_intArrayAdt(&arr);
    
    printf("\nShifting to the left, 0 spots");
    shift_intArrayAdt(&arr, 0, LEFT);  
    display_intArrayAdt(&arr);

    printf("\nShifting to the left, 30 spots");
    shift_intArrayAdt(&arr, 30, LEFT);  
    display_intArrayAdt(&arr);

    printf("\nReinitializing array");
    init_intArrayAdt(&arr, tempC, 40, sizeof(tempC)/sizeof(int));    
    display_intArrayAdt(&arr);

    printf("\nRotating to the left, 23 spots (meaning 2 spots)");
    rotate_intArrayAdt(&arr, 23, LEFT);  
    display_intArrayAdt(&arr);

    printf("\nRotating to the left, 1 spots");
    rotate_intArrayAdt(&arr, 1, LEFT);  
    display_intArrayAdt(&arr);

    printf("\nRotating to the left, 3 spots");
    rotate_intArrayAdt(&arr, 3, LEFT);  
    display_intArrayAdt(&arr);

    printf("\nRotating to the right, 3 spots");
    rotate_intArrayAdt(&arr, 3, RIGHT);  
    display_intArrayAdt(&arr);

    printf("\nRotating to the right, 1 spots");
    rotate_intArrayAdt(&arr, 1, RIGHT);  
    display_intArrayAdt(&arr);

    printf("\nRotating to the right, 23 spots (meaning 2 spots)");
    rotate_intArrayAdt(&arr, 23, RIGHT);  
    display_intArrayAdt(&arr);

    free_intArrayAdt(&arr);

    printf("\nProcess count: %d\n\n", processCount);

    return 0;
}
