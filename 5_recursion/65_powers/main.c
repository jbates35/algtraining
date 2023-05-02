#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

int powers(int m, int n);

int main(int argc, char *argv[])
{
    int c, index;
    int n=0;
    int m=0;
    opterr = 0;

    while((c = getopt(argc, argv, "m:n:")) != -1)
    {
        switch(c)
        {
        case 'n':
            n = atoi(optarg);
            break;

        case 'm':
            m = atoi(optarg);
            break;        
        }
    }

    printf("m = %d\n", m);
    printf("n = %d\n", n);
    printf("m^n = %d\n", powers(m,n));

    return 0;
}

int powers(int m, int n)
{
    if(n==1)
        return m;
    else if(n==0)
        return 1;
    else 
        return powers(m,n/2)*powers(m,n/2)*powers(m,n%2);
}