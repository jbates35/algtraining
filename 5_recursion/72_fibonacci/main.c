#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

int fib(int n);

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
    printf("Fib of n = %d\n", fib(n));

    return 0;
}

int fib(int n) 
{
    if(n<=1) return n;
    return fib(n-2)+fib(n-1);
}
