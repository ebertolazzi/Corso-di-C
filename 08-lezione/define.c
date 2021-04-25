#include <stdio.h>

//Definisco una costante di valore 10
#define A 10

//Definisco una costante uguale ad un altra costante
#define B A

//Funzione con le define
#define FUN(X,Y) X+Y

//Define complessa
#define FOR(X,Y) for(int i=0;i<X;i++){Y}

//Define con simboli
#define ESEGUI(F,A,B) A F B

//define multiriga
#define TEXT \
printf("Questo è un testo\n");\
printf("Ancora del testo\n");

int main(){
    printf("Ecco A: %d\n",B);
    printf("Ecco FUN(X,Y): %d\n",FUN(4,5));
    FOR(10,printf("num:%d\n",i);)
    printf("Risultato: %d\n", ESEGUI(+,4,5));
    TEXT

    // Sbagliato
    // ESEGUI(l,4,5);
}