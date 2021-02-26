/*\
 |
 |  lezione 2 esempio 2
 |
\*/

#include <stdio.h>

int
main() {
  int                a, b, c; /* define integer variables a, b, c */
  long  int          d, e, f; /* "big" integer */
  short int          g, h;    /* "small" integer */
  unsigned int       i;       /* integer without sign */
  unsigned short int j;       /* "small" integer without sign */

  unsigned
  long
  int k; /* "big" integer with out sign, notice that C is free form */

  /*
   you can use the shortcuts
   unsigned int       = unsigned
   long int           = long
   short int          = short
   signed int         = int
   unsigned long int  = unsigned long
   unsigned short int = unsigned short
  */
 
  b = 32;
  c = 23;

  /* integer operations */
  a = b + c; /* addition */
  printf("b=%d,c=%d,b+c=%d\n",b,c,a);
  a = b - c; /* difference */
  printf("b=%d,c=%d,b-c=%d\n",b,c,a);
  a = b * c; /* product */
  printf("b=%d,c=%d,b*c=%d\n",b,c,a);
  a = b / c; /* integer division 10/4 ==> 2 */
  printf("b=%d,c=%d,b/c=%d\n",b,c,a);
  a = b % c; /* remainder of the division 20 % 3 ==> 2
                in fact 20 = 3*6 + 2 */
  printf("b=%d,c=%d,b%%c=%d\n",b,c,a);
  return 0; 
}

/*\
  to compile on a UNIX os.
  > gcc example2.c -o example2
\*/