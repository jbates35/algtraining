#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <unistd.h>
#include <sys/select.h>

int processCount;

int main(int argc, char *argv[])
{
    int c, index;
    //int x=0;
    int n=0;
    opterr = 0;

    while((c = getopt(argc, argv, "x:n:")) != -1)
    {
        switch(c)
        {
        case 'n':
            n = atoi(optarg);
            break;
        }
    }

    printf("\nn: %d\n\n", n);

    unsigned int x[4][3] ={
        {1, 2, 3}, 
        {4, 5, 6}, 
        {7, 8, 9}, 
        {10, 11, 12}
        }; 

    printf("%u\n%u\n%u", x+3, *(x+3), *(x+2)+3);  

    printf("\nProcess count: %d\n\n", processCount);

    return 0;
}
