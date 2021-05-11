#include<stdio.h>

int main ()
{
  int c;
  int   ch;
  puts ("Enter text. Include a dot ('.') in a sentence to exit:");
  fflush(stdout); 
  do {
    // Funzione per prendere un carattere da tastiera
    // https://www.cplusplus.com/reference/cstdio/getchar/
    c = getchar();
    // Funzione di stampa più semplice che printf
    puts ("Stampa: ");
    // Con questa istruzione pulisco il buffer di input
    //while ((ch = getchar()) != '\n' && ch != EOF);
    // Funzione di stampa più semplice che printf
    putchar (c);
    puts ("\n");
    // Funzione per ripulire il buffer di stampa
    fflush(stdout);
  } while (c != '.');
  return 0;
}