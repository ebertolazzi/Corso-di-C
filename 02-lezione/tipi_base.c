int
main() {
  int                a, b, c ; /* definisco le variabili intere a, b, c */
  long  int          d, e, f ; /* interi "lunghi" */
  short int          g, h    ; /* interi "corti" */
  unsigned int       i ; /* interi senza segno */
  unsigned short int j ; /* interi "corti" senza segno */
  
  unsigned
  long 
  int k ; /* interi "lunghi" senza segno */

  float r = 0.5f;       /* numero con virgola piccolo*/
  double g = 0.3;      /* numero con virgola grande */
  long double t = 0.00001; /* numero con virgola grande "lunghi" */

  char c = 'r'; /* Singolo carattere */

  /* si possono usare le forme contratte 
   unsigned int       = unsigned
   long int           = long
   short int          = short
   signed int         = int
   unsigned long int  = unsigned long
   unsigned short int = unsigned short
  */

  /* operazioni sugli interi */
  a = b + c ; /* somma */
  a = b - c ; /* differenza */
  a = b * c ; /* prodotto */
  a = b / c ; /* divisione intera  10/4 ==> 2 */
  a = b % c ; /* resto della divisione 20 % 3 ==> 2 
                 infatti 20 = 3*6 + 2 */
  return 0 ; 
}

/*
  per compilarlo uso su macchine UNIX
  > gcc esempio2.c -o esempio2
*/