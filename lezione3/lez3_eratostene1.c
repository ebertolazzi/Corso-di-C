
/*
  check numero primo
*/

#include <stdio.h>

/* per exit e malloc e free */
#include <stdlib.h>

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

#define N_MAX 1000000000

int
main() {

  int     i, j, count,  N;
  short * is_prime;
  
  /* alloco memoria in byte */
  /* Necessaria per vettori di grande dimenzione */
  is_prime = malloc( (N_MAX+1) * sizeof( short ) );

  printf("Inserisci numero da testare [max]: ");
  scanf( "%d", &N );

  if ( N > N_MAX ) {
    printf( "N = %d deve essere <= di M_MAX = %d\n", N, N_MAX );
    exit(0);
  }

  start();

  /* inizializzo il vettore is_prime = tutti primo */
  for ( i = 0; i <= N; ++i ) is_prime[i] = 1;

  for ( i = 2; i <= N; ++i ) {
    /* se i e marcato come numero primo, i multipli non lo sono */
    if ( is_prime[i] == 0 )  continue; /* salta al prossimo i del loop */
    /* i e un primo, i multiply vanno marcati come non primi */
    for ( j = 2*i; j <= N; j += i ) is_prime[j] = 0;
  }

  /* conto i numeri primi sa 2 a N */
  count = 0;
  for ( i = 2; i <= N; ++i ) {
    if ( is_prime[i] == 1 ) ++count;
  }

  stop();

  printf("Ci sono %d numeri primi tra [2,%d]\n", count, N);
  printf("Tempo di calcolo %g [ms]\n", elapsed());

  free( is_prime );

  return 0;
  /* return 0 = no error */
}

