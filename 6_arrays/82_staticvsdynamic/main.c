#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

int processCount;

int main(int argc, char *argv[])
{
    int c, index;
    int x=0;
    int n=0;
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

    printf("\nx: %d", x);
    printf("\nn: %d\n", n);

    printf("\nProcess count: %d\n\n", processCount);

    return 0;
}
