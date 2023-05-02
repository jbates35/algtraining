#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

int sum(int n);

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
    printf("sum(n) = %d\n", sum(n));

    return 0;
}

int sum(int n) 
{
    if(n == 0)
    {
        return n;
    }
    else 
    {
        return sum(n-1) + n;
    }
}