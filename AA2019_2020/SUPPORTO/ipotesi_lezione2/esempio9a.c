/* 
 * Esempio di vettori e puntatori
 *
 * Uso della libreria standard del C per ordinare un vettore
 *
 */

/*
  nell'include usando le "" cerco il file nella directory
  corrente o nelle directory specificate dal flag -I del compilatore

  gcc -I/usr/pippo/pluto -I./libs .....

*/

#include "esempio9a.h"

int
main() {
  value_type * pvec ; /* definisco un puntatore al vettore */
                      /* per convenzione uso "p" davanti a una variabile puntatore
                         non fa parte dello standard ANSI ma delle buone abitudini
                         di programmazione */

  int nelem = 123 ; /* definisco il numero di elementi */

  /* allocazione dinamica della memoria */
  pvec = malloc( nelem * sizeof(value_type) ) ;
  printf("puntatore %lX\n",(long) pvec) ;

  if ( pvec == NULL ) {
    /* allocazione dinamica fallita */	
	printf("allocazione dinamica fallita per pvec\n") ;
	exit(1) ; /* uscita pulita dal programma */ 	
  }

  /* riempimento del vettore */
  { /* apro un blocco, posso definire variabili locali al blocco */
	/* le variabili esterne tipo "vec" sono visibili nel blocco  */
	int i=0 ;
    int j=1231242 ;
	while ( i < nelem ) {
	  pvec[i] . numer = j%1234 ;
	  pvec[i] . denom = (j+3)%234 ;
      j      = (j*2341) % 234245 ;
      ++i ;
	}
	/* vec contiene numeri non in ordine */
  }
  /* stampa dei numeri */
  stampa( pvec, nelem ) ;

  /* ordino i numeri con qsort */
  qsort(pvec, nelem, sizeof(pvec[0]), compare ) ;

  printf("\n\nNumeri Ordinati\n\n") ;
  /* stampa dei numeri */
  stampa( pvec, nelem ) ;

  /* rilascio della memoria allocata */
  free(pvec) ;

  return 0 ; 
}

/*
  per compilarlo uso su macchine UNIX
  > gcc esempio6.c -o esempio6
*/