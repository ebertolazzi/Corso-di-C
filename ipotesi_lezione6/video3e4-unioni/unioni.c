// Libreria di input-output
#include <stdio.h>

union // Parola chiave per creare unione
example // Nome della unione, la unione è un nuovo tipo variabile.
{
    // Qui all'interno ci sono i campi della unione
    float f;
    int i;
    char c;
}uni; // Creazione di variabile di tipo example

int main(){
    // Creo un unione di nome u
    union example u;    
    // Utilizzo il campo float
    u.f = 5.3;
    printf("float: %f\n",u.f);
    printf("integer: %d\n",u.i);
    u.f = 5.2;
    // Cambia anche il valore dell'intero
    printf("float: %f\n",u.f);
    printf("integer: %d\n",u.i);    
    // ora modifico l'intero
    u.i = 3;
    printf("float: %f\n",u.f);
    printf("integer: %d\n",u.i); 
    printf("char: %c\n",u.c);    

    // Posso creare anche puntatore a unione
    union example* uu = &uni;
    uu->c = 'f';
    //https://it.wikipedia.org/wiki/ASCII
    printf("%c\n",uu->c); 
    printf("%d\n",uu->i); 

    // Cosiderazione dei valori ASII dei caratteri
    uu->i = 65; // carattere A
    printf("%c\n",uu->c); 
    printf("%c\n",uu->i); 
    printf("%d\n",uu->i);
}