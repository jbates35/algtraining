#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <time.h>
#include <stdbool.h>

int diagMatrix();

int main(int argc, char *argv[])
{
    int c;
    opterr = 0;
    char *str;

    while ((c = getopt(argc, argv, "x:")) != -1)
    {
        switch (c)
        {
        case 'x':
            str = optarg;
            break;
        }
    }

    return 0;
}
