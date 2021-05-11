/* 
 * Esempio di vettori e puntatori
 *
 * Uso della libreria standard del C per ordinare un vettore
 *
 */

#include <stdio.h>
/* per le funzioni matematiche tipo sqrt */
#include <math.h>

/* per la routine di ordinamento qsort */
#include <stdlib.h>

/* parametrizzo il codice */
typedef float value_type ;

/* definisco una macro */
#define VALUE_TYPE      "%f"
#define CAST_VALUE_TYPE double

/*
void
qsort(void *base, size_t nmemb, size_t size,
     int (*compar)(const void *, const void *));
*/

int
compare(const void * pa_in, const void * pb_in) {
  value_type const * pa = pa_in ;
  value_type const * pb = pb_in ;
  if ( *pa == *pb ) return 0 ;
  if ( *pa >  *pb ) return 1 ;
  return -1 ;
}

void
stampa( value_type vec[], int nelem ) {
  int i, j ;
  for ( i = 0 ; i < nelem ; ) {
	for ( j = 0 ; i < nelem && j < 5 ; ++i, ++j )
	  printf(VALUE_TYPE ", ", (CAST_VALUE_TYPE) vec[i]) ;
    printf("\n") ;
  }
}

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
	  pvec[i] = sqrt( fabs( (value_type)(j%1234) ) ) ;
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