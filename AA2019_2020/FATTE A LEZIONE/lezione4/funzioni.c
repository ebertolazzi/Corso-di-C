

#include <stdio.h>

// Somma i due numeri a e b
double somma( int a, double b){
    return a + b;
}

//Funzione che incrementa il valore della variabile
void inc(int *a){
    (*a) += 1;
}

//Mette a zero l'indice ind all'interno del vettore vett
void ind_to_zero(int *vett, int ind){
    vett[ind] = 0;
}

int     // Tipo del ritorno della funzione
main    // Nome della funzione
(/* Argomenti */)
{
    int num1 = 5;
    double num2 = 6.4;
    double num3 = somma(num1, num2);
    printf("Somma di %d + %f = %f\n",num1, num2, num3);

    printf("num1: %d\n",num1);
    inc(&num1);
    printf("num1: %d\n",num1);

    int r[] = {1,2,3,4,5};
    printf("elem r[1]: %d\n",r[1]);
    ind_to_zero(r,1);
    printf("elem r[1]: %d\n",r[1]);
    return 0;
}

