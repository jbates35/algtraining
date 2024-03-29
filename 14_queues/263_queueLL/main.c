#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>

#include "queueLL.h"

int main(int argc, char *argv[])
{
    int c;
    opterr = 0;
    char *str;
    char *token;
    const char s[2] = " ";
    int size=5;

    while ((c = getopt(argc, argv, "x:")) != -1) {
        switch (c) {
        case 'x':
            str = optarg;
            break;
        }
    }

    Node *q = NULL;

    int cnt = 0;
    token = strtok(str, s);
    while(token != NULL) {
        enqueue(&q, atoi(token));
        cnt++;
        if(cnt == 4) {
            cnt = 0;
            printf("\nUnloading queue (size==4):\n");
            while(!queueIsEmpty(q))
                printf("%d\n", dequeue(&q));
        }
        token = strtok(NULL, s);
    }

    printf("\nUnloading remaining values in queue:\n");
    while(!queueIsEmpty(q))
        printf("%d\n", dequeue(&q));
}
