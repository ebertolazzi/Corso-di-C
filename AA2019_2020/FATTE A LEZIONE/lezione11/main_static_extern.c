#include <stdio.h>

#include "static_extern.h"

// Dichiarazione di fun2s
int fun2();

// Posso dichiarare nuovamente le varibili static
int tot = 12;
// Allocazione di res non è possibile
// Perchè è già definito all'interno della libreria
//int res = 13;

// Allocazione di num è possibile 
// e la definizione di num dentro il file di libreria diventa una dichiarazione
int num = 12;

int main(){
    // Questa vale com definizione
    // int num;
    printf("val: %d\n",val);
    printf("num: %d\n",num);
    // Dichiaro una variabile esterna
    extern int res;
    printf("res: %d\n",res);

    // Utilizzo della funzione dichiarata dentro il .h
    printf("fun: %d\n",fun());
    printf("fun2: %d\n",fun3());

    // Dichiaro tot extern
    // Dico al compilatore che tot è definita esternamente
    // Essendo tot varibile static non può essere chiamata dell'esterno
    //extern int tot;
    //printf("tot: %d\n",tot);
    // Posso accedere a tot tramite la funzione fun
    printf("fun: %d\n",fun());

    printf("tot: %d\n",tot);
}

// In questo caso la variabile val è stata considerata come una definizione
// gcc main_static_extern.c

// In questo caso la variabile val dentro il punto .h è stata considerata una dichiarazione
// gcc main_static_extern.c static_extern.c