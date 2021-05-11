#include "seir.h"

void
SEIR_taylor(
  integer            order,
  real_type          t,
  real_type  const   y[],
  real_type          taylor[][4],
  SEIR_model const * model
) {

  real_type N     = model->N;
  real_type alpha = model->alpha;
  real_type beta  = model->beta;
  real_type gamma = model->gamma;

  real_type beta__N = beta/N;
  real_type S = y[0];
  real_type E = y[1];
  real_type I = y[2];
  real_type R = y[3];

  real_type t1, t2, t3, t4, t6, t8, t9, t10, t16, t17, t18, t26, t27, t28,
            t38, t39, t40, t52, t53, t54, t68, t69, t70, t86, t87, t88;

  real_type S__d1, E__d1, I__d1, R__d1;
  real_type S__d2, E__d2, I__d2, R__d2;
  real_type S__d3, E__d3, I__d3, R__d3;
  real_type S__d4, E__d4, I__d4, R__d4;
  real_type S__d5, E__d5, I__d5, R__d5;
  real_type S__d6, E__d6, I__d6, R__d6;
  real_type S__d7, E__d7, I__d7, R__d7;
  real_type S__d8, E__d8, I__d8, R__d8;

  // ordine 1
  t2 = beta__N * S * I;
  t3 = E * alpha;
  t4 = gamma * I;
  S__d1 = taylor[0][0] = -t2;
  E__d1 = taylor[0][1] = t2 - t3;
  I__d1 = taylor[0][2] = t3 - t4;
  R__d1 = taylor[0][3] = t4;

  // ordine 2
  if ( order < 2 ) return;
  t6  = S * I__d1 * beta__N;
  t8  = S__d1 * I * beta__N;
  t9  = E__d1 * alpha;
  t10 = I__d1 * gamma;
  S__d2 = taylor[1][0] = -t6 - t8;
  E__d2 = taylor[1][1] = t6 + t8 - t9;
  I__d2 = taylor[1][2] = t9 - t10;
  R__d2 = taylor[1][3] = t10;

  // ordine 3
  if ( order < 3 ) return;
  t16 = beta__N * (S * I__d2 + 2 * S__d1 * I__d1 + S__d2 * I);
  t17 = E__d2 * alpha;
  t18 = I__d2 * gamma;
  S__d3 = taylor[2][0] = -t16;
  E__d3 = taylor[2][1] = t16 - t17;
  I__d3 = taylor[2][2] = t17 - t18;
  R__d3 = taylor[2][3] = t18;

  // ordine 4
  if ( order < 4 ) return;
  t26 = beta__N * (S * I__d3 +
                   3 * S__d1 * I__d2 +
                   3 * S__d2 * I__d1 +
                   S__d3 * I);
  t27 = E__d3 * alpha;
  t28 = I__d3 * gamma;
  S__d4 = taylor[3][0] = -t26;
  E__d4 = taylor[3][1] = t26 - t27;
  I__d4 = taylor[3][2] = t27 - t28;
  R__d4 = taylor[3][3] = t28;

  // ordine 5
  if ( order < 5 ) return;
  t38 = beta__N * (S * I__d4 +
                   4 * S__d1 * I__d3 +
                   6 * S__d2 * I__d2 +
                   4 * S__d3 * I__d1 +
                   S__d4 * I);
  t39 = E__d4 * alpha;
  t40 = I__d4 * gamma;
  S__d5 = taylor[4][0] = -t38;
  E__d5 = taylor[4][1] = t38 - t39;
  I__d5 = taylor[4][2] = t39 - t40;
  R__d5 = taylor[4][3] = t40;

  // ordine 6
  if ( order < 6 ) return;
  t52 = beta__N * (S * I__d5 +
                   5 * S__d1 * I__d4 +
                   10 * S__d2 * I__d3 +
                   10 * S__d3 * I__d2 +
                   5 * S__d4 * I__d1 +
                   S__d5 * I);
  t53 = E__d5 * alpha;
  t54 = I__d5 * gamma;
  S__d6 = taylor[5][0] = -t52;
  E__d6 = taylor[5][1] = t52 - t53;
  I__d6 = taylor[5][2] = t53 - t54;
  R__d6 = taylor[5][3] = t54;

  // ordine 7
  if ( order < 7 ) return;
  t68 = beta__N * (S * I__d6 +
                   6 * S__d1 * I__d5 +
                   15 * S__d2 * I__d4 +
                   20 * S__d3 * I__d3 +
                   15 * S__d4 * I__d2 +
                   6 * S__d5 * I__d1 +
                   S__d6 * I);
  t69 = E__d6 * alpha;
  t70 = I__d6 * gamma;
  S__d7 = taylor[6][0] = -t68;
  E__d7 = taylor[6][1] = t68 - t69;
  I__d7 = taylor[6][2] = t69 - t70;
  R__d7 = taylor[6][3] = t70;

  // ordine 8
  if ( order < 8 ) return;
  t86 = beta__N * (S * I__d7 +
                   7 * S__d1 * I__d6 +
                   21 * S__d2 * I__d5 +
                   35 * S__d3 * I__d4 +
                   35 * S__d4 * I__d3 +
                   21 * S__d5 * I__d2 +
                   7 * S__d6 * I__d1 +
                   S__d7 * I);
  t87 = E__d7 * alpha;
  t88 = I__d7 * gamma;
  S__d8 = taylor[7][0] = -t86;
  E__d8 = taylor[7][1] = t86 - t87;
  I__d8 = taylor[7][2] = t87 - t88;
  R__d8 = taylor[7][3] = t88;
}


void
SEIR_step(
  integer            order,
  real_type          t,
  real_type  const   y[],
  real_type          delta_t,
  real_type          y_new[],
  SEIR_model const * model
) {
  real_type taylor[8][4];
  SEIR_taylor( order, t, y, taylor, model );
  y_new[0] = (delta_t/order)*taylor[order-1][0];
  y_new[1] = (delta_t/order)*taylor[order-1][1];
  y_new[2] = (delta_t/order)*taylor[order-1][2];
  y_new[3] = (delta_t/order)*taylor[order-1][3];
  for ( integer i = order-1; i > 0; --i ) {
    y_new[0] = (taylor[i-1][0]+y_new[0])*(delta_t/i);
    y_new[1] = (taylor[i-1][1]+y_new[1])*(delta_t/i);
    y_new[2] = (taylor[i-1][2]+y_new[2])*(delta_t/i);
    y_new[3] = (taylor[i-1][3]+y_new[3])*(delta_t/i);
  }
  y_new[0] += y[0];
  y_new[1] += y[1];
  y_new[2] += y[2];
  y_new[3] += y[3];
}
