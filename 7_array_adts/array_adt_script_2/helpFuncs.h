#include <time.h>
#include "arrayAdt.h"

void funcTime(int (*fp)(struct ArrayInt *arr), struct ArrayInt *localarr, char *funcName)
{
    clock_t start = clock();
    fp(localarr);
    clock_t end = clock();
    printf("\nTime taken to execute %s: %0.3f ms", funcName, (double) 1000 * (end-start)/CLOCKS_PER_SEC);

}