#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <unistd.h>
#include <memory.h>
#include <sys/select.h>

int processCount;

struct Array {
    int *A;
    int size;
    int length;
};

void Display(struct Array *arr);

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

    struct Array arr;

    printf("Enter size of array");
    scanf("%d", &arr.size);

    arr.A = (int *) malloc (sizeof(int) * arr.size);
    arr.length = 0;

    printf("Enter number of numbers");
    scanf("%d", &arr.length);

    printf("Enter all elements");
    for(int i= 0; i<arr.length; i++)
    {   
        scanf("%d", &arr.A[i]);
    }

    Display(&arr);

    return 0;
}

void Display(struct Array *arr)
{
    int i;
    printf("\nElements are\n");

    for(int i=0; i < (*arr).length; i++)
    {
        printf("Integer %d:\t%d\n", i, (*arr).A[i]);
    }
}

