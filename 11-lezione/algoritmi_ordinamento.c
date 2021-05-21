
// Input output
#include <stdio.h>
//Include atoi
#include <stdlib.h>

void stampa_vettore(int vett[], int size){
    //Indice per il for
    int j;
    //Controllo vettore vuoto
    if(size == 0){
        printf("Il vettore è vuoto\n");
        return;
    }
    //Stampare il contenuto di vett
    printf("Il vettore è composto da:\n[");
    for(j = 0 ; j < size - 1 ; j++){
        printf("%d,",vett[j]);
    }
    printf("%d]\n",vett[j]);
}

int inserisci_elemento(int *vett, int *ind){
    //Stringa 
    char s[5];
    //Intero letto
    int n;
    
    printf("Inserisci un numero:");
    //c = getchar(); getchar(); 
    // Leggo una stringa
    scanf(" %s",s);
    printf("Strina letta: %s\n",s);
    
    //Controllo per verifare se ho letto 'f'
    if( s[0] == 'f' ){
        return 1;
    }

    //Conversione della stringa s in intero
    //https://en.cppreference.com/w/cpp/string/byte/atoi
    n = atoi(s);
    //Inserisco l'elemento dentro al vettore
    vett[(*ind)++] = n;

    return 0;
}

//Algoritmo di ordinamento bubble sort
//https://www.geeksforgeeks.org/bubble-sort/
void bubble_sort(int vett[], int size){
    printf("Ordino il vettore utilizzando la funzione bubble sort.\n");
    //Variabili indice
    int i,j,temp;
    //Primo ciclo mi serve per eseguire size cicli
    for(i = size-1 ; i >= 0 ; i--){
        //Ciclo per lo scambio di elementi
        for(j = 0 ; j < i ; j++){
            //Scambio dell'elemento se l'elemento di sinistra è più grande dell'elemento di destra
            if(vett[j] > vett[j+1]){
                temp = vett[j];
                vett[j] = vett[j+1];
                vett[j+1] = temp;
            }
        }
    }
}

//Algoritmo di ordinamento insertion sort
//https://www.geeksforgeeks.org/insertion-sort/
void insertion_sort(int vett[], int size){
    printf("Ordino il vettore utilizzando la funzione insertion sort.\n");
    //Variabili indice
    int i,j,temp;
    //Primo ciclo mi serve per eseguire size cilci
    for(i = 1 ; i < size ; i++){
        temp = vett[i];
        //Serve per spostare più a sinistra l'elemento considerato
        //Fino a che non incotro un elemento che ha un valore più piccolo
        for(j = i-1 ; j >= 0 && vett[j] > temp; j--){
            vett[j+1] = vett[j];
        }
        vett[j+1] = temp;
    }
}

void selection_sort(int vett[], int size){
    /* CODICE */
}

void scelgo_algoritmo(int vett[], int size){
    //Carattere da leggere
    char c;
    //Variabile di ciclo
    int fine = 0;
    do{
        printf("Scegli l'algoritmo: [b,i]\n");
        printf("b - per bubble sort\n");
        printf("i - per insertion sort\n");
        printf("s - per selection sort\n");

        //Leggo un char
        scanf(" %c", &c);

        switch (c)
        {
            case 'b':
                bubble_sort(vett, size);
                fine = 1;
                break;

            case 'i':
                insertion_sort(vett, size);
                fine = 1;
                break;

            default:
                printf("Carattere errato.\n");
                break;
        }
    }while(fine == 0);
}

int main(){
    printf("Inizio Programma\n");
    //Vettore di interi
    int vett[10];
    //Indice del vettore
    int ind = 0; 
    //Fine programma
    int fine = 0;

    //Controllo valore indice e se non ho letto 'f'
    while( fine == 0 && ind < 10){
        //Inserisci elemento dentro al vettore
        fine = inserisci_elemento(vett, &ind);
        //Stampa vettorels
        stampa_vettore(vett, ind);
    }
    //Scelgo algoritmo di ordinamento
    scelgo_algoritmo(vett, ind);
    //Stampa vettore
    stampa_vettore(vett, ind);

    printf("Fine Programma\n");
}