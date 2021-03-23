/* 
  uso direttiva di compilazione 

  #include <file>

  dove <> indica di cercare il file corrispondente
  nelle directory di sistema per il compilatore C
  normalmente /usr/include
  
 */

#include <stdio.h>

/* funzione (subroutine) che converte un intero in una stringa
   che rappresenta il numero in binario.
   Non spaventarsi, codice non per pivelli, si usa cosi e basta.
 */


/*
  Si usa cosi: dati un intero contenuto nella variabile b
  si costruisce la stringa res (deve essere abbastanza grande
  da contenere il risultato) con la rappresentazione binaria del numero

  int b=10;
  char res[100];
  to_binary( b, res );

  dopo la chiamata
  res = "1010"
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
    str[i] = '0' + (a%2);
    /* str[i] accedo all'i-esimo carattere della stringa str (a partire da 0) */
    a /= 2 ; /* scorciatoia per scrivere a = a / 2 ;
                in generale a OP= b ; ==> a = a OP b  */
    /* si può anche scrivere come a >>= 1 ; == dividere a per 2 */
    ++i;    /* scorciatoia per i = i+1 ; */
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
