#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

double taylorSum(double x, int n);

int main(int argc, char *argv[])
{
    int c, index;
    int n=1;
    int x=1;
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

    double sum = taylorSum(x, n);

    printf("Sum: %lf",sum);

    return 0;
}

double taylorSum(double x, int n)
{
    static double sum = 1;

    if(n>0)
    {
        sum = 1+x/n*sum;
        return taylorSum(x,n-1);
    }
    else
        return sum;
}