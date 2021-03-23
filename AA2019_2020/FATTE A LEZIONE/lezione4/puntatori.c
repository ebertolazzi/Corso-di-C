
#include <stdio.h>

int main(){
    int num = 10;
    int num2 = 20;
    //Con * indico una variabile puntatore
    //Con & accedo all'indirizzo di una variabile
    int *p = &num;

    char r[]="Hello";
    char *p2 = r;

    printf("Contenuto di num: %d\n", num);
    printf("Indirizzo di num: %p\n", &num);
    printf("Contenuto di p: %p\n", p);
    printf("Indirizzo di p: %p\n", &p);

    printf("Contenuto dell'indirizzo p: %d\n", *p); 
    //Modifica del contenuto attraverso il puntatore
    (*p) = 11;
    printf("Contenuto di num: %d\n", num);
    //Modifica del puntatore 
    p = &num2;
    printf("Contenuto dell'indirizzo p: %d\n", *p); 

    printf("Contenuto di r: %s\n", r);
    printf("Contenuto di r[0]: %c\n", r[0]);
    printf("Indirizzo di r: %p\n", &r);
    //L'indirizzo di r[0] è uguale all'indirizzo di r perché punta al pirmo elemento del vettore
    printf("Indirizzo di r[0]: %p\n", &r[0]);

    //Contenuto di p2 che è l'indirizzo di r
    printf("Contenuto di p2: %p\n", p2);
    //Modifica di una stringa attraverso puntatore
    p2[0] = 'h';
    printf("Contenuto di r: %s\n", r);
}