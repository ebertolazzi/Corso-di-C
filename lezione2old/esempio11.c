/*
  Programma che calcola i numeri primi
  tra 2 e N (>2) con il metodo del crivello
  di Eratostene.

  versione 2.

*/

#include <stdio.h>
#include <stdlib.h>

/* routine per la manipolazione di un vettore di bit */

typedef struct {
  int      nbit ;
  int      vec_len, bit_per_unsigned ;
  unsigned * vec ;
} vettore_bit ;

int /* 0 = ok, -1 allocazione dinamica fallita */
costruisci( vettore_bit * vb, int const nbit ) {
  int vec_len, bit_per_unsigned ;
  vb -> nbit = nbit ; /* (*vb) . nbit = nbit ; */
  /* calcolo quanti "unsigned" mi servono per contenere "nbit" bit */
  vb -> bit_per_unsigned = sizeof(unsigned) * 8 ;
  vb -> vec_len = (nbit + vb -> bit_per_unsigned - 1) / vb -> bit_per_unsigned ;
            /* ^---- trucco per allocare i byte necessari */
  /* allocazione dinamica del vettore */
  vb -> vec = malloc( vb -> vec_len * sizeof(unsigned) ) ;
  if ( vb -> vec == NULL ) return -1 ;
  return 0 ;
}

void
distruggi( vettore_bit * vb ) {
  if ( vb -> vec != NULL ) free( vb -> vec ) ;
  vb -> vec  = NULL ;
  vb -> nbit = 0 ;
}

void
inizializza( vettore_bit * vb ) {
  int i ;
  /* riempie il vettore di bit con il valore 0 */
  for ( i = 0 ; i < vb -> vec_len ; ++i )
	vb -> vec[i] = 0 ;  printf("esci inizializza\n") ;
}

int /* 0 = ok, -1 bit fuori range */
imposta_bit( vettore_bit * vb, int const nbit ) {
  int i, ne, nb ;
  
  if ( nbit > vb -> nbit || nbit < 0 ) return -1 ;

  /* cerco in quale elemento del vettore vec il bit appartiene */
  ne = nbit / vb -> bit_per_unsigned ;
  /* cerco all'interno dell'elemento il bit di appartenenza */
  nb = nbit % vb -> bit_per_unsigned ;

  vb -> vec[ne] |= 1<<nb ;
}

int /* 0, 1 = valore letto, -1 bit fuori range */
leggi_bit( vettore_bit * vb, int const nbit ) {
  int i, ne, nb ;
  
  if ( nbit > vb -> nbit || nbit < 0 ) return -1 ;

  /* cerco in quale elemento del vettore vec il bit appartiene */
  ne = nbit / vb -> bit_per_unsigned ;
  /* cerco all'interno dell'elemento il bit di appartenenza */
  nb = nbit % vb -> bit_per_unsigned ;

  if ( vb -> vec[ne] & 1<<nb ) return 1 ;
  else                         return 0 ;
}

int
Eratostene( int const N,
            int *  p_quanti_primi,
            int ** pp_primi) {
  /* variabili da usare nell'algoritmo */
  int         i, j ;
  vettore_bit e_un_primo ; /* 1 = primo, 0 = non primo */

  if ( costruisci( &e_un_primo, N+1) == -1 ) return -1 ; 

  /* fase 2: inizializzazione del vettore e_un_primo */
  inizializza( &e_un_primo ) ;

  /* fase 3: ricerca dei numeri primi */
  *p_quanti_primi = 1 ; /* 1 e 2 sappiamo gia che sono primi */
  for ( i = 2 ; i <= N ; ++i ) {
	switch ( leggi_bit( &e_un_primo, i ) ) {
    case 0: /* è un primo */
	  ++(*p_quanti_primi) ; /* aggiorno la conta dei primi */
	  /* elimino i suoi multipli dalla tabella di numeri primi */
	  j = i*2 ;
      while ( j <= N ) { imposta_bit( &e_un_primo, j) ; j += i ; }
      break ;
    case 1: /* non è un primo */
      break ;
    case -1: /* errore */
     return -1 ;
	}
  }

  /* fase 4: allocazione dinamica del vettore in uscita */
  *pp_primi = malloc( (*p_quanti_primi)*sizeof(int) ) ;
  if ( *pp_primi == NULL ) {
	/* allocazione dinamica fallita, rilascio la memoria
	   allocata da e_un_primo */
	distruggi( &e_un_primo ) ;
	return -2 ;
  }

  /* fase 5: riempimento del vettore con i numeri primi */
  j = 0 ;
  for ( i = 1 ; i <= N ; ++i ) {
	switch ( leggi_bit( &e_un_primo, i ) ) {
    case 0: /* è un primo */
      (*pp_primi)[j++] = i ; /* j è incrementato DOPO il suo uso! */
      break ;
    case 1: /* non è un primo */
      break ;
    case -1: /* errore */
     return -1 ;
	}
  }

  /* controllo che sia andato tutto bene */
  if ( j != *p_quanti_primi ) return -3 ;

  /* rilascio la memoria ed esco */
  distruggi(&e_un_primo) ;
  return 0 ;
}

/* programma principale che richiamerà Eratostene */

int
main() {
  int   n_primi ; /* quanti primi ho calcolato */
  int * p_primi ; /* puntatore alla zona di memoria che 
                     conterrà i numeri primi */
  int   i, N, ok ;

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
