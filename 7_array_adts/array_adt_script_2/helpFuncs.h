#include <time.h>
#include "arrayAdt.h"

void funcTime(int (*fp)(struct ArrayInt *arr), struct ArrayInt *localArr, char *funcName)
{
    clock_t start = clock();
    fp(localArr);
    clock_t end = clock();
    printf("\nTime taken to execute %s: %0.3f ms", funcName, (double) 1000 * (end-start)/CLOCKS_PER_SEC);
}

void funcShow(int (*fp)(struct ArrayInt *arr), struct ArrayInt *localArr, char *funcStr)
{
    printf("\n%s", funcStr);
    fp(localArr);
}