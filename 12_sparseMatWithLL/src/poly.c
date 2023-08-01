#include "poly.h"

double fpow(double x, int deg);

void appendTerm(Term **first, int deg, int coef)
{
    Term *new = (Term *)malloc(sizeof(Term));
    new->deg = deg;
    new->coef = coef;
    new->next = NULL;

    if (*first == NULL)
    {
        *first = new;
        return;
    }

    Term *t = *first;
    Term *s = NULL;
    while (t)
    {
        if (deg == t->deg)
        {
            fflush(stdout);
            fprintf(stderr, "Error: Term of degree %d already added", deg);
            return;
        }
        s = t;
        t = t->next;
    }
    s->next = new;
}

double solvePoly(Term *t, double x)
{
    double rtnVal = 0.0;
    while (t)
    {
        rtnVal += t->coef * fpow(x, t->deg);
        t = t->next;
    }
    return rtnVal;
}

void displayEq(Term *t)
{
    printf("\n");
    while (t)
    {
        if(t->deg == 0)
            printf("%d", t->coef);
        else if(t->deg == 1)    
            printf("%dx", t->coef);
        else
            printf("%dx^%d", t->coef, t->deg);

        if (t->next)
            printf(" + ");

        t = t->next;
    }
    printf("\n");
}

void freeTerms(Term *t)
{
    Term *s = NULL;
    while (t)
    {
        s = t;
        t = t->next;
        free(s);
    }
}

double fpow(double x, int deg)
{
    double rtnVal = 1.0;
    while (deg)
    {
        rtnVal *= x;
        deg--;
    }
    return rtnVal;
}