/* 
  uso direttiva di compilazione 

  #include <file>

  dove <> indica di cercare il file corrispondente
  nelle directory di sistema per il compilatore C
  normalmente /usr/include
  
 */

#include <stdio.h>

int
main() {
  int       a = 112; /* definione e inizializzazione contestuale */
  int       b = 203;
  int const c = 322; /* c non può piu essere modificato */

  /* operazioni sugli interi */
  a = b + c ; /* somma */
  /* print e' definita in stdio.h 
     print( formato, argomenti ) ;
     formato   = "stringa" descrizione di come stampare a terminale gli argomenti
     argomenti =  lista separata da "," di variabili
  */
  printf("Esempio somma tra due numeri\n") ;
  printf("%d = %d + %d\n\n", a, b, c ) ;
  /* 
      ^  ^    ^     ^ ^    ^  ^  ^
      |  |    |     | |    |  |  |
      |  |    |     | |    +--+--+-- argomenti in stampa
      |  |    |     | |
      |  |    |     | +------------ carattere non stampabile (ritorno a capo + avanza linea)
      |  |    |     |
      |  +----+-----+--- %d formattatore = prende argomento e lo stampa come intero
      |
      +------ chiama la funzione printf della libreria standard 
   */

  printf("Esempio differenza tra due numeri\n") ;
  a = b - c ; /* differenza */
  printf("%d = %d - %d\n\n", a, b, c ) ;

  printf("Esempio prodotto tra due numeri\n") ;
  a = b * c ; /* prodotto */
  printf("%d = %d * %d\n\n", a, b, c ) ;

  printf("Esempio divisione tra due numeri\n") ;
  a = b / c ; /* divisione intera  10/4 ==> 2 */
  printf("%d = %d / %d\n\n", a, b, c ) ;

  printf("Esempio resto della divisione tra due numeri\n") ;
  a = b % c ; /* resto della divisione 20 % 3 ==> 2
                 infatti 20 = 3*6 + 2 */
  printf("%d = %d %% %d\n\n", a, b, c ) ;
  /*              ^                                                    */
  /*              |                                                    */
  /*              + per stampare un singolo % devo usare %%            */
  /*                altrimenti diventa metacarattere per formattazione */

  return 0 ; 
}

/*
  per compilarlo uso su macchine UNIX
  > gcc   -Wall esempio3.c -o esempio3
  > clang -Wall esempio3.c -o esempio3
*/
