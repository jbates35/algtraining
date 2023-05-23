#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>


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

    double sum=1;

    for(int i=n; i>0; i--)
    {
        sum = sum*x/i + 1;
    }

    printf("Sum: %lf",sum);

    return 0;
}
