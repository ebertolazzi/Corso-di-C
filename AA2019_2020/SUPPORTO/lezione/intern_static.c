#include <stdio.h>

int fun(){
    // Allocazione di una variabile static interna ad una funzione
    static int count = 0;
    printf("static count: %d\n",++count);
}
// Le variabili static dichiarate interne ad una funzione sono utili
// quando vogliamo trasferire dell'informaizione tra una chiamata di funzione e l'altra
// mantenendo però la visibilità locale

int main(){
    fun();
    fun();
    fun();
    fun();
    fun();
}