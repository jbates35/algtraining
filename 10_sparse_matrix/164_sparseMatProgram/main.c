#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <time.h>
#include <stdbool.h>

#include "sparseMatrix.h"

void enterMats(void);
void addMats(void);

int main(int argc, char *argv[])
{
    void (*fps[2])(void) = {
        &enterMats,
        &addMats};

    int option = -1;

    while (option != 0)
    {
        printf("\n\nSelect options, or enter 0 to exit:");
        printf("\n\t(1) Enter one matrix and sort it");
        printf("\n\t(2) Add two matrices\n");

        scanf("%d", &option);

        // Execute function based on argument
        if (option != 0)
            fps[option - 1]();
    }

    return 0;
}

void enterMats(void)
{
}

void addMats(void)
{
}