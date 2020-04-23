/* Libreria input-output */
#include <stdio.h>

/* Libreria math.h per includere fabs */
#include <math.h> 
#define SMALL 0.00000001f

/* Libreia assert */
#include <assert.h>

int main(){

    int a = 1;
    float b = 0.5;
    int c = (int)b;
    double d = 1.1/2.0;
    unsigned int e = 4294966996;
    int f;
    int r;
    int unused __attribute__((unused));

    /* int a; -Wall => In particolare questo -Wuninitialized */
    if(a == 1){
        printf("a == 1\n");
    }

    
    /* int c = b; -Wconversion */
    if( c == (int)0.5 ){
        printf("c == 0.5 no c == 0\n");
    }

    
    if(fabs(d - 0.55) < SMALL /*d == 0.55f -Wfloat-equal*/){
        printf("d == 0.5\n");
    }

    /* unsigned int e = -1; -Wconverion */
    printf("e = %u\n",e);

    if(e == (unsigned int)-300 /*e == -300 -Wextra*/){
        printf("e == 4294966996\n");
    }


    /* -O2 */
    printf("Prima: ");
    r = scanf(" %d,%d",&f,&f);
    printf("(%d)\n",r);

    /* Se non voglio leggere il ritorno */
    printf("Seconda: ");
    if(scanf(" %d,%d",&f,&f)){} /* Ignoro il ritorno */

    /* Utilizzo attribute */
    printf("Terza: ");
    unused = scanf(" %d,%d",&f,&f);

    /* Utilizzo della assert */
    /* Il programma fallisce se non leggo 2 paramentri */
    printf("Quarta: ");
    assert(scanf(" %d,%d",&f,&f) == 2);
    /* Il programma fallisce se non leggo 1 paramentri */
    printf("Quinta: ");
    assert(scanf(" %d",&f) == 1);

    return 0;
}

/*
    Flag di compilazione utili
    https://linux.die.net/man/1/g++
    -Wall: Attiva una lista di warning tipici utili
    -Werror: Trasforma tutti gli warning in errori
    -Wconversion: Controlla che le conversioni di tipo
    -Wfloat-equal: Avverte delle compare tra float o double
    -Wextra: Abilita un altra serie di warning
    -O2: Per ottimizzare il codice
    -std=VERSION VERSION=[c99, c11, c90, c89]: Scelgo la versione di standart c
    -pedantic e -pedantic-errors: Forzo il compilatore a utilizzare la veriosione scelta
*/

/*
    Conversioni implicite
    https://www.geeksforgeeks.org/type-conversion-c/
    Tutti i tipi in funzione delle versioni di C
    https://en.wikipedia.org/wiki/C_data_types
    Comandi alias
    alias gccW="gcc -O2 -Wall -Werror -Wextra -Wconversion -Wfloat-equal -pedantic-errors"
    alias gccW90="gcc -std=c90 -O2 -Wall -Werror -Wextra -Wconversion -Wfloat-equal -pedantic-errors"
*/