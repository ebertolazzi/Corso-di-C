
#include <stdio.h>
// Libreria per includere EXIT_SUCCESS e EXIT_FAILURE
#include <stdlib.h>

// Link parametri da riga di comando
// https://publications.gbdirect.co.uk/c_book/chapter10/arguments_to_main.html

// Libreria per gestire le stringhe 
// https://publications.gbdirect.co.uk/c_book/chapter9/string_handling.html
#include <string.h>

int leggo_parametro(int argc, char *argv[], int *ind /* Indica la posizione a cui sono arrivato*/){ 
    if((*ind) >= argc){
        printf("Parametri finiti\n");
        return EXIT_FAILURE;
    }
    if(strlen(argv[*ind]) == 2){
        switch (argv[*ind][1] /* Leggo il secondo carattere che indica il comando */)
        {
        case 'z': // Zero parametri
            printf("Lettura zero parametri successivi\n");
            (*ind) += 1;
            return EXIT_SUCCESS;

        case 'u': // Un parametro
            if((*ind) + 1 < argc){
                printf("Lettura un parametro successivo: %s\n", argv[(*ind) + 1]);
                (*ind) += 2;
                return EXIT_SUCCESS;
            }
            break;

        case 'd': // Due parametro
            if((*ind) + 2 < argc){
                printf("Lettura due parametri successivi: %s, %s\n", argv[(*ind) + 1], argv[(*ind) + 2]);
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

int main(
    int argc,       // Numero di parametri  
    char *argv[]    // Lista dei parametri
    ){
    //Stampato la lista dei parametri
    // for(int i = 0; i < argc; i++){
    //     printf("Parametro %d: %s\n",i,argv[i]);
    // }

    // Gestione di un singola tipologia di parametri
    // if(argc == 2){
    //     printf("Due parametri sono %s, %s\n", argv[1], argv[2]);
    // }

    // Gestione di tipologie varie di parametri
    // switch (argc)
    // {
    // case 1:
    //     printf("Un parametro %s\n", argv[1]);
    //     break;

    // case 2:
    //     printf("Due parametri sono %s, %s\n", argv[1], argv[2]);
    //     break;

    // default:
    //     return EXIT_FAILURE;
    //     break;
    // }
    int ind = 1;
    while(leggo_parametro(argc, argv, &ind) == 0);

    // Uscita standard
    return EXIT_SUCCESS;
}