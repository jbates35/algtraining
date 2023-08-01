#ifndef POLY_H
#define POLY_H

typedef struct Term {
    struct Term *next;
    int deg;
} Term;

appendTerm(Term **first, int deg);
solvePoly(Term *first, int x);
displayEq(Term *first);
freeTerms(Term *first);

#endif