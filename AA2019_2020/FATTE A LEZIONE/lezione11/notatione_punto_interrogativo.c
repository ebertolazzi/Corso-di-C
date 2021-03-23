#include <stdio.h>

int main(){
    int a = 5;
    // Assegnare una variabile in funzione del valore di un altra varibile
    // int g;
    // if(a == 5){
    //     g = 3;
    // }else{
    //     g = 6;
    // }
    // Potete utilizzare la notazione punto interrogativo
    int g = a < 5 ? 3 : 6;
    // VARIBILE = CONDIZIONE ? VERO : FALSO
    printf("contenuto di g: %d\n",g);
}