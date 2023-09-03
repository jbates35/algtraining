#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>

#include "queue.h"

int main(int argc, char *argv[])
{
    int c;
    opterr = 0;
    char *str;
    char *token;
    const char s[2] = " ";
    int size=20;

    while ((c = getopt(argc, argv, "x:s:")) != -1) {
        switch (c) {
        case 'x':
            str = optarg;
            break;
        case 's':
            size = atoi(optarg);
            break;
        }
    }

    Queue *q;
    initQueue(&q, size);

    token = strtok(str, s);
    while(token != NULL) {
        enqueue(q, atoi(token));
        token = strtok(NULL, s);
    }

    printf("\nDequeuing queue:\n");

    while(!queueIsEmpty(q)) {
        printf("%d\n", dequeue(q));
    }

    freeQueue(&q);
}
