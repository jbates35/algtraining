#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

double e(int x, int n);

int fact(int n);
int power(int x, int n);

int main(int argc, char *argv[])
{
    int c, index;
    int n=0;
    int x=0;
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

    printf("x = %d\n", x);
    printf("n = %d\n", n);
    printf("f(n) = %f\n", e(x,n));

    return 0;
}

double e(int x, int n)
{
    if(n==0)
        return 1.0;
    else
    {
        return (double) power(x, n)/fact(n) + e(x, n-1);
    }
}

int fact(int n)
{
    if(n==0)
        return 1;
    else
        return n * fact(n-1);
}

int power(int x, int n)
{
    if(n==1)
        return x;
    else if(n==0)
        return 1;
    else 
        return power(x,n/2)*power(x,n/2)*power(x,n%2);
}