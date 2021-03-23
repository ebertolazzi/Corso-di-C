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

  ok_e_primo = 0; /* assumo che sia prima */

  /* inizializzo variabile contatore */
  i = 2;

  /*\

    while ( istruzione ) { instruzione; ... ; istruzione }

  \*/

  while ( i < n ) { /* se i < n esegue corpo del loop */

    /* controllo se i divide n */
    if ( (n % i) == 0 ) {
      ok_e_primo = 1; /* non e primo, cambio ok_e_primo di conseguenza */
      break; /* esce, interrompe il ciclo while */
    }

    /* ok, passo al numero successivo */
    i = i + 1;
  }

  printf("Il numero %d %s\n", n, si_no[ok_e_primo]);
  return 0;
  /* return 0 = no error */
}
