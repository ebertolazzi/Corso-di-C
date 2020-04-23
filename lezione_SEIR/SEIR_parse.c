#include "SEIR_taylor.h"

#include <stdio.h>
#include <stdlib.h> // per la funzione exit()

// la funzione getline non è disponibile on mingw, la implementiamo qui!

#ifdef __MINGW32__

/*
  funzione copiata da
  https://stackoverflow.com/questions/735126/are-there-alternate-implementations-of-gnu-getline-interface
 */

size_t
getline(char **lineptr, size_t *n, FILE *stream) {
    char *bufptr = NULL;
    char *p = bufptr;
    size_t size;
    int c;

    if (lineptr == NULL) {
        return -1;
    }
    if (stream == NULL) {
        return -1;
    }
    if (n == NULL) {
        return -1;
    }
    bufptr = *lineptr;
    size = *n;

    c = fgetc(stream);
    if (c == EOF) {
        return -1;
    }
    if (bufptr == NULL) {
        bufptr = malloc(128);
        if (bufptr == NULL) {
            return -1;
        }
        size = 128;
    }
    p = bufptr;
    while(c != EOF) {
        if ((p - bufptr) > (size - 1)) {
            size = size + 128;
            bufptr = realloc(bufptr, size);
            if (bufptr == NULL) {
                return -1;
            }
        }
        *p++ = c;
        if (c == '\n') {
            break;
        }
        c = fgetc(stream);
    }

    *p++ = '\0';
    *lineptr = bufptr;
    *n = size;

    return p - bufptr - 1;
}

#endif

void
SEIR_parse_file(
  char const  fname[],   // nome de file
  integer   * p_order,   // ordine di integrazione (letto)
  SEIR_data * SD,        // struttura dati del modello (letto)
  real_type   Y0[],      // dato iniziale (letto)
  real_type * p_T_max,   // range della simulazione (letto)
  real_type * p_delta_t  // passo avanzamento (letto)
) {
  real_type tmp_r;
  integer   reading_status, tmp_i;
  char      *line = NULL;
  size_t    linecap = 0; // capacita della stringa attuale
  ssize_t  linelen;     // lunghezza della stringa letta
  // size_t  = intero senza segno (typedef unsigned size_t)
  // ssize_t = intero cins segno (typedef int size_t)

  FILE * fd = fopen( fname, "r" );
  if ( fd == NULL ) {
    // file non trovato o non leggibile
    printf( "File: %s, non leggibile o non esiste\n",fname );
    exit(1);
  }

  // stato di lettura
  /*
    0 -> alpha
    1 -> beta
    2 -> gamma
    3 -> S(0)
    4 -> E(0)
    5 -> I(0)
    6 -> tmax
    7 -> passo integrazione
    8 -> ordine (intero)
   */

  // loop il lettura del file, leggo una riga alla volta
  // quando linelen = 0 ho finito il file

  reading_status = 0;
  while ( (linelen = getline(&line, &linecap, fd)) > 0 ) {
    // line è stringa che contiene la riga

    // se primo carattere è # salto la riga
    if ( line[0] == '#' ) continue;

    if ( reading_status < 8 ) {
      sscanf( line, "%lf", &tmp_r );
      switch ( reading_status ) {
      case 0: SD->alpha  = tmp_r; break;
      case 1: SD->beta   = tmp_r; break;
      case 2: SD->gamma  = tmp_r; break;
      case 3: Y0[0]      = tmp_r; break;
      case 4: Y0[1]      = tmp_r; break;
      case 5: Y0[2]      = tmp_r; Y0[3] = 1-Y0[0]-Y0[1]-Y0[2]; break;
      case 6: *p_T_max   = tmp_r; break;
      case 7: *p_delta_t = tmp_r; break;
      }
      ++reading_status; // prossimo valore
    } else {
      sscanf( line, "%d", &tmp_i );
      *p_order = tmp_i;
      break; // niente altro da leggere esco..
    }
  }

  fclose( fd );
}

