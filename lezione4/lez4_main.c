//
//  Autore: Gastone Pietro Rosati Papini
//  Corso:  ....
//  Lezione: ....
//

// Libreria standard C per input output 
#include <stdio.h>

// Step 1
int main1() {
  //Messaggio di apertura programma
  printf("Inizio Progamma");

  //Alloco il carattere per leggere da terminale
  char c;

  //Leggo i numeri fino a che non leggo il carattere 'f'
  while(c != 'f'){
    printf("\nScrivi un carattere: ");
    c = getchar();                    //Qui si accorgono che il sistema ricorda un secondo carattere che è l'invio
    // scanf("%c",&c);                //Posso fare anche così ginorando gli spazi
    // scanf(" %c",&c);               //Soluzione 1
    // c = getchar(); getchar();      //Soluzione 2 
    printf("Il carattere è: %c",c);
  }

  //Messaggio di chiusara programma
  printf("\nProgamma Terminato\n");
}

//Include per atoi
#include <stdlib.h>

// Step 2
int main2() {
  //Messaggio di apertura programma
  printf("Inizio Progamma");

  //Alloco il carattere per leggere da terminale
  char c;
  //Alloco un intero di appoggio
  int n;

  //Leggo i numeri fino a che non leggo il carattere 'f'
  while(c != 'f'){
    printf("\nScrivi un carattere: ");
    scanf(" %c",&c);
    //Converto il carattere in numero
    n = atoi(&c);
    printf("Il numero è: %d",n);
  }

  //Messaggio di chiusara programma
  printf("\nProgamma Terminato\n");
}

// Step 3
int main3() {
  //Messaggio di apertura programma
  printf("Inizio Progamma");

  //Alloco il carattere per leggere da terminale
  char c;
  //Alloco un intero di appoggio
  int n;
  //Creaiamo un vettore
  int vett[10];
  //indice del vettore
  int i = 0; 
  //variabile per la stampa
  int j;

  //Leggo i numeri fino a che non leggo il carattere 'f' oppure non finisco il vettore
  while(c != 'f' && i < 10){
    printf("\nScrivi un numero: ");
    //Leggo un carattere
    scanf(" %c",&c);
    //Converto il carattere in numero
    n = atoi(&c);
    //Inserisco il numero nel vettore
    vett[i++] = n;
    printf("Il vettore è composto da\n[");
    //Stampo il vettore
    for(j = 0 ; j < i-1 ; j++){
      printf("%d,",vett[j]);
    }
    printf("%d]",vett[j]);
  }

  //Messaggio di chiusara programma
  printf("\nProgamma Terminato\n");
}

//Funzione di stampa del vettore
//Qui posso usare const
void stampa_vett(const int vett[], int size){
  printf("Il vettore è composto da\n[");
  int j;
  for(j = 0 ; j < size-1 ; j++){
    printf("%d,",vett[j]);
  }
  printf("%d]\n",vett[j]);
}

//Leggi un numero
//Qui parlo dei parametri passati per riferimento
//i deve essere passata per riferimento
//Ritorno 1 se il programma legge 'f'
int inserisci_numero(int *vett, int *i){
  //Alloco il carattere per leggere da terminale
  char c[5];
  //Alloco un intero di appoggio
  int n;
  
  //Leggo un carattere
  printf("Scrivi un numero: ");
  scanf(" %s",c);
  
  //Se ho letto 'f' finisco
  if(c[0] == 'f'){
    return 1;
  }
  
  //Converto il carattere in numero
  n = atoi(c);
  //n = strtol(c,NULL,10);
  //Inserisco il numero nel vettore
  //NOTA qui sto modificando il valore di i che mi è stato passato
  vett[(*i)++] = n;
  
  return 0;
}

// Step 4
int main4() {
  //Messaggio di apertura programma
  printf("Inizio Progamma\n");
  //Fine programma 
  int fine = 0;

  //Creaiamo un vettore
  int vett[10];
  //indice del vettore
  int i = 0; 

  //Leggo i numeri fino a che non leggo il carattere 'f' oppure non finisco il vettore
  while(fine == 0 && i < 10){
    //Inserico il numero dentro il vettore
    fine = inserisci_numero(vett,&i);
    //Stampo il vettore
    stampa_vett(vett,i);
  }

  //Messaggio di chiusara programma
  printf("Progamma Terminato\n");
}

