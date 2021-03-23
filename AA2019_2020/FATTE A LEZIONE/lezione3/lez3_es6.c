/*
  check numero primo
*/

#include <stdio.h>

/* accedo a funzioni di distema gettimeofday */
#include <sys/time.h>

struct timeval tbegin, tend;


static void start() { gettimeofday(&tbegin, NULL); }
static void stop()  { gettimeofday(&tend, NULL); }

static
double
elapsed() {
  double elapsedTime;
  elapsedTime  = (tend.tv_sec - tbegin.tv_sec) * 1000.0;      // sec to ms
  elapsedTime += (tend.tv_usec - tbegin.tv_usec) / 1000.0;   // us to ms
  return elapsedTime;
}

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
  int ok_e_primo, i, n, count;
  printf("Inserisci numero da testare [max]: ");
  scanf( "%d", &n );

  count = 0;

  start();
  for ( i = 2; i <= n; ++i ) {
    ok_e_primo = is_prime( i );
    if ( ok_e_primo == 0 ) ++count;
  }
  stop();
  
  printf("Ci sono %d numeri primi tra [2,%d]\n", count, n);
  printf("Tempo di calcolo %g [ms]\n", elapsed());
  return 0;
  /* return 0 = no error */
}
