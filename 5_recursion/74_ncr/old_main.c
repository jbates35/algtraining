#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

int processCount;

double ncr(int n, int r);

int main(int argc, char *argv[])
{
    int c, index;
    int x=0;
    int n=0;
    int r=0;
    opterr = 0;

    while((c = getopt(argc, argv, "x:n:r:")) != -1)
    {
        switch(c)
        {
        case 'x':
            x = atoi(optarg);
            break;
        case 'n':
            n = atoi(optarg);
            break;
        case 'r':
            r = atoi(optarg);
            break;
        }
    }

    printf("\nn: %d", n);
    printf("\nr: %d\n", r);

    printf("\nnCr: %d\n", (int) ncr(n, r));

    printf("\nProcess count: %d\n\n", processCount);

    return 0;
}

double ncr(int n, int r)
{
    processCount++;
    
    if(r==1)
        return n; 
        
    return (double) n/r * ncr(n-1, r-1);
}