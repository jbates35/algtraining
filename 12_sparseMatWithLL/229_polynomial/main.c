#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

#include "poly.h"

#define INTSIZEOF(arr) sizeof(arr)/sizeof(int)

int main(int argc, char *argv[])
{
    int c;
    opterr = 0;
    char *str;
    char *token;
    const char s[2] = " ";
    double x = 0;
    while ((c = getopt(argc, argv, "c:x:")) != -1)
    {
        switch (c)
        {
        case 'c':
            str = optarg;
            break;
        case 'x':
            x = atof(optarg);
            break;
        }
    }

    struct Term *poly = NULL;
    int coefs[100];
    int pos = 0;

    for(int i = 0; i < INTSIZEOF(coefs); i++)
        coefs[i] = 0;

    token = strtok(str, s);
    while(token != NULL)
    {
        coefs[pos++] = atoi(token);    
        token = strtok(NULL, s);
    }

    for(int i = INTSIZEOF(coefs)-1; i >= 0; i--)
    {
        if(coefs[i] != 0)
            appendTerm(&poly, i, coefs[i]);
    }

    printf("\nShowing equation:");
    displayEq(poly);
    printf("Solving this gives us %.3f\n\n", solvePoly(poly, x));
    freeTerms(poly);
}

