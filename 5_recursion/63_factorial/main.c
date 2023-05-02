#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

int fact(int n);

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
    printf("Fib of n = %d\n", fact(n));

    return 0;
}

int fact(int n) 
{
    if(n==0)
    {
        return 1;
    }
    else 
    {
        return fact(n-1)*n;
    }
}