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

/*
void
qsort(void *base, size_t nmemb, size_t size,
     int (*compar)(const void *, const void *));
*/

int
compare(const void * pa_in, const void * pb_in) {
  double const * pa = pa_in ;
  double const * pb = pb_in ;
  if ( *pa == *pb ) return 0 ;
  if ( *pa >  *pb ) return 1 ;
  return -1 ;
}

int
main() {
  double vec[100] ; /* definisco un vettore di double di 100 elementi */

  /* riempimento del vettore */
  { /* apro un blocco, posso definire variabili locali al blocco */
	/* le variabili esterne tipo "vec" sono visibili nel blocco  */
	int i=0 ;
    int j=1231242 ;
	while ( i < 100 ) {
	  vec[i] = sqrt( fabs( (double)(j%1234) ) ) ;
      j      = (j*2341) % 234245 ;
      ++i ;
	}
	/* vec contiene numeri non in ordine */
  }
  /* stampa dei numeri */
  {
	int i, j ;
	for ( i=0 ; i < 20 ; ++i ) {
	  for ( j=0 ; j < 5 ; ++j )
		printf("%lf, ",vec[i*5+j]) ;
      printf("\n") ;
	}
  }

  /* ordino i numeri con qsort */
  qsort(vec, 100, sizeof(vec[0]), compare ) ;

  printf("\n\nNumeri Ordinati\n\n") ;
  /* stampa dei numeri */
  {
	int i, j ;
	for ( i=0 ; i < 20 ; ++i ) {
	  for ( j=0 ; j < 5 ; ++j )
		printf("%lf, ",vec[i*5+j]) ;
      printf("\n") ;
	}
  }

  return 0 ; 
}

/*
  per compilarlo uso su macchine UNIX
  > gcc esempio2.c -o esempio2
*/