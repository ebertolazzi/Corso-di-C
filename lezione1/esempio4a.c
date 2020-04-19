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
   Solo prototipo, prometto al compilatore che
   la funzione é da qualche altrsa parte
 */

void to_binary( int aa, char str[33] );

int
main() {
  int       a = 112 ; /* definione e inizializzazione contestuale */
  int       b = 203 ;
  int const c = 322 ; /* c non può piu essere modificato */
  int       d ;
  char      str1[33] ; /* vettore di 33 caaratteri */
  char      str2[33] ; /* vettore di 33 caaratteri */
  char      str3[33] ; /* vettore di 33 caaratteri */
  /*

   Manipolazione di BIT!

  */

  printf("Esempio shift a sinistra di 1 bit (equivale a x2 in binario)\n") ;
  a = b << 1 ; /* shift a sinistra di 1 bit */
  
  printf("%d = %d<<1\n", a, b) ;
  to_binary(a, str1) ;
  to_binary(b, str2) ;
  printf("stessa cosa in base 2, notazione (n)_2 numero in base 2\n") ;
  printf("(%s)_2 = (%s)_2<<1\n\n", str1, str2) ;

  printf("Esempio shift a sinistra di 5 bit (equivale a x32 in binario)\n") ;
  a = b << 5 ; /* shift a sinistra di 5 bit */
  printf("%d = %d<<5\n", a, b) ;
  to_binary(a, str1) ;
  to_binary(b, str2) ;
  printf("stessa cosa in base 2, notazione (n)_2 numero in base 2\n") ;
  printf("(%s)_2 <-- (%s)_2<<5\n\n", str1, str2) ;

  printf("Esempio shift a destra di 1 bit (equivale a /2 in binario)\n") ;
  a = b >> 1 ; /* shift a destra di 1 bit */
  printf("%d <-- %d>>1\n", a, b) ;
  to_binary(a, str1) ;
  to_binary(b, str2) ;
  printf("stessa cosa in base 2, notazione (n)_2 numero in base 2\n") ;
  printf("(%s)_2 <-- (%s)_2>>1\n\n", str1, str2) ;

  printf("Esempio shift a sinistra di 5 bit (equivale a /32 in binario)\n") ;
  a = b >> 5 ; /* shift a destra di 5 bit */
  printf("%d <-- %d>>5\n", a, b) ;
  to_binary(a, str1) ;
  to_binary(b, str2) ;
  printf("stessa cosa in base 2, notazione (n)_2 numero in base 2\n") ;
  printf("(%s)_2 <-- (%s)_2>>5\n\n", str1, str2) ;

  /* operazioni maschere bit a bit
    & operazione 'and' bit a bit
    | operazione 'or' bit a bit
    ^ operazione 'or esclusivo' bit a bit
    ~ operazione 'complementazione' bit a bit
  */

  printf("Esempio bit AND\n") ;
  a = b & c ; /* and bit a bit */
  to_binary(a, str1) ;
  to_binary(b, str2) ;
  to_binary(c, str3) ;
  printf("(%s)_2 <-- (%s)_2 & (%s)_2\n\n", str1, str2, str3);

  printf("Esempio bit OR\n") ;
  a = b | c ; /* or bit a bit */
  to_binary(a, str1) ;
  to_binary(b, str2) ;
  to_binary(c, str3) ;
  printf("(%s)_2 <-- (%s)_2 | (%s)_2\n\n", str1, str2, str3);

  printf("Esempio bit XOR\n") ;
  a = b ^ c ; /* or esclusivo bit a bit */
  to_binary(a, str1) ;
  to_binary(b, str2) ;
  to_binary(c, str3) ;
  printf("(%s)_2 <-- (%s)_2 ^ (%s)_2\n\n", str1, str2, str3);

  printf("Esempio bit NEGAZIONE o COMPLEMENTO\n") ;
  a = ~b ; /* complemento bit a bit */
  to_binary(a, str1) ;
  to_binary(b, str2) ;
  printf("(%s)_2 <-- ~(%s)_2\n\n", str1, str2) ;
  printf("Attenzione i bit a 0 a sinistra non vengono stampati\n");
  printf("ma dopo il complemento sono a 1, ce ne sono tanti quanto\n");
  printf("la dimensione in bit dell'intero usato.\n\n\n");

  /*
   0x  = prefisso per numeri in esadecimale
   0   = prefisso per numeri in ottale
   0b  = prefisso per numeri in binario

   ad esempio

   0b110101 = 0x35        = 065
   binario    esadecimale   ottale
   */

  printf("Esempio maschere di bit\n") ;
  d = b & 0xFF ; /* controllo se i primi 8 bit sono assegnati */
  to_binary(0b11111111, str1) ;
  to_binary(b,    str2) ;
  to_binary(d,    str3) ;
  printf("(%s)_2 <-- (%s)_2 & (%s)_2\n\n", str3, str2, str1) ;

  printf("Esempio maschere di bit + shift\n") ;
  b = 1234;
  d = (b<<4) & 0b11111111; /* controllo se i primi 8 bit sono assegnati */
  to_binary(0xFF, str2) ;
  to_binary(b, str1) ;
  to_binary(d, str3) ;
  printf("(%s)_2 <-- ((%s)_2 << 4) & (%s)_2\n\n", str3, str1, str2) ;

  return 0 ; 
}

/*
  per compilarlo uso su macchine UNIX
  > gcc   -Wall esempio4a.c esempio4b.c -o esempio3
  > clang -Wall esempio4a.c esempio4b.c -o esempio3
*/
