#include <stdio.h>

int main(){
    /* Condizione IF */
    int a = 3, b = 4;

    if( b >= a ){
        /* Condizione VERA */
        printf("b >= a ? SI\n"); 
    }

    if( b == a ) {
        /* Condizione VERA */
        printf("b >= a ? SI\n"); 
    } else {
        /* Condizione FALSA */
        printf("b == a ? NO\n"); 
    }
}