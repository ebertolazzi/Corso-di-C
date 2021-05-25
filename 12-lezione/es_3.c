#include <stdio.h>
#include <stdlib.h>
#include "lib_stampa.h"

//trova tutti i divisori di un numero e ritornali in un vettore dinamico
int *divisori(int r, int *const dim)
{
    int *res2 = NULL, *res = malloc(sizeof(int) * 1);
    (*dim) = 0;
    if (res2 != NULL)
    {
        res = res2;
    }
    for (int d = 1; d <= r; ++d)
    {
        if (0 == r % d)
        {
            res[(*dim)] = d;
            (*dim)++;
            res2 = (int *)realloc(res, sizeof(int) * (*dim));
            if (res2 != NULL)
            {
                res = res2;
            }
        }
    }
    return res;
}

int main()
{
    int dim;
    int *res = divisori(15, &dim);
    stampa(res, dim);
    free(res);
    return 0;
}