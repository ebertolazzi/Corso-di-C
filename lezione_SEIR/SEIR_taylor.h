/*

  Modello SEIR integrazione con metodo di Taylor

 */

// cassico trucco per evitare doppia inclusione
#ifndef SEIR_TAYLOR_H
#define SEIR_TAYLOR_H

// parametrizzazione numeri reali
typedef double real_type;

// parametrizzazione numeri interi
typedef int integer;

// struttura con i parametri del modello SEIR
typedef struct {
  real_type alpha;
  real_type beta;
  real_type gamma;
} SEIR_data;

void
SEIR_D(
  SEIR_data const * SD,
  real_type         t,
  real_type const   Y[],
  real_type         Y_D[]
);

void
SEIR_DD(
  SEIR_data const * SD,
  real_type         t,
  real_type const   Y[],
  real_type const   Y_D[],
  real_type         Y_DD[]
);

void
SEIR_DDD(
  SEIR_data const * SD,
  real_type         t,
  real_type const   Y[],
  real_type const   Y_D[],
  real_type const   Y_DD[],
  real_type         Y_DDD[]
);

void
SEIR_DDDD(
  SEIR_data const * SD,
  real_type         t,
  real_type const   Y[],
  real_type const   Y_D[],
  real_type const   Y_DD[],
  real_type const   Y_DDD[],
  real_type         Y_DDDD[]
);

void
SEIR_DDDDD(
  SEIR_data const * SD,
  real_type         t,
  real_type const   Y[],
  real_type const   Y_D[],
  real_type const   Y_DD[],
  real_type const   Y_DDD[],
  real_type const   Y_DDDD[],
  real_type         Y_DDDDD[]
);

void
SEIR_DDDDDD(
  SEIR_data const * SD,
  real_type         t,
  real_type const   Y[],
  real_type const   Y_D[],
  real_type const   Y_DD[],
  real_type const   Y_DDD[],
  real_type const   Y_DDDD[],
  real_type const   Y_DDDDD[],
  real_type         Y_DDDDDD[]
);

void
SEIR_advance(
  integer           order,   // 1,2,...,6 ordine metodo numerico
  SEIR_data const * SD,      // dati modello
  real_type         t,       //
  real_type const   Y[],     // Y(t) soluzione approx al tempo t
  real_type         delta_t, // incremento h
  real_type         Y_new[]  // Y(t+h) soluzione approx al tempo t+h
);

/*

  Routione per la lettura del file di dati per la simulazione

 */
void
SEIR_parse_file(
  char const  fname[],   // nome de file
  integer   * p_order,   // ordine di integrazione (letto)
  SEIR_data * SD,        // struttura dati del modello (letto)
  real_type   Y0[],      // dato iniziale (letto)
  real_type * p_T_max,   // range della simulazione (letto)
  real_type * p_delta_t  // passo avanzamento (letto)
);

#endif
