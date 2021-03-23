
#include <stdio.h>

// Funzione generica che prende tude argomenti di tipo intero e ritorna un intero
// Dichiarazione
int fun(int a, int b);
// Implementazione o Definizione
int fun(int a, int b){
    return a + b;
}

// Dichiarazione di un puntatore a funzione
// La parentesi (*p_fun) è indispensabile
// https://publications.gbdirect.co.uk/c_book/chapter5/function_pointers.html
int (*p_fun)(int,int);

// Da non confondere con 
// Questa è una funzione che ritorna un puntatore ad intero
//int *p_fun(int,int);

// Dichiarazione di un altro puntatore a funzione
int (*p_fun2)(double,int);
double (*p_fun3)(int,int,int);

// Vettore di puntatori a funzione
int (*p_vett_fun[3])(int,int);

int main(){
    // Assegno il puntatore a funzione
    p_fun = fun;
    // Questa operazione non è ammissibile
    //p_fun2 = fun;
    //p_fun3 = fun;
    printf("%d + %d = %d\n", 4, 5, p_fun(4,5));

    // Puntatore a funzione
    int (*op)(int,int);
    // Assegnamento diretto
    op = fun;
    // Assegnamento con indirizzo
    op = &fun;
    // Chiamate di funzione attraverso il puntatore
    // Chiamata diretta
    int r = op(3,4);
    // Chiamata con dereferenzazione
    int rr = (*op)(3,4);

    // Assegno un elemento del puntatore a funzione
    p_vett_fun[0] = fun;
    // Chiamata di una funzione del puntatore a funzione
    printf("%d + %d = %d\n", 4, 5, p_vett_fun[0](4,5));
}
