#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node {
    int val;
    struct Node *next;
};

//Lesson 175
void createNode(struct Node **p, int val);
void freeList(struct Node *p);
void displayList(struct Node *p);

//Lesson 180
int countNodes(struct Node *p);
int sumNodes(struct Node *p);

//Lesson 182
int maxNode(struct Node *p);

//Lesson 184
struct Node *searchNode(struct Node *p, int key);
struct Node *qsearchNode(struct Node **p, int key);

//Lesson 191
int isSortedList(struct Node *p);
void insertNode(struct Node **p, int val, int pos);
void insertNodeS(struct Node **p, int val);

//Lesson 193
int deleteNode(struct Node **p, int pos);

//Lesson 197
void removeDuplicates(struct Node *p);

//Lesson 201
void reverseList(struct Node **p);

//Lesson 204
void sortList(struct Node **p);
void concatLists(struct Node **p, struct Node **q);
struct Node *mergeLists(struct Node **p, struct Node **q);

//Lesson 210
void makeCircular(struct Node *p);
int checkCircular(struct Node *p);
void insertCircular(struct Node **p, int val, int pos);
int deleteCircular(struct Node **p, int pos);
void displayCircular(struct Node *p);
void freeCircular(struct Node *p);
#endif