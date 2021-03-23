// Libreria di input-output
#include <stdio.h>

// Link alle unioni
// https://publications.gbdirect.co.uk/c_book/chapter6/unions.html

union       // Parola chiave per creare un unione
example     // nome del tipo unione, è un nuovo tipo di variabile 
{
    // Qui sono presenti i campi all'interno della nostra unione
    float f;
    int i;
    char c;
}uni; // Creo una variabile di tipo unione di nome uni

struct           
example_struct     
{
    float f;
    int i;
    char c;
}uni_struct;

int main(){
    // Creato un elemento di ttipo example di nome u
    union example u;

    // Utilizzare il campo float
    u.f = 5.3f;
    printf("float: %f\n",u.f);
    printf("integer: %d\n", u.i); 

    // Modifico il campo float e questo provaca la modifica anche degli altri campi
    u.f = 6.4f;
    printf("float: %f\n",u.f);
    printf("integer: %d\n", u.i); 

    //Accedo e modifico il campo come fosse un intero
    u.i = 2;
    printf("float: %f\n",u.f);
    printf("integer: %d\n", u.i); 
    printf("char: %c\n", u.c); 

    // Dimensione della mia union
    printf("dimensione union: %lu\n", sizeof(uni)); 
    // Dimensione della mia struttura
    printf("dimensione struct: %lu\n", sizeof(uni_struct)); 

    // Definizione di un puntatore a unione
    union example *uu = &uni;
    // Verifica dei valori della union
    printf("float: %f\n",uu->f);
    printf("integer: %d\n", uu->i); 
    printf("char: %c\n", uu->c); 

    uu->c = 'f';
    //https://it.wikipedia.org/wiki/ASCII
    printf("integer: %d\n", uu->i); 
    printf("char: %c\n", uu->c);     

    uu->i = 65; // Carattere A
    printf("integer: %d\n", uu->i); 
    printf("char: %c\n", uu->i); 
    printf("char: %c\n", uu->c);    
}