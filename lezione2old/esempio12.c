/*
  Programnma che risolve con differenze finite
  il problema

  y'' + a(x) y' + b(x) y = c(x)
  y(A) = ya
  y(B) = yb
*/

#include <stdlib.h>
#include <stdio.h>

/*
  prototipo della routine LAPACK
  che risolve un sistema tridiagonale
*/

#define F77NAME(A) A##_
typedef int    integer ;
typedef double double_precision ;

/* F77NAME(dgtsv)  ==> dgtsv_ */

void F77NAME(dgtsv) ( integer const    * N,
                      integer const    * NRHS,
                      double_precision * DL,
                      double_precision * D,
                      double_precision * DU,
                      double_precision * B,
                      integer const    * LDB,
                      integer          * INFO );

/* definizione del problema */

double_precision
a( double_precision x )
{ return 1 ; } 

double_precision
b( double_precision x )
{ return -1 ; } 

double_precision
c( double_precision x )
{ return x*x ; } 

/*
  funzione che costruisce il sistema tridiagonale
  e lo risolve con la chiamata alla routione LaPack
 */

int
bvp_solver( double_precision A, /* estremo sinistro */
            double_precision B, /* estremo destro */ 
            double_precision YA, /* BC estremo sinistro */
            double_precision YB, /* BC estremo destro */ 
            integer          N, /* numero di intervalli */
            double_precision **pp_y /* doppio puntatore alla soluzione */
          ) {
  integer i, ONE=1, INFO ;
  double_precision xi, h, *D, *DU, *DL, *RHS ;
  /* fase 1: allocazione dinamica */	
  RHS = *pp_y = malloc( (N+1)* sizeof(double_precision) ) ;
  if ( *pp_y == NULL ) /* controllato */ ;
  D  = malloc( (3*N+1)* sizeof(double_precision) ) ;
  if ( D == NULL ) /* controllato */ ;
  DL = D  + N+1 ;
  DU = DL + N ;

  /* ciclo per riempire i vettori */
  D[0] = 1 ; DU[0]   = 0 ; RHS[0] = YA ;
  D[N] = 1 ; DL[N-1] = 0 ; RHS[N] = YB ;
  h = (B-A)/N ;
  for ( i=1 ; i < N ; ++i ) {
	xi      = A + i*h ;
	D[i]    = -2 + h*h *b(xi) ;
	DL[i-1] = 1-h*a(xi)/2 ;
    DU[i]   = 1+h*a(xi)/2 ;
	RHS[i]  = h*h*c(xi) ;
  }
  /* chiamata della routine lapack */
  F77NAME(dgtsv) ( &N, &ONE, DL, D, DU, RHS, &N, &INFO ) ;
  return INFO ;
}

int
main( int argc, char * argv[] ) {
  FILE * fd ;	
  double_precision * p_y ;
  integer            i, N, ok ;	
  /* mi aspetto una chiamata del tipo 
     program N file
     N = numero di intervalli
     file = nome del file dove salvare il risultato 
  */
  printf("%d\n",argc);
  if ( argc != 3 ) {
	printf("comando errato\n");
	exit(1) ;
  }

  sscanf( argv[1], "%d", &N ) ;

  ok = bvp_solver( 0, 10, 1, 1, N, &p_y );

  if ( ok == 0 ) {
	fd = fopen( argv[2], "w+" ) ;
	for ( i = 0 ; i <= N ; ++i ) {
	  fprintf( fd, "%lf\n", p_y[i]) ;	
	}
  }
}
