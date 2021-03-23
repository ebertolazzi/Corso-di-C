#include "SEIR_taylor.h"

#include <stdio.h>
#include <stdlib.h>

int
main() {
  real_type t, T_max, delta_t, Y0[4], Y[4], Y_new[4];
  integer   order;
  SEIR_data SD;
  FILE      *fd_out;
  char      out_file[] = "SEIR_result.txt";

  // legge dati da file
  printf("Lettura file con i dati del problema\n");
  SEIR_parse_file(
    "SEIR_data.txt",
    &order,   // ordine di integrazione (letto)
    &SD,      // struttura dati del modello (letto)
    Y0,       // dato iniziale (letto)
    &T_max,   // range della simulazione (letto)
    &delta_t  // passo avanzamento (letto)
  );

  printf("Dati modello:\n");
  printf("alpha:    %lf\n",SD.alpha);
  printf("beta:     %lf\n",SD.beta);
  printf("gamma:    %lf\n",SD.gamma);
  printf("S(0):     %lf\n",Y0[0]);
  printf("E(0):     %lf\n",Y0[1]);
  printf("I(0):     %lf\n",Y0[2]);
  printf("R(0):     %lf\n",Y0[3]);
  printf("T_max:    %lf\n",T_max);
  printf("delta_t:  %lf\n",delta_t);
  printf("order:    %d\n",order);

  // integra soluzione
  printf("Integrazione numerica della soluzione e salvataggio su file\n");

  fd_out = fopen(out_file,"w");
  if ( fd_out == NULL ) {
    printf("Fallita apertura file: %s\n",out_file );
    exit(1);
  }

  fprintf( fd_out, "#\n# risultati simulazione SEIR model\n#\n# t S E I R\n" );

  // copia dato iniziale
  Y[0] = Y0[0];
  Y[1] = Y0[1];
  Y[2] = Y0[2];
  Y[3] = Y0[3];
  t    = 0;
  fprintf( fd_out, "%g\t%g\t%g\t%g\t%g\n", t, Y[0], Y[1], Y[2], Y[3] );
  while ( t < T_max ) {
    SEIR_advance( order, &SD, t, Y, delta_t, Y_new );
    // aggiorna Y a Y_new
    Y[0] = Y_new[0];
    Y[1] = Y_new[1];
    Y[2] = Y_new[2];
    Y[3] = Y_new[3];
    t   += delta_t;
    fprintf( fd_out, "%g\t%g\t%g\t%g\t%g\n", t, Y[0], Y[1], Y[2], Y[3] );
  }

  printf("All done Folks\n");
  return 0;
}
