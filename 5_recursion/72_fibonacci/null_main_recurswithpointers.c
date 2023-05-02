#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

void fib(int *sum, int *n);

int main(int argc, char *argv[])
{
    int c, index;
    int n=0;
    opterr = 0;

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

    int sum = 0;
    fib(&sum, &n);
     
    printf("Fib of n = %d\n", sum);

    return 0;
}

void fib(int *sum, int *n) 
{
    static int k1 = 0;
    static int k2 = 0;

    *sum += k2;
    if(*sum == 0) *sum = 1;
    
    k2 = k1;
    k1 = *sum;

    if(*n != 0)
    {   
        (*n)--;
        fib(sum, n);
    }
}