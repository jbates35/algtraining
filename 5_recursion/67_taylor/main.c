#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

double e(int x, int n);

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
    static int p=1;
    static int f=1;

    if(n==0)
        return 1.0;
    
    double r = e(x, n-1);

    p = p * x;
    f = f * n;

    return r + (double) p/f;
}