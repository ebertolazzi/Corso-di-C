#include "seir.h"
#include <stdlib.h>

int
main() {
  SEIR_model model;
  integer   order;
  real_type S0, E0, I0, R0;
  real_type delta_t, t_max;
  real_type t, y[4], y_new[4];

  {
    real_type RT0, incubation, recovery;
    FILE * fd = fopen("data.txt","r");
    char tmp[100];
    fscanf( fd, "%s = %lg", tmp, &model.N );
    fscanf( fd, "%s = %lg", tmp, &I0 );
    fscanf( fd, "%s = %lg", tmp, &RT0 );
    fscanf( fd, "%s = %lg", tmp, &incubation );
    fscanf( fd, "%s = %lg", tmp, &recovery );
    fscanf( fd, "%s = %d",  tmp, &order );
    fscanf( fd, "%s = %lg", tmp, &delta_t );
    fscanf( fd, "%s = %lg", tmp, &t_max );
    model.alpha = 1/incubation;
    model.beta  = model.alpha*RT0;
    model.gamma = 1/recovery;
  }

  S0 = model.N-I0;
  E0 = 0;
  R0 = 0;

  printf( "population = %lg\n", model.N );
  printf( "S0         = %lg\n", S0 );
  printf( "E0         = %lg\n", E0 );
  printf( "I0         = %lg\n", I0 );
  printf( "R0         = %lg\n", R0 );
  printf( "alpha      = %lg\n", model.alpha );
  printf( "beta       = %lg\n", model.beta );
  printf( "gamma      = %lg\n", model.gamma );
  printf( "order      = %d\n", order );

  FILE * fd = fopen("out.txt","w");

  t    = 0;
  y[0] = S0;
  y[1] = E0;
  y[2] = I0;
  y[3] = R0;

  fprintf(fd,"# t S E I R\n");
  fprintf(fd,"%g\t%g\t%g\t%g\t%g\n",t,y[0],y[1],y[2],y[3]);
  while ( t <= t_max ) {
    SEIR_step( order, t, y, delta_t, y_new, &model );
    t   += delta_t;
    y[0] = y_new[0];
    y[1] = y_new[1];
    y[2] = y_new[2];
    y[3] = y_new[3];
    fprintf(fd,"%g\t%g\t%g\t%g\t%g\n",t,y[0],y[1],y[2],y[3]);
  }
  fclose(fd);

  system("gnuplot -e \"load 'gplot.cmd'; pause -1\"");
  return 0;
}
