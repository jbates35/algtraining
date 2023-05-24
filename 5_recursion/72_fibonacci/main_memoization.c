#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

int fibVals[100];
int processCount=0;

int fib(int n);

int main(int argc, char *argv[])
{
    int c, index;
    int n=0;
    opterr = 0;

    for(int i=0; i<sizeof(fibVals)/sizeof(int); i++) 
        fibVals[i] = -1;
        

    printf("\n");

    while((c = getopt(argc, argv, "n:")) != -1)
    {
        switch(c)
        {
        case 'n':
            n = atoi(optarg);
            break;
        }
    }

    printf("n = %d\n", n);
    printf("Fib of n = %d\n", fib(n));

    printf("\nProcess count: %d\n\n", processCount);

    return 0;
}

int fib(int n) 
{
    processCount++;

    if(n<=1) 
    {
        fibVals[n] = n;
        return fibVals[n];
    }   
    
    if(fibVals[n] == -1) 
        fibVals[n] = fib(n-1) + fib(n-2);

    return fibVals[n];
}
