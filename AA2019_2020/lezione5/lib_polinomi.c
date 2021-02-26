//Libreria di input-output
#include <stdio.h>

//Libreria per includere la funzione exit
#include <stdlib.h>

//Libreria che abbiamo realizzato con le funzioni fatte nella lezione precedente
//inserisci_elemento e stampa_vettore
#include "lib_vett.h"

//Libreria per le funzioni su file
#include "lib_file.h"

// Macro che definisce la dimensione massima del polinomio
#define SIZE 10


// Creare un nuovo polinomio
void nuovo_polinomio(int vett[], int *size){
    // Variabile di ciclo
    int fine = 0;
    // Reset della dimensione del polinomio
    *size = 0;

    //Controllo se ho letto 'f' e se size < SIZE
    while(fine == 0 && (*size) < SIZE){
        // Inserisco un elemento nel vettore
        fine = inserisci_elemento(vett, size);
        // Stampa del vettore
        stampa_vettore(vett, *size);
    }
}

// Salva un polinomio su FILE
void salva_polinomio(const int vett[],const int *size){
    // Variabile nome del file del polinomio
    char s[10];

    // Puntatore al file dove sara salvato il polinomio
    FILE *file;

    // Variabile del ciclo di stampa
    int j;

    // Verifica del polinomio
    if(*size == 0){
        printf("Polinomio vuoto\n");
        return;
    }

    printf("Inserisci nome del polinomio:");
    //Lettura del nome del file del polinomio
    scanf(" %10s",s);

    // Apertura file polinomio
    file = apri_file(s,"w");

    // Stampare il polinomio su file
    // Stampo la dimensione per prima cosi so quanti coefficenti è composto il polinomio nel momento in cui dovro' caricarlo
    fprintf(file, "%d\n", *size);
    // Stampa degli elementi del polinomio
    fprintf(file, "[");
    for(j = 0; j < (*size)-1; j++){
        fprintf(file, "%d,", vett[j]);
    }
    fprintf(file, "%d]", vett[j]);

    // Chiudere il file
    fclose(file);
}

// Carica un polinomio da FILE
void carica_polinomio(int vett[], int *size){
    // Variabile nome del file del polinomio
    char s[10];

    // Puntatore al file del polinomio che sara caricato
    FILE *file;

    // Variabile del ciclo di lettura
    int j;

    printf("Inserisci nome del polinomio da caricare:");
    //Lettura del nome del file del polinomio
    scanf(" %10s",s);

    // Apertura file polinomio
    file = apri_file(s,"r");

    // Leggiamo il polinomio da file
    // Leggo la dimensione del polinomio
    fscanf(file, "%d\n", size);
    // Leggo gli elementi del polinomio
    fscanf(file, "[");
    for(j = 0; j < (*size)-1; j++){
        // Leggo i coefficenti del polinomio
        fscanf(file, "%d,", &vett[j]);
    }
    fscanf(file, "%d]", &vett[j]);

    // Stampa del vettore
    stampa_vettore(vett, *size);

    // Chiudere il file
    fclose(file);
}

void mostra_polinomio(const int vett[], const int *size){
    // Variabile di ciclo
    int j;
    // variabile di appoggio per la stampa
    int n;

    // Verifica del polinomio
    if(*size == 0){
        printf("Polinomio vuoto\n");
        return;
    }

    printf("Il polinomio è:");
    // Ciclo del polinomio per la stampa
    for(j = (*size)-1; j >= 0 ; j--){
        if(vett[j] < 0){
            printf("-");
            n = -vett[j];
        }else{
            if(j != (*size)-1){
                printf("+");
            }
            n = vett[j];
        }
        switch (j)
        {
            case 0:
                printf(" %d",n);
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

void valuta_polinomio(const int vett[],const int* size){
    // File per la valutazione del polinomio
    FILE *file;

    // Variabile ausiliarie
    double da, a, p, x, fx;

    if(*size == 0){
        printf("Polinomio vuoto\n");
        return;
    }

    // Recupero dall'utente i parametri per valutazione del polinomio
    printf("Valuta polinomio da:");
    scanf("%lf", &da);
    printf("a:");
    scanf("%lf", &a);
    printf("Passo da utilizzare:");
    scanf("%lf", &p);

    // Apro il file dove salvo i valore del polinomio valutato
    file = apri_file("valori" ,"a");

    // Valutazione del polinomio dal valore di 'x=da' al valore di 'x=a'
    x = da;
    while(x < a){
        // Valutazione di un polinomio utilizzando il metodo di Horner
        // https://it.wikipedia.org/wiki/Regola_di_Horner
        // Assegno a fx il valore del coefficente più significativo
        fx = vett[(*size)-1];
        for(int j = (*size)-2 ; j >= 0; j--){
            // Moltiplico al valore precedente di fx il valore di x poi sommo il coefficente j
            fx = fx * x + vett[j];
        }
        //Stampo sul file i falore di x ed fx
        fprintf(file, "%lf\t%lf\n", x, fx);
        x += p;
    }

    //Chiudere il file
    fclose(file);
} 
