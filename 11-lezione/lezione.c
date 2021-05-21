#define DIM 5
#include <stdio.h>
#include "lib.h" 


int main(){
    g = 5;
    //rr = 5;

    int c;
    //fun(&c);
    fun2(&c);

    const int r = 3;
    //fun(&r);
    //fun2(&r);


    const int *a = &c;
    int const *b = &c;
    b = &r;
    //(*a) = 5;

    int *const d = &c;
    //d = &r;
    (*d) = 10;

    const int *const p = &c;
}