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
    int k = 0;
    int sum = 0;

    int k1=0, k2=0;

    for(int i=0; i<n; i++)
    {
        sum = k1+k2;
     
        printf("%d\n", sum);

        if(sum==0) sum=1;

        k2 = k1;
        k1 = sum;        
    }    

    return sum;
}