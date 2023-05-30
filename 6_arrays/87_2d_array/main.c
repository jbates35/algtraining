#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <unistd.h>
#include <sys/select.h>
#include <memory.h>

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

    printf("\nn: %d\n\n", n);

    int A[3][4] = {
        { 4, 6, 4, 5 },
        { 2, 3, 6, 7 },
        { 1, 6, 4, 3 }
    };

    int *B[3];

    B[0] = (int *) malloc(sizeof(int) * 4);
    B[1] = (int *) malloc(sizeof(int) * 4);
    B[2] = (int *) malloc(sizeof(int) * 4);

    printf("\nB is: \n");

    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 4; j++)
        {
            B[i][j] = A[i][j] * 2;
            printf("\t%d\n", B[i][j]);
        }

    
    int **C;
    C = (int**) malloc(sizeof(int*) * 3);
    C[0] = (int*) malloc(sizeof(int) * 4);
    C[1] = (int*) malloc(sizeof(int) * 4);
    C[2] = (int*) malloc(sizeof(int) * 4);

    printf("\nC is: \n");
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 4; j++)
        {
            C[i][j] = A[i][j] * 3;
            printf("\t%d\n", C[i][j]);
        }

    free(C);
    C = NULL;

    free(B[0]);
    free(B[1]);
    free(B[2]);
    B[0] = NULL;
    B[1] = NULL;
    B[2] = NULL;

    printf("\nProcess count: %d\n\n", processCount);

    return 0;
}

