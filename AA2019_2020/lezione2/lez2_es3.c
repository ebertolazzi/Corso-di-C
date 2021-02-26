/* 
 */

#include <stdio.h>

int
main() {

  char        a;
  int         b;
  short       c;
  long        d;
  long long   e;
  float       f;
  double      g;
  long double h;

  printf("Print memory requirement for standard types\n");
  printf("sizeof(char)        = %lu\n", sizeof(char));
  printf("sizeof(int)         = %lu\n", sizeof(int));
  printf("sizeof(short)       = %lu\n", sizeof(short));
  printf("sizeof(long)        = %lu\n", sizeof(long));
  printf("sizeof(long long)   = %lu\n", sizeof(long long));
  printf("sizeof(float)       = %lu\n", sizeof(float));
  printf("sizeof(double)      = %lu\n", sizeof(double));
  printf("sizeof(long double) = %lu\n", sizeof(long double));

  printf("sizeof(a) = %lu\n", sizeof(a));
  printf("sizeof(b) = %lu\n", sizeof(b));
  printf("sizeof(c) = %lu\n", sizeof(c));
  printf("sizeof(d) = %lu\n", sizeof(d));
  printf("sizeof(e) = %lu\n", sizeof(e));
  printf("sizeof(f) = %lu\n", sizeof(f));
  printf("sizeof(g) = %lu\n", sizeof(g));
  printf("sizeof(h) = %lu\n", sizeof(h));

  return 0; 
}

/*
  to compile on a UNIX os.
  > gcc example4.c -o example4
*/
