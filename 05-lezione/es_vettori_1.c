/*
 * Scrivere una libreria che continene due funzioni 
 * La prima funzione:
 * dato una vettore di interi o double ritorna la somma di tutti i suoi elementi
 * nel caso sia positiva; se la somma è negativa torna sempre -1.
 * La seconda funzione:
 * prende una stringa e conta le ricorrenze di tutte le vocali
 * e ne stampa in numero scrivendo:
 * "Nella stringa "#STRINGA#" ci sono #N A, #N E, #N I, #N O, #N U
 * esempio:
 * Se passo la stringa "Io mi chiamo Gastone" il risultato è
 * "Nella stringa "Io mi chiamo Gastone" ci sono 2 A, 1 E, 3 I, 3 O
 * Se non vi sono vocali di quel tipo semplicemente non stampa quella vocale
 * come nell'esempio.
 * Compilare successivamente la libreria separatamente e utilizzarla all'interno
 * del programma main.
 */

int prima_funzione(int *vett, int dim);

void seconda_funzione(char *vett);