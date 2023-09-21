#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>

#include "queueCircular.h"
#include "arrayAdt.h"

int main(int argc, char *argv[])
{
    int c;
    opterr = 0;
    char *str;
    char *token;
    const char s[2] = " ";
    int size=100;

    while ((c = getopt(argc, argv, "x:")) != -1) {
        switch (c) {
        case 'x':
            str = optarg;
            break;
        }
    }

    ArrayInt arr;
    int initarr[1] = {-1};
    initADT(&arr, initarr, 10, 0);
    
    token = strtok(str, s);
    while(token != NULL) {
        appendADT(&arr, atoi(token));
        token = strtok(NULL, s);
    }

    Queue *q;
    initQueue(&q, size);

    displayADT(&arr);

    freeQueue(&q);
    freeADT(&arr);
}
