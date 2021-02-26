//Libreria di input-output
#include <stdio.h>
// Libreria per allocazione dinamica
#include <stdlib.h>
// Libreria per gestire le stringhe
#include <string.h>
// Libreria che gestisce i segnali
#include <signal.h>

//Libreria funzioni sui polinomi
#include "lib/lib_lista_poly.h"

// Vettore di polinomi
Elem *base_poly = NULL;

void carica_polinomio_main(char *nome_file){
    Elem *p = calloc(1,sizeof(Elem));
    carica_polinomio(nome_file,&p->poly);
    int d = inserisci_in_fondo(&base_poly, p);
    printf("Il polinomio caricato da file in posizione %d è:\n", d);
    mostra_polinomio(&p->poly);
}

void salva_polinomio_main(int ind, char *nome_file){
    int i;
    Elem *p;
    printf("Salvataggio polinomio:\n");
    for(i = 0, p = base_poly; p != NULL && i < ind; p = p->next, i++);
    if(p == NULL){
        printf("Indice errato\n");
    }else{
        mostra_polinomio(&p->poly);
        salva_polinomio(nome_file, &p->poly);
    }
}

int somma_polinomi_main(int inda, int indb){
    printf("Somma di due polinomi\n");
    // Elem puntatore
    Elem *p, *pp, *ppp;
    int i;
    // Primo ciclo per determinare il primo polinomio
    for(i = 0, p = base_poly; p != NULL && i < inda; p = p->next, i++);
    printf("Primo polinomio:\n");
    if(p == NULL){
        printf("Indice errato\n");
        return EXIT_FAILURE;
    }else{
        mostra_polinomio(&p->poly);
    }
    // secondo ciclo per determinare il secondo polinomio
    for(i = 0, pp = base_poly; pp != NULL && i < indb; pp = pp->next, i++);
    printf("Secondo polinomio:\n");
    if(pp == NULL){
        printf("Indice errato\n");
        return EXIT_FAILURE;
    }else{
        mostra_polinomio(&pp->poly);
    }
    ppp = calloc(1, sizeof(Elem));
    somma_polinomi(&p->poly,&pp->poly,&ppp->poly);
    //ppp->poly = somma_polinomi_valore(&p->poly,&pp->poly);
    int d = inserisci_in_fondo(&base_poly, ppp);
    printf("Il polinomio risultato in posizione %d è:\n",d);
    mostra_polinomio(&ppp->poly);
    return EXIT_SUCCESS;
}

// Funzione per leggere i parametri
int leggo_parametro(int argc, char *argv[], int *ind){ 
    if((*ind) >= argc){
        printf("Parametri finiti\n");
        return EXIT_FAILURE;
    }
    if(strlen(argv[*ind]) == 2){
        switch (argv[*ind][1] /* Leggo il secondo carattere che indica il comando */)
        {

        case 'q':
            printf("Chiusura programma\n");
            exit(EXIT_SUCCESS);
        
        case 'c':
            if((*ind) + 1 < argc){
                carica_polinomio_main(argv[(*ind) + 1]);
                (*ind) += 2;
                return EXIT_SUCCESS;
            }
            break;
        

        case 'p':
            if((*ind) + 2 < argc){
                somma_polinomi_main(atoi(argv[(*ind) + 1]), atoi(argv[(*ind) + 2]));
                (*ind) += 3;
                return EXIT_SUCCESS;
            }
            break;

        case 's':
            if((*ind) + 2 < argc){
                salva_polinomio_main(atoi(argv[(*ind) + 1]), argv[(*ind) + 2]);
                (*ind) += 3;
                return EXIT_SUCCESS;
            }
            break; 

        default:
            printf("Parametro non riconosciuto\n");
            return EXIT_FAILURE;
        }
        printf("Numero parametri errato\n");
        return EXIT_FAILURE;        
    }else{
        printf("Parametro non conforme\n");
        return EXIT_FAILURE;        
    }
}

int scegli_indice(char *string){
    int d;
    printf("%s",string);
    scanf(" %d",&d);
    return d;
}

