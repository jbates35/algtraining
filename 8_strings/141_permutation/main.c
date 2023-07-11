#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <time.h>
#include <stdbool.h>

int processCount;

int permutation(const char* inputStr, char *outputStr);

int main(int argc, char *argv[])
{
    int c;
    opterr = 0;
    char* str;

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

int permutation(const char* inputStr, char *outputStr)
{
    //Get length of string
    int inputLength;
    for(inputLength = 0; inputStr[inputLength] != '\0'; inputLength++);
    
    int outputLength;
    for(outputLength = 0; outputStr[outputLength] != '\0'; outputLength++);
      
    if(inputLength==0)
    {
        // printf("\n%s", outputStr);
        return 1;
    }

    for(int i = 0; i < inputLength; i++)
    {
        char pop = inputStr[i];
        char* newOutput = malloc(outputLength + 2);

        int j;
        for(j = 0; j < outputLength; j++)
        {
            newOutput[j] = outputStr[j];
        }
        newOutput[j++] = pop;
        newOutput[j] = '\0';

        printf("%s\n",newOutput);

        char* newInput = malloc(inputLength-1);
        for(int j = 0; j < inputLength; j++)
        {
            if(j==i)
                continue;

            if(j<i)
                newInput[j] = inputStr[j];
            else
                newInput[j-1] = inputStr[j];          
        }

        // permutation(newInput, newOutput);
        free(newInput);
        // free(newOutput);
    }
}
