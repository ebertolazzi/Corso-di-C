//Libreria di input-output
#include <stdio.h>

//Libreria per includere la funzione exit
#include <stdlib.h>

//Libreria che abbiamo realizzato con le funzioni fatte nella lezione precedente
#include "lib_vett.h"

//Macro che definisce la dimensione del vettore
#define SIZE 10

FILE *apri_file(char *name, char *mod){
    //Puntatore al file
    FILE *file;
    //Apro di nuovo il file
    file = fopen(
        name, // File da aprire
        mod           // Modalita di apertura 
                      // r read         - lettura
                      // w writing      - scrittura
                      // a append       - aggiungo alla fine del file
                      // r+ read+write  - leggo e scrivo solo se esiste
                      // w+ read+write  - se non esiste viene creato
                      // a+ read+write  - se non esiste viene creato ed aggiungo alla fine del file
    );
    //Controllo se l'apertura del file è andata a buon fine
    if(file == NULL) {
        printf("Errore!");   
        exit(1);
    }

    return file;
}

void nuovo_polinomio(int vett[], int *size){
    //Variabile di ciclo
    int fine = 0;
    
    //Resetto polinomio attuale
    *size = 0;

    //Controllo valore indice e se non ho letto 'f'
    while( fine == 0 && *size < SIZE ){
        //Inserisci elemento dentro al vettore
        fine = inserisci_elemento(vett, size);
        //Stampa vettorels
        stampa_vettore(vett, *size);
    }
}

void carica_polinomio(int vett[], int *size){
    // Nome del file da cui carico il polinomio
    char s[10];

    // File di caricamento del polinomio
    FILE *file;

    // Variablile di ciclo
    int j;

    printf("Inserisci nome del polinomio da caricare:");
    scanf(" %10s", s);

    // Apro il file
    file = apri_file(s, "r");

    // Stampare il polinomio su file
    // Leggo quanti coefficenti al il polinomio
    fscanf(file, "%d\n" , size);
    fscanf(file, "[");
    for(j = 0 ; j < (*size) - 1 ; j++){
        // Leggo i coefficenti del polinomio
        fscanf(file, "%d,",&vett[j]);
    }
    fscanf(file, "%d]",&vett[j]);

    // Stampo i coefficenti
    stampa_vettore(vett, *size);

    //Chiudo il file
    fclose(file);
}

void stampa_polinomio(const int vett[],const int *size){
    // Varibile di appoggio 
    int n;
    // Controllo vettore vuoto
    if(*size == 0){
        printf("Polinomio vuoto\n");
        return;
    }
    
    //Stampare il contenuto di vett
    printf("Il polinomio è: ");
    for(int j = *size - 1 ; j >= 0 ; j--){
        if(vett[j] < 0){
            printf("-"); 
            n = -vett[j];
        }else{
            printf("+");  
            n = vett[j];         
        }
        switch (j)
        {
            case 0:
                printf(" %d ",n); 
                break;

            case 1:
                printf(" %d x ",n); 
                break;

            default:
                printf(" %d x^%d ",n,j);
                break;
        }
    }
    printf("\n");
}

void salva_polinomio(const int vett[],const int *size){
    // Nome del file dove viene salvato il polinomio
    char s[10];

    // File  di salvataggio del polinomio
    FILE *file;

    // Variablile di ciclo
    int j;

    if(*size == 0){
        printf("Polinomio vuoto\n");
        return;
    }

    printf("Inserisci nome del polinomio:");
    scanf(" %10s", s);

    // Apro il file
    file = apri_file(s, "w");

    // Stampare il polinomio su file
    // Stampo la dimensione per prima così so quanti coefficenti sono nel momento in cui dovro caricarli
    fprintf(file, "%d\n",*size);
    // Scrivo su file i coefficenti come quando li stampo a video
    fprintf(file, "[");
    for(j = 0 ; j < *size - 1 ; j++){
        fprintf(file, "%d,",vett[j]);
    }
    fprintf(file, "%d]",vett[j]);

    //Chiudo il file
    fclose(file);
}

void valuta_polinomio(const int *vett,const int *size){
    //File di valutazione dei polinomi
    FILE *file;

    // Variabili di appoggio
    double da, a, p, x, fx;

    if(*size == 0){
        printf("Polinomio vuoto\n");
        return;
    }

    printf("Valuta polinomio da: ");
    scanf(" %lf", &da);
    printf("a: ");
    scanf(" %lf", &a);
    printf("passo da utilizzare: ");
    scanf(" %lf", &p);

    // Apro il file
    file = apri_file("valori", "a");
    
    // Inizializzo x = da;
    x = da;
    // Ciclo fin quando 'x' non vale più di 'a' 
    while(x < a){
        // Valutazione di un polinomio utilizzando il metodo di Horner
        // https://it.wikipedia.org/wiki/Regola_di_Horner
        // Assegno il coefficento più significativo
        fx = vett[(*size)-1];
        for(int j = (*size)-2; j >= 0; j--){
            // Moltiplico al valore precedente di fx il valore di x poi sommo il coefficente
            fx = fx * x + vett[j];
        }
        //Scrivo su file i valori di
        fprintf(file, "%lf %lf\n", x, fx);
        x += p;
    }

    fclose(file);
}

void ciclo_programma(int vett[], int *size){
    //Carattere da leggere
    char c;
    //Variabile di ciclo
    int fine = 0;
    do{
        printf("Scegli comando:\n");
        printf("n - crea nu nuovo polinomio\n");
        printf("c - carica un polinomio\n");
        printf("s - salva polinomio corrente\n");
        printf("v - valuta polinomio corrente\n");
        printf("m - mostra a schermo il polinomio corrente\n");
        printf("q - per terminare\n");

        //Leggo un char
        scanf(" %c", &c);

        switch (c)
        {
            case 'n':
                nuovo_polinomio(vett, size);
                break;

            case 'c':
                carica_polinomio(vett, size);
                break;

            case 's':
                salva_polinomio(vett, size);
                break;

            case 'v':
                valuta_polinomio(vett, size);
                break;

            case 'm':
                stampa_polinomio(vett, size);
                break;

            case 'q':
                fine = 1;
                break;

            default:
                printf("Carattere errato.\n");
                break;
        }
    }while(fine == 0);
}

int main(){
    // Dimensione polinomio
    int size = 0;
    // Elementi polinomio
    int vett[SIZE];
    
    ciclo_programma(vett, &size);
}