void ciclo_principale(){
    // nome del file
    char nome_file[10];
    // Caratte di input
    char c;
    // Fine programma
    int fine = 0;
    // Elemento ausiliario della lista
    Elem *p, *pp, *ppp;
    // indici utili per le operazioni sui polinomi
    int i, ind, inda, indb, indr;
    // Ciclo do while delle operazioni
    do{
        printf("Scegli comando:\n");
        printf("n - crea nu nuovo polinomio\n");
        printf("c - carica un polinomio\n");
        printf("s - salva polinomio corrente\n");
        printf("v - valuta polinomio corrente\n");
        printf("m - mostra a schermo un polinomio\n");
        printf("p - somma due polinomi\n");
        printf("x - moltiplica due polinomi\n");        
        printf("q - per terminare\n");

        scanf(" %c", &c);

        switch (c) {
            case 'n':
                p = calloc(1,sizeof(Elem));
                nuovo_polinomio(&p->poly);
                inserisci_in_cima(&base_poly, p);
                printf("Il nuovo polinomio in posizione 0 è:\n");
                mostra_polinomio(&p->poly);
                break;

            case 'c':
                scegli_nome_polinomio(nome_file);
                carica_polinomio_main(nome_file);
                break;

            case 's':
                ind = scegli_indice("Scegli l'indice del polinomio da salvare:");
                scegli_nome_polinomio(nome_file);
                salva_polinomio_main(ind, nome_file);
                break;

            case 'v':
                ind = scegli_indice("Scegli l'indice del polinomio da valutare:");
                for(i = 0, p = base_poly; p != NULL && i < ind; p = p->next, i++);
                if(p == NULL){
                    printf("Indice errato\n");
                }else{
                    valuta_polinomio(&p->poly);
                }
                break;

            case 'm':
                for(i = 0, p = base_poly; p != NULL ; p = p->next, i++){
                    printf("Il polinomio in posizione %d è:\n",i);
                    mostra_polinomio(&p->poly);
                }
                break;

            case 'p':
                inda = scegli_indice("Somma due polinomi, scegli l'indice del primo:");
                indb = scegli_indice("Scegli l'indice del secondo:");
                somma_polinomi_main(inda, indb);
                break;

            case 'x':
                inda = scegli_indice("Moltiplica due polinomi, scegli l'indice del primo:");
                for(i = 0, p = base_poly; p != NULL && i < inda; p = p->next, i++);
                if(p == NULL){
                    printf("Indice errato\n");
                    break;
                }else{
                    mostra_polinomio(&p->poly);
                }
                indb = scegli_indice("Scegli l'indice del secondo:");
                for(i = 0, pp = base_poly; pp != NULL && i < indb; pp = pp->next, i++);
                if(pp == NULL){
                    printf("Indice errato\n");
                    break;
                }else{
                    mostra_polinomio(&pp->poly);
                }
                ppp = calloc(1,sizeof(Elem));
                moltiplica_polinomi(&p->poly,&pp->poly,&ppp->poly);
                inserisci_in_cima(&base_poly, ppp);
                printf("Il polinomio risultato in posizione 0 è:\n");
                mostra_polinomio(&ppp->poly);
                break;

            case 'q':
                fine = 1;
                break;
                    
            default:
                printf("Comando errato.\n");
                break;
        }
    }while(fine == 0);

    // Pulizia memoria
    while (base_poly != NULL){
        p = rimuovi_at(&base_poly, 0);
        free_polinomio(&p->poly);
        free(p);
    }
}

void salva_tutti_polinomi(int sing){
    printf("Il programma è stato terminato, salvo i polinomi\n");
    // Stringa del nome del file
    char nome_file[25];
    // indice che mi dice a che polinomio sono arrivato
    int ind = 0;
    // Ciclo su tutti i polinomi e li salvo
    while (base_poly != NULL){
        // Compongo la stringa
        sprintf(nome_file,"polinomio_%d",ind++);
        // Salvo il polinomio
        salva_polinomio_main(0, nome_file);
        // Pulisco la memoria
        Elem * p = rimuovi_at(&base_poly, 0);
        free_polinomio(&p->poly);
        free(p);
    }    
    exit(EXIT_FAILURE);
}

int main(int argc, char* argv[]){
    // Quando il segnale SIGINT (interruzione da tastiera) viene lanciato la funzione terminate viene chiamata
    signal(SIGINT, salva_tutti_polinomi);
    // Gestiamo i parametri da riga di comando
    int ind = 1;
    while(leggo_parametro(argc, argv, &ind) == 0);
    // Ciclo principale
    ciclo_principale();
    // Chiusura main
    return EXIT_SUCCESS;
}