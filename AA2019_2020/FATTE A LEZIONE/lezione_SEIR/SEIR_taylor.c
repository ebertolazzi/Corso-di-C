#include "SEIR_taylor.h"

void
SEIR_D(
  SEIR_data const * SD,
  real_type         t,
  real_type const   Y[],
  real_type         Y_D[]
) {

  real_type alpha = SD->alpha;
  real_type beta  = SD->beta;
  real_type gamma = SD->gamma;

  real_type S = Y[0];
  real_type E = Y[1];
  real_type I = Y[2];
  //real_type R = Y[3];

  real_type t2 = beta * S * I;
  real_type t3 = alpha * E;
  real_type t5 = gamma * I;

  Y_D[0] = -t2;
  Y_D[1] = t2-t3;
  Y_D[2] = t3-t5;
  Y_D[3] = t5;
}

void
SEIR_DD(
  SEIR_data const * SD,
  real_type         t,
  real_type const   Y[],
  real_type const   Y_D[],
  real_type         Y_DD[]
) {

  real_type alpha = SD->alpha;
  real_type beta  = SD->beta;
  real_type gamma = SD->gamma;

  real_type S = Y[0];
  //real_type E = Y[1];
  real_type I = Y[2];
  //real_type R = Y[3];

  real_type S_D = Y_D[0];
  real_type E_D = Y_D[1];
  real_type I_D = Y_D[2];
  //real_type R_D = Y_D[3];

  real_type t2 = beta*I*S_D;
  real_type t4 = S*beta*I_D;
  real_type t6 = alpha*E_D;
  real_type t8 = gamma*I_D;

  Y_DD[0] = -t2-t4;
  Y_DD[1] = t2+t4-t6;
  Y_DD[2] = t6-t8;
  Y_DD[3] = t8;

}

void
SEIR_DDD(
  SEIR_data const * SD,
  real_type         t,
  real_type const   Y[],
  real_type const   Y_D[],
  real_type const   Y_DD[],
  real_type         Y_DDD[]
) {

  real_type alpha = SD->alpha;
  real_type beta  = SD->beta;
  real_type gamma = SD->gamma;

  real_type S = Y[0];
  //real_type E = Y[1];
  real_type I = Y[2];
  //real_type R = Y[3];

  real_type S_D = Y_D[0];
  //real_type E_D = Y_D[1];
  real_type I_D = Y_D[2];
  //real_type R_D = Y_D[3];

  real_type S_DD = Y_DD[0];
  real_type E_DD = Y_DD[1];
  real_type I_DD = Y_DD[2];
  //real_type R_DD = Y_DD[3];

  real_type t6 = beta*(I*S_DD+2.0*I_D*S_D+I_DD*S);
  real_type t7 = alpha*E_DD;
  real_type t9 = gamma*I_DD;

  Y_DDD[0] = -t6;
  Y_DDD[1] = t6-t7;
  Y_DDD[2] = t7-t9;
  Y_DDD[3] = t9;

}

void
SEIR_DDDD(
  SEIR_data const * SD,
  real_type         t,
  real_type const   Y[],
  real_type const   Y_D[],
  real_type const   Y_DD[],
  real_type const   Y_DDD[],
  real_type         Y_DDDD[]
) {
  real_type alpha = SD->alpha;
  real_type beta  = SD->beta;
  real_type gamma = SD->gamma;

  real_type S = Y[0];
  //real_type E = Y[1];
  real_type I = Y[2];
  //real_type R = Y[3];

  real_type S_D = Y_D[0];
  //real_type E_D = Y_D[1];
  real_type I_D = Y_D[2];
  //real_type R_D = Y_D[3];

  real_type S_DD = Y_DD[0];
  //real_type E_DD = Y_DD[1];
  real_type I_DD = Y_DD[2];
  //real_type R_DD = Y_DD[3];

  real_type S_DDD = Y_DDD[0];
  real_type E_DDD = Y_DDD[1];
  real_type I_DDD = Y_DDD[2];
  //real_type R_DDD = Y_DDD[3];

  real_type t8 = beta*(I*S_DDD+3.0*I_D*S_DD+3.0*I_DD*S_D+I_DDD*S);
  real_type t9 = alpha*E_DDD;
  real_type t11 = gamma*I_DDD;

  Y_DDDD[0] = -t8;
  Y_DDDD[1] = t8-t9;
  Y_DDDD[2] = t9-t11;
  Y_DDDD[3] = t11;

}

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
) {
  real_type alpha = SD->alpha;
  real_type beta  = SD->beta;
  real_type gamma = SD->gamma;

  real_type S = Y[0];
  //real_type E = Y[1];
  real_type I = Y[2];
  //real_type R = Y[3];

  real_type S_D = Y_D[0];
  //real_type E_D = Y_D[1];
  real_type I_D = Y_D[2];
  //real_type R_D = Y_D[3];

  real_type S_DD = Y_DD[0];
  //real_type E_DD = Y_DD[1];
  real_type I_DD = Y_DD[2];
  //real_type R_DD = Y_DD[3];

  real_type S_DDD = Y_DDD[0];
  //real_type E_DDD = Y_DDD[1];
  real_type I_DDD = Y_DDD[2];
  //real_type R_DDD = Y_DDD[3];

  real_type S_DDDD = Y_DDDD[0];
  real_type E_DDDD = Y_DDDD[1];
  real_type I_DDDD = Y_DDDD[2];
  //real_type R_DDDD = Y_DDDD[3];

  real_type t10 = beta*(I*S_DDDD+4.0*I_D*S_DDD+6.0*I_DD*S_DD+4.0*I_DDD*S_D+I_DDDD*S);
  real_type t11 = alpha*E_DDDD;
  real_type t13 = gamma*I_DDDD;

  Y_DDDDD[0] = -t10;
  Y_DDDDD[1] = t10-t11;
  Y_DDDDD[2] = t11-t13;
  Y_DDDDD[3] = t13;
}

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
) {
  real_type alpha = SD->alpha;
  real_type beta  = SD->beta;
  real_type gamma = SD->gamma;

  real_type S = Y[0];
  //real_type E = Y[1];
  real_type I = Y[2];
  //real_type R = Y[3];

  real_type S_D = Y_D[0];
  //real_type E_D = Y_D[1];
  real_type I_D = Y_D[2];
  //real_type R_D = Y_D[3];

  real_type S_DD = Y_DD[0];
  //real_type E_DD = Y_DD[1];
  real_type I_DD = Y_DD[2];
  //real_type R_DD = Y_DD[3];

  real_type S_DDD = Y_DDD[0];
  //real_type E_DDD = Y_DDD[1];
  real_type I_DDD = Y_DDD[2];
  //real_type R_DDD = Y_DDD[3];

  real_type S_DDDD = Y_DDDD[0];
  //real_type E_DDDD = Y_DDDD[1];
  real_type I_DDDD = Y_DDDD[2];
  //real_type R_DDDD = Y_DDDD[3];

  real_type S_DDDDD = Y_DDDDD[0];
  real_type E_DDDDD = Y_DDDDD[1];
  real_type I_DDDDD = Y_DDDDD[2];
  //real_type R_DDDDD = Y_DDDDD[3];

  real_type t12 = beta*(I*S_DDDDD+5.0*I_D*S_DDDD+10.0*I_DD*S_DDD+10.0*I_DDD*S_DD+5.0*I_DDDD*S_D+I_DDDDD*S);
  real_type t13 = alpha*E_DDDDD;
  real_type t15 = gamma*I_DDDDD;

  Y_DDDDDD[0] = -t12;
  Y_DDDDDD[1] = t12-t13;
  Y_DDDDDD[2] = t13-t15;
  Y_DDDDDD[3] = t15;
}

