#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <time.h>
#include <stdbool.h>

//This version is without string.h
int permutation(const char *inputStr, char *outputStr);

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

    permutation(str, "");
    return 0;
}

int permutation(const char *inputStr, char *outputStr)
{
    // Get length of strings
    int inLen;
    for (inLen = 0; inputStr[inLen] != '\0'; inLen++)
        ;

    int outLen;
    for (outLen = 0; outputStr[outLen] != '\0'; outLen++)
        ;

    if (inLen == 0)
    {
        printf("%s\n", outputStr);
        return 1;
    }

    for (int i = 0; i < inLen; i++)
    {
        char pop = inputStr[i];
        char *newOutput = malloc(outLen + 2);
        char *newInput = malloc(inLen);

        int j;
        for (j = 0; j < outLen; j++)
        {
            newOutput[j] = outputStr[j];
        }
        newOutput[j++] = pop;
        newOutput[j] = '\0';

        for (j = 0; j < inLen; j++)
        {
            if (j == i)
                continue;
            else if (j < i)
                newInput[j] = inputStr[j];
            else
                newInput[j - 1] = inputStr[j];
        }
        newInput[j-1] = '\0';

        permutation(newInput, newOutput);
        free(newInput);
        free(newOutput);
    }
    return 0;
}