//Algoritmo di ordinamento bubble sort
//https://www.geeksforgeeks.org/bubble-sort/
void bubble_sort(int vett[], int size){
  //Variabili necessarie
  int i,j,temp;
  //ordino gli elementi		
  printf("Ordino il vettore con il bubble sort\n");
  
  //Primo ciclo
  for(j = 0 ; j < size-1 ; j++){
    //Secondo ciclo
    for(i = 0 ; i < size-1 ; i++){
      //Controllo se i numeri adiacenti possono sono nell'ordine sbagliato
      if( vett[i] > vett[i+1] ){
        //Scambio i numeri
        temp = vett[i];
        vett[i] = vett[i+1];
        vett[i+1] = temp;
      }
      //stampa_vett(vett,size);
    }
  }
}

// Step 5
int main5() {
  //Messaggio di apertura programma
  printf("Inizio Progamma\n");
  //Fine programma 
  int fine = 0;

  //Creaiamo un vettore
  int vett[10];
  //indice del vettore
  int i = 0; 

  //Leggo i numeri fino a che non leggo il carattere 'f' oppure non finisco il vettore
  while(fine == 0 && i < 10){
    //Inserico il numero dentro il vettore
    fine = inserisci_numero(vett,&i);
    //Stampo il vettore
    stampa_vett(vett,i);
  }

  //Ordino il vettore
  bubble_sort(vett,i);
  //Stampo il vettore ordinato
  stampa_vett(vett,i);

  //Messaggio di chiusara programma
  printf("Progamma Terminato\n");
}

//Algoritmo di ordinamento insertion sort
//https://www.geeksforgeeks.org/insertion-sort/
void insertion_sort(int vett[], int size){
  //Variabili necessarie
  int i,j,temp;
  //ordino gli elementi		
  printf("Ordino il vettore con il insertion sort\n");
  //Parto dal secondo elemento fino all'ultimo
  for( i = 1 ; i < size ; i++){ 
    //Mi salvo l'elemento in una variabile d'appoggio
    temp = vett[i]; 
    //Controllo tutti gli elementi prima dell'elemento selezionato
    //Fin che incontro numeri più grandi li sposto in avanti
    //Se finisco il vettore o se trovo un numero più piccolo mi fermo
    j = i-1; 
    while( j >= 0 && vett[j] > temp){
		  vett[j+1]=vett[j];		
		  j--;		
	  }
    //Posiziono il numero selezionato dopo il numero più piccolo trovato
	  vett[j+1]=temp;
	}
}

void scelgo_algoritmo(int *vett, int size){
  //Carattere da leggere
  char c;
  //Ciclo fin che non prendo il carattere giusto
  int fine = 0;
  do{
    printf("Scegli l'algoritmo: [b,i]\n");
    printf("b - per bubble sort\n");
    printf("i - per insertion sort\n");
    //Leggo un carattere
    scanf(" %c",&c);

    switch (c)
    {
      case 'b':
        //Ordino il vettore
        bubble_sort(vett,size);
        fine = 1;
        break;

      case 'i':
        //Ordino il vettore
        insertion_sort(vett,size);    
        fine = 1;  
        break;
    
      default:
        printf("Carattere sbagliato!\n");
        break;
    }
  }while(fine == 0);
}

#define N 10

// Step 5
int main() {
  //Messaggio di apertura programma
  printf("Inizio Progamma\n");
  //Fine programma 
  int fine = 0;

  //Creaiamo un vettore
  int vett[N];
  //indice del vettore
  int i = 0; 

  //Leggo i numeri fino a che non leggo il carattere 'f' oppure non finisco il vettore
  while(fine == 0 && i < N){
    //Inserico il numero dentro il vettore
    fine = inserisci_numero(vett,&i);
    //Stampo il vettore
    stampa_vett(vett,i);
  }

  //Scelgo algoritmo
  scelgo_algoritmo(vett,i);
  //Stampo il vettore ordinato
  stampa_vett(vett,i);

  //Messaggio di chiusara programma
  printf("Progamma Terminato\n");
}

/*
  to compile on a UNIX os.
  > gcc lez3_main.c -o myProgram
*/