void
SEIR_advance(
  integer           order,   // 1,2,...,6 ordine metodo numerico
  SEIR_data const * SD,      // dati modello
  real_type         t,       //
  real_type const   Y[],     // Y(t) soluzione approx al tempo t
  real_type         delta_t, // incremento h
  real_type         Y_new[]  // Y(t+h) soluzione approx al tempo t+h
) {
  real_type tmp;
  // vettori che contengono le derivate della soluzione
  real_type Y_D[4],
            Y_DD[4],
            Y_DDD[4],
            Y_DDDD[4],
            Y_DDDDD[4],
            Y_DDDDDD[4];

  // controllo order sia tra 1 e 6

  // copia Y_new = Y
  Y_new[0] = Y[0];
  Y_new[1] = Y[1];
  Y_new[2] = Y[2];
  Y_new[3] = Y[3];

  // metodo al primo ordine
  SEIR_D( SD, t, Y, Y_D );
  Y_new[0] += delta_t * Y_D[0];
  Y_new[1] += delta_t * Y_D[1];
  Y_new[2] += delta_t * Y_D[2];
  Y_new[3] += delta_t * Y_D[3];

  if ( order <= 1 ) return;

  // metodo al secondo ordine
  SEIR_DD( SD, t, Y, Y_D, Y_DD );
  tmp = delta_t*delta_t/2;
  Y_new[0] += tmp * Y_DD[0];
  Y_new[1] += tmp * Y_DD[1];
  Y_new[2] += tmp * Y_DD[2];
  Y_new[3] += tmp * Y_DD[3];

  if ( order <= 2 ) return;

  // metodo al terzo ordine
  SEIR_DDD( SD, t, Y, Y_D, Y_DD, Y_DDD );
  tmp *= delta_t/3;
  Y_new[0] += tmp * Y_DDD[0];
  Y_new[1] += tmp * Y_DDD[1];
  Y_new[2] += tmp * Y_DDD[2];
  Y_new[3] += tmp * Y_DDD[3];

  if ( order <= 3 ) return;

  // metodo al quarto ordine
  SEIR_DDDD( SD, t, Y, Y_D, Y_DD, Y_DDD, Y_DDDD );
  tmp *= delta_t/4;
  Y_new[0] += tmp * Y_DDDD[0];
  Y_new[1] += tmp * Y_DDDD[1];
  Y_new[2] += tmp * Y_DDDD[2];
  Y_new[3] += tmp * Y_DDDD[3];

  if ( order <= 4 ) return;

  // metodo al quinto ordine
  SEIR_DDDDD( SD, t, Y, Y_D, Y_DD, Y_DDD, Y_DDDD, Y_DDDDD );
  tmp *= delta_t/5;
  Y_new[0] += tmp * Y_DDDDD[0];
  Y_new[1] += tmp * Y_DDDDD[1];
  Y_new[2] += tmp * Y_DDDDD[2];
  Y_new[3] += tmp * Y_DDDDD[3];

  if ( order <= 5 ) return;

  // metodo al sesto ordine
  SEIR_DDDDDD( SD, t, Y, Y_D, Y_DD, Y_DDD, Y_DDDD, Y_DDDDD, Y_DDDDDD );
  tmp *= delta_t/6;
  Y_new[0] += tmp * Y_DDDDDD[0];
  Y_new[1] += tmp * Y_DDDDDD[1];
  Y_new[2] += tmp * Y_DDDDDD[2];
  Y_new[3] += tmp * Y_DDDDDD[3];

}

