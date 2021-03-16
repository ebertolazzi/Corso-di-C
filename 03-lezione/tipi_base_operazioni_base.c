int main() {
    /* Dichiarazione di una variabile */
    int ciao_mondo; /* Convenzione del come con _ oppure ciaoMondo */ 
    /* Tipo interi */
    int  a = 4, b = 5, c = 5; /* definisco le variabili intere e le inizializzo a, b, c */
    long  int          d, e, f; /* interi "lunghi" */
    short int          g, h; /* interi "corti" */
    unsigned int       i; /* interi senza segno */
    unsigned short int j; /* interi "corti" senza segno */
    /* si possono usare le forme contratte 
    unsigned int       = unsigned
    long int           = long
    short int          = short
    signed int         = int
    unsigned long int  = unsigned long
    unsigned short int = unsigned short
    */

    /* Posso anche andare a capo, il compilatore considera solo il ;*/
    unsigned
    long 
    int k ; /* interi "lunghi" senza segno */

    /* Tipi con virgola */
    float r = 0.5f;       /* numero con virgola piccolo*/
    double g = 0.3;      /* numero con virgola grande */
    long double t = 0.00001; /* numero con virgola grande "lunghi" */    
    
    /* Tipo char */
    char c = 'r'; /* Singolo carattere */

    int  a = 4 /*B00000100*/, b = 5 /*B00000101*/, c = 5; /* definisco le variabili intere a, b, c */

    /* OPERAZIONI ARITMETICHE */
    /* https://publications.gbdirect.co.uk/c_book/chapter2/expressions_and_arithmetic.html */
    a = b + c; /* somma */
    a = b - c; /* differenza */
    a = b * c; /* prodotto */
    a = b / c; /* divisione intera  10/4 ==> 2 */
    a = b % c; /* resto della divisione 20 % 3 ==> 2 
                    infatti 20 = 3*6 + 2 */
    /* Esempio complesso */
    /* Per ovviare ad ogni dubbio sulla priorità degli operatori 
       utilizzare le parentesi 
    */
    a = (b / c) + (c * (-c)); 
    /* ---------------------- */

    /* OPERAZIONI CON ASSEGNAMENTO */
    a *= c; /* equivalente a = a * c; */
    a += c; /* equivalente a = a + c; */
    a -= c; /* equivalente a = a - c; */
    a /= c; /* equivalente a = a / c; */
    a %= c; /* equivalente a = a % c; */
    /* ---------------------- */

    /* OPERAZIONI CONTRATTE + 1 - 1 */
    a++; /* equivalente a = a + 1; */
    a--; /* equivalente a = a - 1; */

    c = 1;
    a = 1;
    c=a++;
    printf("a = 1;\nc = 1;\nc=a++ = (a = %d ,c =%d",a,c);/* c = 1, a = 2 */
    
    c = 1;
    a = 1;
    c=(a++);
    printf("a = 1;\nc = 1;\nc=(a++) = (a = %d ,c =%d",a,c);/* c = 2, a = 2 */

    c = 1;
    a = 1;
    c=++a;  
    printf("a = 1;\nc = 1;\nc=++a = (a = %d ,c =%d",a,c);/* c = 2, a = 2 */
    /* ---------------------- */

    /* OPERAZIONI BINARIE */
    int  a = 4, b = 5, c = 5; 
    /*
    a  B00000100 & (*)
    b  B00000101 =
    --------------
    c  B00000100
    */
    c = a & b;

    /*
    a  B00000100 | (+ senza riporto)
    b  B00000101 =
    --------------
    c  B00000101
    */
    c = a | b;

    /*
    a  B00000100 ^ (1 quando sono diversi)
    b  B00000101 =
    --------------
    c  B00000001
    */
    c = a ^ b;

    /*
    b  B00000101 >> 1 (5/2 = 2)
    --------------
    c  B00000010      (=2)
    */
    c = b>>1; /* equivalente (b/2) */

    /*
    b  B00000101 << 1 (5*2 = 10)
    --------------
    c  B00001010      (=10)
    */
    c = b<<1; /* equivalente (b*2) */
    c <<= 1; /* equivalente (c = c << 1) */

    /*
    b ~B00000101 
    --------------
    c  B11111010
    */
    c = ~b;
    /* ---------------------- */

    /* OPERAZIONI RELAZIONE E CONFRONTO */
    a = 1;  b = 1;
    c = (a == b); /* c = 1 - operazione di confronto = */
    c = (a <= b); /* c = 1 - operazione di confronto minore uguale*/
    c = (a >= b); /* c = 1 - operazione di confronto maggiore uguale*/
    c = (a < b); /*  c = 0 - operazione di confronto minore stretto */
    c = (a > b); /*  c = 0 - operazione di confronto maggiore stretto */
    c = (a != c); /* c = 0 - diverso */
    /* ---------------------- */

    /* OPERAZIONI LOGICHE */
    a = 1; b = 0;
    c = (a && b); /* c = 0 - AND logico*/ 
    c = (a || b); /* c = 1 - OR logico*/
    c = (!a);     /* c = 0 - NOT logico*/

    /* Esempio complesso di utilizzo delle condizioni logiche */
    d = 3;
    e = 12;
    c =(d < e) && (a > b); /*c = 1*/
    c =!(d < e) && (a > b); /*equivalente (d >= e) && (a > b) - c = 0*/
    /* ---------------------- */


  return 0 ; 
}

/*
  per compilarlo uso su macchine UNIX
  > gcc esempio2.c -o esempio2
*/