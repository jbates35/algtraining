#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

#include "dlinkedlist.h"

void create(DoublyLL *p);
void display(DoublyLL *p);
void insert(DoublyLL *p);
void delete(DoublyLL *p);
void peek(DoublyLL *p);
void reverse(DoublyLL *p);

int main(int argc, char *argv[])
{
    DoublyLL *p;
    initList(&p);

    int option = -1;

    void (*fp[6])(DoublyLL *p) = {
        &create,
        &display,
        &insert,
        &delete,
        &peek,
        &reverse};

    // while (true)
    // {
    //     printf("\nPlease select options:\n\n");
    //     printf("\t(1) Create list\n");
    //     printf("\t(2) Display list\n");
    //     printf("\t(3) Insert single node\n");
    //     printf("\t(4) Delete single node\n");
    //     printf("\t(5) Peek a node\n");
    //     printf("\t(6) Reverse list\n");
    //     printf("\t(0) Quit\n\n");
    //     printf("Enter option: ");

    //     scanf("%d", &option);

    //     if(option < 0 || option  > 6)
    //         printf("\nOption must be between 0 and 6\n");
    //     else if(option==0)
    //         break;
    //     else
    //         fp[option -1](p);
    // }

    appendNode(p, 1);
    appendNode(p, 3);
    appendNode(p, 5);
    appendNode(p, 3);
    appendNode(p, 9);
    displayList(p);

    freeList(p);
}

void create(DoublyLL *p)
{

}

void display(DoublyLL *p)
{

}

void insert(DoublyLL *p)
{

}

void delete(DoublyLL *p)
{

}

void peek(DoublyLL *p)
{

}

void reverse(DoublyLL *p)
{

}
