#include <stdio.h>

// Libreria per usufruire del numero di parametri variabile
#include <stdarg.h>

int fun(
    int a, int b, double c, // Parametri noti della funzione
    ...                     // Notazione che indica il fatto che la funzione può accettare un numero di paramtri variabile
){
    // Varibile che è utilizzata per scorrere i parametri vaviabili
    va_list argomenti;

    // Funzione definisce dove comincia la lista di parametri varibile
    // couble c indica l'ultima variaible nota
    va_start(argomenti, c);

    // Lettura di un parametro variabile è eseguito tramite lafunzione va_arg
    // Ogni volta che chiamo questa funzione leggo un parametro nuovo
    // str è la nostra varibile di ingresso
    // Dovete stare attenti che non c'è nessun controllo sul numero di parametri che dovete leggere
    char *str = va_arg(argomenti, char*);

    // Lettura del char
    char s = va_arg(argomenti, int);

    // Fuzione per resettare la lsita di parametri
    va_end(argomenti);

    printf("La stringa letta è %s\n",str);
    printf("Il carattere letto è %c\n",s);

    return 0;
}

double somma(int num_parametri, ...){
    // Creo la lista di parametri
    va_list argomenti;    
    // Inizilizzo la mia lista
    va_start(argomenti, num_parametri);
    // Inizilizzazione della variabile che contiene il totale
    double tot = 0.0;
    while (num_parametri--){
        // Lettura del parametro e somma al totale
        tot += va_arg(argomenti,double);
    }
    // Azzero la lista
    va_end(argomenti);
    // Ritorno il totale
    return tot;
}

int main(){
    // Chiamata corretta alla funzione con numero variabile di parametri
    // fun(1,2,3.4); Chimata sbagliata
    fun(1,2,3.4,"Gastone", 'C');
    // Esempio
    printf("La somma vale: %f\n", somma(3, 2.1, 3.4, 3.4));
}