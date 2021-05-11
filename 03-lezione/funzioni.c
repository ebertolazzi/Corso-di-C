
#include <stdio.h>

int /* ritorno di funzione tutti i tipi che conosciamo */
fun_a /* Nome di funzione, deve cominciare con un carattere A-Z a-z */
(
    int a,
    /* parametri di funzione divisi dalla virgola */
    int b
)
{   /* Corpo della funzione */
    return 0;  /* ritorno di funzione */
}

int somma ( int a, int b ) {   
    return a + b;
}

double somma_double ( double a, double b ) {   
    return a + b;
}

void stampa ( double a ) {   
    printf("%f\n", a); 
    return;
}

int main(){
    int c = somma(2,4);
    /* int c = stampa(4); SBAGLIATO perché è una funzione void*/

    printf("2 + 4 = %d\n", somma(2,4)); 
    printf("2 + 4 = %d\n", c);
    printf("2.3 + 4.3 = %f\n", somma_double(2.3,4.3)); 
    stampa(3.4);

    return 0;
}
