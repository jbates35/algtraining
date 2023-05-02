#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

int exampRec(int n);

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
    
    printf("Main function called with n=%d\n\n",n);

    printf("Result: %d\n", exampRec(n));

    return 0;
}

int exampRec(int n)
{
    int r=0;
    static int factor = 2;

    if(n!=0)
    {
        r = exampRec(n-1);
    }

    factor = factor * 2;

    return r + factor;
}
