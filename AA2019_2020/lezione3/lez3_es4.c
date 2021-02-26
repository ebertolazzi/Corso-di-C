/*
  check numero primo
*/

#include <stdio.h>

int
main() {
  int ok_e_primo;
  int i, n;
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

  /*\

    for ( istruzione1; istruzione2; istruzione3 ) {
      instruzione; ... ; istruzione
    }

    equivalente

    istruzione1;
    while ( istruzione2 ) {

      instruzione; ... ; istruzione

      istruzione3; // alla fine del loop
    }

  \*/

  for ( ok_e_primo = 0, i = 2; i < n; i = i+1 ) {
    /* controllo se i divide n */
    if ( (n % i) == 0 ) {
      ok_e_primo = 1; /* non e primo, cambio ok_e_primo di conseguenza */
      break; /* esce, interrompe il ciclo while */
    }
  }

  printf("Il numero %d %s\n", n, si_no[ok_e_primo]);
  return 0;
  /* return 0 = no error */
}
