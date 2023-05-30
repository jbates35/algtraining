#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <unistd.h>
#include <memory.h>
#include <sys/select.h>

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

    int A[5] = {
        4,5,6,3,3
    };


    printf("\nA: \n");

    for(int i = 0; i<5; i++)
    {
        printf("\t%d\n", A[i]);
    }

    int *q = (int*) malloc (10 * sizeof(int));

    for(int i = 0; i<sizeof(A)/sizeof(int); i++) 
    {
        q[i] = A[i];
        q[i+sizeof(A)/sizeof(int)] = A[i] + 10;
    }

    printf("\nQ: \n");

    for(int i = 0; i<10; i++)
    {
        printf("\t%d\n", q[i]);
    }

    free(q);

    int* p; 
    p=q;

    q = NULL;

    p = (int*)malloc(5*sizeof(int));
    printf("\nP: \n");
    for(int i = 0; i < 5; i++) {
        p[i] = (i+1)*(i+1);
        printf("\t%d\n", p[i]);
    }

    printf("\nProcess count: %d\n\n", processCount);

    free(p);
    p=NULL;

    return 0;
}

