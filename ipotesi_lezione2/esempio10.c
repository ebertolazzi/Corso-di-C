/*
  Programma che calcola i numeri primi
  tra 2 e N (>2) con il metodo del crivello
  di Eratostene.
*/

#include <stdio.h>
#include <stdlib.h>

int /* funzione che non restituisce 0 se tutto ok -1 
       se qualcosa va storto (allocazione dinamica) */
Eratostene( int const N, /* argomento non modificabile
                            numero massimo in cui cercare
                            i numeri primi */
            int *  p_quanti_primi, /* conterrà l'indirizzo dove
                                      copiare il numero totale
                                      di primi calcolati */ 
            int ** pp_primi /* primi conterrà l'indirizzo di un 
                               puntatore il quale a sua volta
                               conterrà l'indirizzo della memoria
                               allocata dinamicamente */
           ) {
  /* variabili da usare nell'algoritmo */
  int i, j ;
  int * e_un_primo ; /* 1 = primo, 0 = non primo */

  /* fase 1: allocazione dinamica del vettore di "booleani"
     per l'algoritmo di Eratostene */
  e_un_primo = malloc( (N+1)*sizeof(int) ) ;
  if ( e_un_primo == NULL ) return -1 ;

  /* fase 2: inizializzazione del vettore e_un_primo */
  for ( i=0 ; i <= N ; ++i ) e_un_primo[i] = 1 ;

  /* fase 3: ricerca dei numeri primi */
  *p_quanti_primi = 1 ; /* 1 e 2 sappiamo gia che sono primi */
  for ( i = 2 ; i <= N ; ++i ) {
    if ( e_un_primo[i] == 1 ) {
	  /* ok, i è un numero primo */
	  ++(*p_quanti_primi) ; /* aggiorno la conta dei primi */
	  /* elimino i suoi multipli
	     dalla tabella di numeri primi */
	  j = i*2 ;
      while ( j <= N ) { e_un_primo[j] = 0 ; j += i ; }
	}
  }

  /* fase 4: allocazione dinamica del vettore in uscita */
  *pp_primi = malloc( (*p_quanti_primi)*sizeof(int) ) ;
  if ( *pp_primi == NULL ) {
	/* allocazione dinamica fallita, rilascio la memoria
	   allocata da e_un_primo */
	free( e_un_primo ) ;
	return -2 ;
  }

  /* fase 5: riempimento del vettore con i numeri primi */
  j = 0 ;
  for ( i = 1 ; i <= N ; ++i ) {
	if ( e_un_primo[i] == 1 )
      (*pp_primi)[j++] = i ; /* j e' incrementato DOPO il suo uso! */
    /* altri modi consentiti ... 
       pp_primi[0][j] = i ; ++j ;
       *(*pp_primi+j) = i ; ++j ;

       pp_primi[0][j++] = i ;
       *(*pp_primi+j++) = i ;

    */
  }

  /* controllo che sia andato tutto bene */
  if ( j != *p_quanti_primi ) return -3 ;

  /* rilascio la memoria ed esco */
  free(e_un_primo) ;
  return 0 ;
}

/* programma principale che richiamerà Eratostene */

int
main() {
  int   n_primi ; /* quanti primi ho calcolato */
  int * p_primi ; /* puntatore alla zona di memoria che 
                     conterrà i numeri primi */
  int   i, N, ok ;

  /* stringone ottenuto con il comando figlet Eratostene */
  printf(
    " _____           _            _                  \n"
    "| ____|_ __ __ _| |_ ___  ___| |_ ___ _ __   ___ \n"
    "|  _| | '__/ _` | __/ _ \\/ __| __/ _ \\ '_ \\ / _ \\\n"
    "| |___| | | (_| | || (_) \\__ \\ ||  __/ | | |  __/\n"
    "|_____|_|  \\__,_|\\__\\___/|___/\\__\\___|_| |_|\\___|\n"
    "\n"
    "programma che calcola i numeri primi da 1 a N\n"
    "Inserisci N=");

  scanf("%d",&N) ;
  ok = Eratostene( N, &n_primi, &p_primi ) ;

  printf("Numeri primi tra 1 e %d\n", N) ;

  for ( i=0 ; i < n_primi ; ++i ) {
	printf("%d ", p_primi[i] ) ;
	if ( (i%10) == 0 ) printf("\n") ;
  }
  printf("\n----------------------\n") ;

  /* fine del programma, rilascio la memoria allocata da Eratostene */
  free( p_primi ) ;
}
