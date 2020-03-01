/* 
  uso direttiva di compilazione 

  #include <file>

  dove <> indica di cercare il file corrispondente
  nelle directory di sistema per il compilatore C
  normalmente /usr/include
  
 */

#include <stdio.h>

/* funzione (subroutine) che converte un intero in una stringa
   che rappresenta il numero in binario,
 */

void
to_binary( int aa, char str[33] ) {
  int j, i = 0 ;
  unsigned a = (unsigned) aa ;
  /*
    while ( cond ) expression ;
    esegue espression finché cond e' vera
  */
  /* 
    operatori di confronto
    == uguaglianza
    != diverso
    >= maggiore o uguale
    <= minore o uguale
    > maggiore
    < minore
  */
 
  while ( a != 0 ) { 
	str[i] = '0' + (a%2) ;
  /* str[i] accedo all'i-esimo carattere della stringa str (a partire da 0) */
	a /= 2 ; /* scorciatoia per scrivere a = a / 2 ;
	            in generale a OP= b ; ==> a = a OP b  */
	/* si può anche scrivere come a >>= 1 ; == dividere a per 2 */
	++i ;    /* scorciatoia per i = i+1 ; */
  }
  if ( i == 0 ) { str[0] = '0' ; ++i ; }
  str[i] = '\0' ; /* marco il fine stringa */
  /* devo rovesciare la stringa */
  /* for ( INIT ; COND ; INCR ) expression ;
     INIT e' eseguita una volta sola a inizio ciclo
     COND viene testata ogni ciclo all'inizio, se falsa esce dal ciclo for
     INCR viene eseguita alla fine di ogni ciclo
     expression viene eseguita ad ogni ciclo
  */
  --i ; /* per non scambiare lo 0 marcatore di fine stringa */
  for ( j=0 ; j < i ; --i, ++j ) {
    /* scambio str[i] con str[j] */
	char bf = str[i] ;
	str[i] = str[j] ;
	str[j] = bf ;
  }
}

int
main() {
  int       a = 112 ; /* definione e inizializzazione contestuale */
  int       b = 203 ;
  int const c = 322 ; /* c non può piu essere modificato */
  int       d ;
  char      str1[33] ; /* vettore di 33 caaratteri */
  char      str2[33] ; /* vettore di 33 caaratteri */
  char      str3[33] ; /* vettore di 33 caaratteri */

  /* operazioni sugli interi */
  a = b + c ; /* somma */
  /* print e' definita in stdio.h 
     print( formato, argomenti ) ;
     formato   = "stringa" descrizione di come stampare a terminale gli argomenti
     argomenti =  lista separata da "," di variabili
  */
  printf("%d = %d + %d\n", a, b, c ) ;
  /* 
      ^  ^    ^     ^ ^   ^  ^  ^
      |  |    |     | |   |  |  |
      |  |    |     | |   +--+--+-- argomenti in stampa 
      |  |    |     | |
      |  |    |     | +------------ carattere non stampabile (ritorno a capo + avanza linea)
      |  |    |     |
      |  +----+-----+--- %d formattatore = prende argomento e lo stampa come intero
      |
      +------ chiama la funzione printf della libreria standard 
   */
  a = b - c ; /* differenza */
  printf("%d = %d - %d\n", a, b, c ) ;
  a = b * c ; /* prodotto */
  printf("%d = %d * %d\n", a, b, c ) ;
  a = b / c ; /* divisione intera  10/4 ==> 2 */
  printf("%d = %d / %d\n", a, b, c ) ;
  a = b % c ; /* resto della divisione 20 % 3 ==> 2 
                 infatti 20 = 3*6 + 2 */
  printf("%d = %d %% %d\n", a, b, c ) ;

  /*
   Manipolazione di BIT!

  */

  a = b << 1 ; /* shift a sinistra di 1 bit */
  
  printf("%d = %d<<1\n", a, b) ;
  to_binary(a, str1) ;
  to_binary(b, str2) ;
  printf("%s = %s<<1\n", str1, str2) ;

  a = b << 5 ; /* shift a sinistra di 5 bit */
  printf("%d = %d<<5\n", a, b) ;
  to_binary(a, str1) ;
  to_binary(b, str2) ;
  printf("%s = %s<<5\n", str1, str2) ;


  a = b >> 1 ; /* shift a destra di 1 bit */
  printf("%d = %d>>1\n", a, b) ;
  to_binary(a, str1) ;
  to_binary(b, str2) ;
  printf("%s = %s>>1\n", str1, str2) ;

  a = b >> 5 ; /* shift a destra di 5 bit */
  printf("%d = %d>>5\n", a, b) ;
  to_binary(a, str1) ;
  to_binary(b, str2) ;
  printf("%s = %s>>5\n", str1, str2) ;

  /* operazioni maschere bit a bit
    & operazione 'and' bit a bit
    | operazione 'or' bit a bit
    ^ operazione 'or esclusivo' bit a bit
    ~ operazione 'complementazione' bit a bit
  */

  a = b & c ; /* and bit a bit */
  to_binary(a, str1) ;
  to_binary(b, str2) ;
  to_binary(c, str3) ;
  printf("%s = %s & %s\n", str1, str2, str3) ;

  a = b | c ; /* or bit a bit */
  to_binary(a, str1) ;
  to_binary(b, str2) ;
  to_binary(c, str3) ;
  printf("%s = %s | %s\n", str1, str2, str3) ;

  a = b ^ c ; /* or esclusivo bit a bit */
  to_binary(a, str1) ;
  to_binary(b, str2) ;
  to_binary(c, str3) ;
  printf("%s = %s ^ %s\n", str1, str2, str3) ;

  a = ~b ; /* complemento bit a bit */
  to_binary(a, str1) ;
  to_binary(b, str2) ;
  printf("%s = ~%s\n", str1, str2) ;

  d = b & 0xFF ; /* controllo se i primi 8 bit sono assegnati */
  to_binary(0xFF, str1) ;
  to_binary(b,    str2) ;
  printf("%d = %s & %s\n", d, str1, str2) ;

  d = (b<<8) & 0xFF ; /* controllo se i primi 8 bit sono assegnati */
  to_binary(0xFF, str1) ;
  to_binary((b<<8), str2) ;
  printf("%d = %s & %s\n", d, str1, str2) ;

  return 0 ; 
}

/*
  per compilarlo uso su macchine UNIX
  > gcc esempio2.c -o esempio2
*/