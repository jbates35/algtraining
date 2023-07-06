#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <time.h>
#include <stdbool.h>

#include "arrayAdt.h"
#include "helpFuncs.h"

struct Pairs {
    int x1;
    int x2;
    int ind1;
    int ind2;
};

struct ArrayPairs {
    struct Pairs* pairs;
    int size;
    int length;
};

int appendPairs(struct ArrayPairs* arr, struct Pairs pair) 
{
    if(arr==NULL)
        return -1;
    
    if(arr->length == arr->size)
    {
        arr->size *= 2;
        arr->pairs = (struct Pairs*) realloc(arr->pairs, sizeof(struct Pairs*) * arr->size);
    }

    arr->pairs[arr->length++] = pair;
}

struct ArrayPairs *findSumPairs(struct ArrayInt *arr, int sum);

int main(int argc, char *argv[])
{
    int c;
    opterr = 0;

    struct ArrayInt arr;
    arr.length = 0;
    arr.size = 1000;

    int sum = 0;

    while ((c = getopt(argc, argv, "s:l:x:")) != -1)
    {
        switch (c)
        {
        case 's':
            sum = atoi(optarg);
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

    struct ArrayPairs *pairsArr = findSumPairs(&arr, sum);

    if (pairsArr->length == 0)
    {
        printf("\nNo values were sums\n\n");
    }
    else
    {
        printf("\nPairs found!! Displaying pairs!");
        for(int i = 0; i < pairsArr->length; i++)
            printf("\nPair %d: <%d, %d>", i, pairsArr->pairs[i].x1, pairsArr->pairs[i].x2);
    }

    printf("\n\n");

    freeADT(&arr);
    free(pairsArr->pairs);
    free(pairsArr);

    return 0;
}

struct ArrayPairs *findSumPairs(struct ArrayInt *arr, int sum)
{
    struct ArrayPairs *pairsArr = (struct ArrayPairs*) malloc(sizeof(struct ArrayPairs));
    pairsArr->size=10;
    pairsArr->length=0;
    pairsArr->pairs = (struct Pairs*) malloc(sizeof(struct Pairs) * pairsArr->size);

    if(arr==NULL)
    {    
        fprintf(stderr, "\nError: Null pointer in findMissingVals");
        return NULL;
    }

    if(arr->length <= 1)
    {    
        printf("Need array list of 2 or more");
        return pairsArr;
    }

    //This one requires being sorted
    if(!isSortedADT(arr))
        mergeSortADT(arr);

    // General idea is -
    //  This will be O(n)
    //  Since this is sorted, I can attack this problem from both sides of the array
    //  After writing this out, I realize if the sum of the two pairs is greater than the desired value, then j needs to dec
    //  If it's less, then i needs to inc
    //  Should watch out for duplicates
    int i = 0;
    int j = arr->length-1;

    while(i < j)
    {
        //Decrement j if sum is too large, increment i if sum is too small
        if(arr->A[i] + arr->A[j] > sum)
        {
            j--;
            continue;
        }
        else if(arr->A[i] + arr->A[j] < sum)
        {
            i++;
            continue;
        }

        //To reach here, this must mean we have a sum
        struct Pairs pair = { arr->A[i], arr->A[j], i, j };
        appendPairs(pairsArr, pair);

        i++;
        j--;

        //Look ahead to find duplicates
        while(arr->A[i-1] == arr->A[i])
            i++;
        while(arr->A[j+1] == arr->A[j])
            j--;
    }

    return pairsArr;
}