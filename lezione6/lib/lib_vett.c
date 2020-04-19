#include <stdio.h>
#include <stdlib.h>

void stampa_vettore(const int vett[], int size){
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
    scanf(" %5s",s);
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