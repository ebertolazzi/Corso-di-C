/* 
 * Esempio di vettori e puntatori
 *
 * Uso della libreria standard del C per ordinare un vettore
 *
 */

#include "esempio9a.h"

int
compare(const void * pa_in, const void * pb_in) {
  struct rational const * pa = pa_in ;
  struct rational const * pb = pb_in ;
  /* pa -> denom == (*pa) . denom */
  int numer = pa -> numer * pb -> denom - pa -> denom * pb -> numer ;
  int denom = pa -> denom * pb -> denom ;
  if ( denom > 0 ) {
	if ( numer > 0 ) return 1 ;	
	if ( numer < 0 ) return -1 ;
  } else {
	if ( numer < 0 ) return 1 ;	
	if ( numer > 0 ) return -1 ;
  }
  return 0 ;
}

void
stampa( struct rational vec[], int nelem ) {
  int i, j ;
  for ( i = 0 ; i < nelem ; ) {
	for ( j = 0 ; i < nelem && j < 3 ; ++i, ++j ) {
	  int   p      = vec[i] . numer ;
	  int   q      = vec[i] . denom ;
      float p_su_q = (float)p/(float)q ;
	  printf("(%d/%d)=%f, ", p, q, p_su_q ) ;
	}
    printf("\n") ;
  }
}
