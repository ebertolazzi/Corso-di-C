/* 
 */

#include <stdio.h>

int
main() {

  char        a ;
  int         b ;
  short       c ;
  long        d ;
  long long   e ;
  float       f ;
  double      g ;
  long double h ;
  
  printf("Stampa della occupazione in memoria dei tipi standard\n") ;
  printf("sizeof(char)        = %d\n", sizeof(char)) ;
  printf("sizeof(int)         = %d\n", sizeof(int)) ;
  printf("sizeof(short)       = %d\n", sizeof(short)) ;
  printf("sizeof(long)        = %d\n", sizeof(long)) ;
  printf("sizeof(long long)   = %d\n", sizeof(long long)) ;
  printf("sizeof(float)       = %d\n", sizeof(float)) ;
  printf("sizeof(double)      = %d\n", sizeof(double)) ;
  printf("sizeof(long double) = %d\n", sizeof(long double)) ;

  printf("sizeof(a) = %d\n", sizeof(a)) ;
  printf("sizeof(b) = %d\n", sizeof(b)) ;
  printf("sizeof(c) = %d\n", sizeof(c)) ;
  printf("sizeof(d) = %d\n", sizeof(d)) ;
  printf("sizeof(e) = %d\n", sizeof(e)) ;
  printf("sizeof(f) = %d\n", sizeof(f)) ;
  printf("sizeof(g) = %d\n", sizeof(g)) ;
  printf("sizeof(h) = %d\n", sizeof(h)) ;

  return 0 ; 
}

/*
  per compilarlo uso su macchine UNIX
  > gcc esempio2.c -o esempio2
*/