/*
 I commenti sono contenuti
 dalla coppia di caratteri / * che indicano l'inizio un commento
 fino ad arrivate alla coppia di caratteri * / che indica
 la fine di un commento
*/

/* struttura di un programma C */

/*
   un programma C consiste di una funzione dal nome "main".
   La funzione restituisce un intero (int).
   Il corpo del programma e' contenuto
   tra parentesi grafe { }.
   Le parentesi tonde () possono contenere
   gli argomenti passati al programma dal sistema operativo
   (non considerato per il momento)
*/

int
main() {
  return 0 ;
  /* ritorna 0 = nessun errore */
}

/*
  per compilarlo da linea di comando

  > gcc esempio1.c -o esempio1     # su macchine unix con compilatore gcc
  > clang esempio1.c -o esempio1   # su OSX o macchine unix con compilatore clang

  in due passi

  # compilo e generero il file esempio1.o (file oggetto codice eseguibile "incompleto")
  > gcc -c esempio1.c

  # link dell codice eseguibile con librerie standard e del sistema operativo
  > gcc esempio1.o -o esempio1

*/
