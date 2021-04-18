/*
 * Scrivere una libreria che continene una funzione che prende in ingresso 
 * una stringa, un carattere, e un puntatore a carattere e ritorna un intero
 * La funzione deve cercare all'interno della stringa il carattere indicato ed assegnare 
 * al puntatore (terzo parametro della funzione) l'indirizzo del carattere trovato.
 * La funzione torna zero se il carattere è contenuto nella stringa e 1 se il carattere 
 * non è contenuto nella stringa.
 * Il main dovrà utilizzare la funzione scanf chiedendo di inserire una stringa e successivamente 
 * il carattere da cercare.
 * Ed infine stampare l'indirizzo del carattere trovato e la differenza tra l'indirizzo del vettore
 * e l'indirizzo del carattere (che corrisponde alla posizione del carattere nella stringa).
 */

#include <stdio.h>

// Questa funzione scorre il vettore fino a trovare il carattere corrispondente.
// Per ritornare l'indirizzo del carattere trovato la funzione deve utilizzare un doppio puntatore.
// in quanto il doppio puntatore può essere inizializzato con un indirizzo di una variabile puntatore.
int fun(char s[], char c, char **p){
    int i=0;
    // Inizializzo il contenuto della variabile puntata da p cioè punt
    (*p)=0;
    while(s[i]!='\0'){
        printf("%d",i);
        if(s[i]==c){
            printf("=>SET!\n");
            // In questo modo sto scrivendo dentro la variabile puntata da p che è punt
            // dato che punt è a sua volta una variabile puntatore deve essere assegnata con un
            // indirizzo, in questo caso è l'indirizzo di s[i].
            (*p)=&s[i];
            return 0;
        }
        printf(",");
        i++; 
    }
}

int main(){
    //50 come lunghezza per stare largo, non so a priori la lunghezza della stringa
    char str[50]; 
    char car;
    char *punt;

    printf("Inserisci la stringa: ");   
    // Con questa funzione leggo una stringa (senza spazi) però il carattere '\n' rimane nel buffer e se non prendo
    // le dovute precauzione non sarà possibile leggere il secondo carattere car.
    // scanf("%s",str);  
    // Utilizzando invece questa sintassi leggo fino ad incontrare il carattere accapo '\n' e quindi posso inserire anche
    // le stringhe con spazi. Comunque il carattere accapo rimane nel buffer.
    scanf("%[^\n]",str);  
    // Controllare la documentazione per i dubbi http://www.cplusplus.com/reference/cstdio/scanf/                              
    printf("Inserisci il carattere: ");
    // Mettendo uno spazio all'inizio questo ignora i caratteri spazio accapo e tab come si legge dalla documentazione:
    // Whitespace character: the function will read and ignore any whitespace characters encountered 
    // before the next non-whitespace character (whitespace characters include spaces, newline and tab characters 
    // -- see isspace). A single whitespace in the format string validates any quantity of whitespace characters 
    // extracted from the stream (including none).
    scanf(" %c",&car);                              
    
    fun(str, car, &punt);                           
    
    printf("Indirizzo del vattore: %p\n",str);
    printf("Indirizzo del carattere nel vettore: %p\n",punt);
    // Posso utilizzare l'aritmetica dei puntatore per capire il carattere in che posizione si trova.
    printf("Il carattere trovato è il numero %ld\n",punt-str);
}