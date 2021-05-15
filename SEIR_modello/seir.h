#include <stdio.h>

typedef double real_type;
typedef int integer;

// espansione taylor modello SEIR
typedef struct {
  real_type alpha;
  real_type beta;
  real_type gamma;
  real_type N;
} SEIR_model;

void
SEIR_taylor(
  integer            order,
  real_type          t,
  real_type  const   y[],
  real_type          taylor[][4],
  SEIR_model const * model
);

void
SEIR_step(
  integer            order,
  real_type          t,
  real_type  const   y[],
  real_type          delta_t,
  real_type          y_new[],
  SEIR_model const * model
);
