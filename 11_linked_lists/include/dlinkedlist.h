#ifndef D_LINKED_LIST
#define D_LINKED_LIST

#include <stdio.h>
#include <stdlib.h>

struct DNode {
    struct DNode *prev;
    int val;
    struct DNode *next;
};

struct DoublyLL {
    struct DNode *first;
    struct DNode *last;
    int length;
};

typedef struct DNode DNode;
typedef struct DoublyLL DoublyLL;

void initList(DoublyLL **list);
void freeList(DoublyLL *list);
void appendNode(DoublyLL *list, int val);
void insertNode(DoublyLL *list, int val, int pos);
int deleteNode(DoublyLL *list, int pos);
void displayList(DoublyLL *list);
void reverseList(DoublyLL *list);
#endif