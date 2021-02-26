#include <stdio.h>
#include <stdlib.h>

int somma(int a, int b){
    return a + b;
}

int sottrazione(int a, int b){
    return a - b;
}

int moltiplicazione(int a, int b){
    return a * b;
}

int divisione(int a, int b){
    return a / b;
}

// Definisco una funzione che prende come primo parametro un puntatore a funzione
int operazione(int (*op)(int,int), int a, int b){
    return op(a,b);
}

// Questa è una funzione che prende un parametro char e ritorna un puntatore a funzione
// di tipo int (*op)(int,int)
int (*ret_operation(char c))(int,int){
    switch (c)
    {
    case '+':
        return somma;
    case '-':
        return sottrazione;
    case '/':
        return divisione;
    case '*':
        return moltiplicazione;
    default:
        exit(1);
    }
}

// Ho dichiarato un puntatore ad una funzione che ritorna un puntatore a funzione
typedef int (*FUN)(int,int);
FUN (*pun_ret_operation)(char);

int main(){
    // Chiamata di una funzione che ritorna una funzione
    printf("%d\n",operazione(ret_operation('+'),5,6));    
    // Chiamata ed assegnamento diretto
    pun_ret_operation = ret_operation;
    printf("%d\n",operazione(pun_ret_operation('+'),5,6));
    // Chiamata ed assegnamento indiretto con puntatore e indirizzo
    pun_ret_operation = &ret_operation;
    printf("%d\n",operazione((*pun_ret_operation)('+'),5,6));
}