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
void reverse(DoublyLL *p);

int main(int argc, char *argv[])
{
    DoublyLL *p;
    initList(&p);

    int option = -1;

    void (*fp[5])(DoublyLL *p) = {
        &create,
        &display,
        &insert,
        &delete,
        &reverse};

    while (true)
    {
        printf("\nPlease select options:\n\n");
        printf("\t(1) Create list\n");
        printf("\t(2) Display list\n");
        printf("\t(3) Insert single node\n");
        printf("\t(4) Delete single node\n");
        printf("\t(5) Reverse list\n");
        printf("\t(0) Quit\n\n");
        printf("Enter option: ");

        scanf("%d", &option);

        if(option < 0 || option  > 6)
            printf("\nOption must be between 0 and 6\n");
        else if(option==0)
            break;
        else
            fp[option -1](p);
    }

    freeList(p);
}

void create(DoublyLL *p)
{
    char vals[100];
    printf("Enter values for entries separated by space. I.e. '1 3 1 6'\n");
    
    int c; 
    while ((c = getchar() != '\n') && c != EOF);
    
    fgets(vals, sizeof(vals), stdin);
    char *token;
    const char s[2] = " ";

    token = strtok(vals, s);
    while(token != NULL)
    {
        appendNode(p, atoi(token));
        token = strtok(NULL, s);
    }

    printf("\nEntries added!\nYour list is:\n");
    displayList(p);
    printf("\n");
}

void display(DoublyLL *p)
{
    printf("\nYour list is:\n");
    displayList(p);
    printf("\n");
}

void insert(DoublyLL *p)
{
    int val = 0, pos = 0;

    printf("\nEnter the value you want to insert\n");
    scanf("%d", &val);
    printf("\nEnter the position you want to insert it at\n");
    scanf("%d", &pos);

    insertNode(p, val, pos);

    printf("\nEntry added\n");

}

void delete(DoublyLL *p)
{
    int pos = 0;

    printf("\nEnter the position you want to delete\n");
    scanf("%d", &pos);

    int retVal = deleteNode(p, pos);
    printf("\nEntry deleted.\nThe popped entry was %d\n", retVal);
}

void reverse(DoublyLL *p)
{
    printf("\nReversing list\n");
    reverseList(p);
    printf("Displaying list:\n");
    displayList(p);
}
