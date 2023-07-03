#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <time.h>

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

    printf("\nx: %d", x);
    printf("\nn: %d\n\n", n);

    char szText[] = "Hello World!";
    char *pText = szText;

    printf("%s\n%s\n", szText, pText);
    //Outputs: 
    // Hello World!
    // Hello World!

    pText+=6;

    printf("%s\n", pText);
    //Outputs: 
    // World!

    int aNums[] = { 1, 2, 3, 4, 5 };
    int *pNums = aNums;

    printf("\nPointer address: %u", &pNums);
    // Outputs 2132857680  
    
    pNums+=4;

    printf("\nPointer address: %u", &pNums);
    // Outputs 2132857680

    printf("\n%d\n\n", pNums[0]);
    //Outputs: 
    // 5

    // printf("\nProcess count: %d\n\n", processCount);

    return 0;
}
