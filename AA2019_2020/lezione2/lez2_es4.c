/*
  usage of the preprocess

  #include <file>

  where <> means that the file must be searched
  of system directories.
  Usually on /usr/include

 */

#include <stdio.h>

/* function (subroutine) that convert an integer to a string
   that represent the number in base 2,
 */


void
to_binary( unsigned a, char str[33] ) {
  int j, i = 0;
  /*
    while ( cond ) expression;
    execute espression until cond become false
  */
  /*
    comparison operator
    == equality
    != not equal
    >= greather or equal than
    <= less or equal than
    > greather than
    < less than
  */

  while ( a != 0 ) {
	  str[i] = '0' + (a%2);
    /* str[i] access i-th character of the string str (starting from 0) */
	  a /= 2; /* shortcut for a = a / 2;
	             in general a OP= b; ==> a = a OP b  */
    /* can be written also as a >>= 1; == divide by 2 */
    ++i;    /* shortcut for i = i+1; */
  }
  if ( i == 0 ) { str[0] = '0'; ++i; }
  str[i] = '\0'; /* set end of string */
  /* reverse the string */
  /* for ( INIT; COND; INCR ) EXPRESSION;
     INIT execute once and the begin of the cycle
     COND tested at every cycle at the beginning, if false exit from loop
     INCR execute at the end of every cycle
     EXPRESSION executed at every cycle
  */
  --i; /* set i to the position of the last character */
  for ( j=0; j < i; --i, ++j ) {
    /* scambio str[i] con str[j] */
  	char bf = str[i];
  	str[i] = str[j];
  	str[j] = bf;
  }
}

int
main() {
  int       a = 112; /* define and initialize */
  int       b = 203;
  int const c = 322; /* c cannot be modified */
  int       d;
  char      str1[33]; /* vector of 33 characters */
  char      str2[33]; /* vector of 33 characters */
  char      str3[33]; /* vector of 33 characters */

  /* integer operations */
  a = b + c; /* addition */
  /* print is defined in stdio.h 
     print( format, arguments );
     format    = "string" describe as to print the arguments
     arguments = list comma "," separated of variables
  */
  printf("test somma: %d = %d + %d\n\n\n", a, b, c );
  /*
       ^  ^    ^     ^ ^   ^  ^  ^
       |  |    |     | |   |  |  |
       |  |    |     | |   +--+--+-- arguments to be printed
       |  |    |     | |
       |  |    |     | +------------ not printable character (carriage return + line feed)
       |  |    |     |
       |  +----+-----+--- %d formatter = print argument as integer
       |
       +------ call function printf from the standard library 
   */
  a = b - c; /* difference */
  printf("test differenza: %d = %d - %d\n\n\n", a, b, c );
  a = b * c; /* product */
  printf("test moltiplicazione %d = %d * %d\n\n\n", a, b, c );
  a = b / c; /* integer division 10/4 ==> 2 */
  printf("test divisione %d = %d / %d\n\n\n", a, b, c );
  a = b % c; /* remainder of the dicision 20 % 3 ==> 2
                in fact 20 = 3*6 + 2 */
  printf("test resto della divisione: %d = %d %% %d\n\n\n", a, b, c );

  /*
   BIT manipulation
  */

  a = b << 1; /* left shift by 1 bit */

  printf("test shift a sinistra: %d = %d<<1\n", a, b);
  to_binary(a, str1);
  to_binary(b, str2);
  printf("test shift a sinistra (%s)_2 = (%s)_2<<1\n\n\n", str1, str2);

  a = b << 5; /* left shift by 5 bit */
  printf("test shift a sinistra: %d = %d<<5\n", a, b);
  to_binary(a, str1);
  to_binary(b, str2);
  printf("test shift a sinistra (%s)_2 = (%s)_2<<5\n\n\n", str1, str2);


  a = b >> 1; /* shift a destra di 1 bit */
  printf("shift a destra: %d = %d>>1\n", a, b);
  to_binary(a, str1);
  to_binary(b, str2);
  printf("shift a destra: (%s)_2 = (%s)_2>>1\n\n\n", str1, str2);

  a = b >> 5; /* shift a destra di 5 bit */
  printf("shift a destra: %d = %d>>5\n", a, b);
  to_binary(a, str1);
  to_binary(b, str2);
  printf("shift a destra: (%s)_2 = (%s)_2>>5\n\n\n", str1, str2);

  /* operazioni maschere bit a bit
    & operazione 'and' bit a bit
    | operazione 'or' bit a bit
    ^ operazione 'or esclusivo' bit a bit
    ~ operazione 'complementazione' bit a bit
  */

  a = b & c; /* and bit a bit */
  to_binary(a, str1);
  to_binary(b, str2);
  to_binary(c, str3);
  printf("%s = %s & %s\n", str1, str2, str3);

  a = b | c; /* or bit a bit */
  to_binary(a, str1);
  to_binary(b, str2);
  to_binary(c, str3);
  printf("%s = %s | %s\n", str1, str2, str3);

  a = b ^ c; /* or esclusivo bit a bit */
  to_binary(a, str1);
  to_binary(b, str2);
  to_binary(c, str3);
  printf("%s = %s ^ %s\n", str1, str2, str3);

  a = ~b; /* complemento bit a bit */
  to_binary(a, str1);
  to_binary(b, str2);
  printf("%s = ~%s\n", str1, str2);

  d = b & 0xFF; /* controllo se i primi 8 bit sono assegnati */
  to_binary(0xFF, str1);
  to_binary(b,    str2);
  printf("%d = %s & %s\n", d, str1, str2);

  d = (b<<8) & 0xFF; /* controllo se i primi 8 bit sono assegnati */
  to_binary(0xFF, str1);
  to_binary((b<<8), str2);
  printf("%d = %s & %s\n", d, str1, str2);

  return 0; 
}

/*
  to compile on a UNIX os.
  > gcc example3.c -o example3
*/