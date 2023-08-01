#ifndef POLY_H
#define POLY_H

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

typedef struct Term {
    struct Term *next;
    int deg;
    int coef;
} Term;

void appendTerm(Term **first, int deg, int coef);
double solvePoly(Term *t, double x);
void displayEq(Term *t);
void freeTerms(Term *t);

#endif