#include <stdio.h>

//Dato un vettore ritorna la più lunga ricorrenza di un numero consegutivo
int max_ric(int array[], int size)
{
    int max = 0, count = 0;
    int num;
    if (size > 0)
    {
        count = 1;
        max = 1;
        num = array[0];
    }
    else
    {
        return 0;
    }
    for (int i = 1; i < size; i++)
    {
        if (num == array[i])
        {
            count++;
            if (max < count)
            {
                max = count;
            }
        }
        else
        {
            num = array[i];
            count = 1;
        }
    }
    return max;
}


int main()
{
    int a[] = {1,7,1,7,7,3,3,3,3,2};
    printf("%d\n",max_ric(a,10));
}