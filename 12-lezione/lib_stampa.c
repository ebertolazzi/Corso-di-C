#include <stdio.h>

void stampa(int array[], int size)
{
    printf("[");
    for (int i = 0; i < size; i++)
    {
        printf("%d", array[i]);
        if(i < size - 1){
            printf(",");
        }
    }
    printf("]");
}