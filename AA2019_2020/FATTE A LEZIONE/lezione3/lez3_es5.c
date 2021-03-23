/*
  check numero primo
*/

#include <stdio.h>

/*\
  promemoria scorciatoie C

  i = i+1; ++i oppure i++ DIFFERENZA  a = ++i; i = i+1; a = i;
                                      a = i++; a = i; i = i+1;
  i = i-1; --i oppure i--

  a += b; a = a+b;
  a -= b; a = a-b;
  a *= b; a = a*b;
  a /= b; a = a/b;
  a |= b; a = a | b; etc etc

\*/

/*
// fuzione esterna check numero primo
// 0 se il numero e primo
// 1 se il numerio non e' primo
//
// n = argomento in ingresso passato per valore (sullo stack)
//
*/

static /* la funzione is_prime e;' visibile solo il questo file */
int
is_prime( int n ) {
  int i;
  for ( i = 2; i < n; ++i ) {
    /* controllo se i divide n, se si esco con 1 cioe' non primo */
    if ( (n % i) == 0 ) return 1;
  }
  return 0; /* nessun divisore trovato, e' numerio primo */
}

int
main() {
  int ok_e_primo, n;
  /*\
  si_no = vettore sdi puntatori tipo carattere

   si_no[0] = indirizzo0
   si_no[1] = indirizzo1

   indirizzo0 = indirizzo dell'inizio stringa "e' primo"
   indirizzo1 = indirizzo dell'inizio stringa "non e' primo"
  \*/
  char *si_no[2] = { "e' primo", "non e' primo" };
  printf("Inserisci numero da testare: ");
  scanf( "%d", &n );

  ok_e_primo = is_prime( n );

  printf("Il numero %d %s\n", n, si_no[ok_e_primo]);
  return 0;
  /* return 0 = no error */
}
