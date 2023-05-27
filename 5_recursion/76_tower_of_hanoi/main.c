#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <unistd.h>
#include <sys/select.h>

#define MAX_SIZE 10
#define BLOCK "\u25A0"

int processCount;

char pieces[MAX_SIZE];

void towerOfHanoi(int n, char *A, char *B, char *C);

int main(int argc, char *argv[])
{
    int c, index;
    int x=0;
    int n=0;
    opterr = 0;

    char A = 'A';
    char B = 'B';
    char C = 'C';

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

    for(int i = 0; i < n; i++)
    {
        printf(BLOCK);
    }

    printf("\nn: %d\n\n", n);

    towerOfHanoi(n, &A, &B, &C);

    printf("\nProcess count: %d\n\n", processCount);

    return 0;
}

void towerOfHanoi(int n, char *A, char *B, char *C) 
{
    if(n == 0) return;
    
    processCount++;
    
    towerOfHanoi(n-1, A, C, B);
    printf("Moving %d from %c to %c\n", n, *A, *C);
    towerOfHanoi(n-1, B, A, C);
}
