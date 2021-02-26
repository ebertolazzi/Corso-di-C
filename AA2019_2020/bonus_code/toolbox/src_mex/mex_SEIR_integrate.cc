/****************************************************************************\
  Copyright (c) Enrico Bertolazzi 2016
  All Rights Reserved.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the file license.txt for more details.
\****************************************************************************/

#include "mex_utils.hh"
#include <exception>

#define MEX_ERROR_MESSAGE \
"======================================================================\n" \
"\n" \
"FresnelCS: Integrate the SEIR model\n" \
"\n" \
"USAGE:\n" \
"  [S,E,I,R] = SEIR_integrate(t,S0,E0,I0,R0,D0,Tinf,Tinc,Rt,Rt_change);\n" \
"\n" \
"======================================================================\n" \
"\n" \
"Autor: Enrico Bertolazzi\n" \
"       Department of Industrial Engineering\n" \
"       University of Trento\n" \
"       enrico.bertolazzi@unitn.it\n" \
"\n" \
"======================================================================\n"

namespace SIR {

  using namespace std;

  typedef double real_type;

  static
  void
  SEIR_step(
    real_type   S,
    real_type   E,
    real_type   I,
    real_type   R,
    real_type   dt,
    real_type   Tinf,
    real_type   Tinc,
    real_type   Rt,
    real_type & S1,
    real_type & E1,
    real_type & I1,
    real_type & R1
  ) {
    // S' = -(Rt/(N*Tinf)) S*I
    // E' = (Rt/(N*Tinf)) S*I - E/Tinc
    // I' = E/Tinc - I/Tinf
    // R' = I/Tinf
    real_type N   = S+E+I+R;
    real_type RR  = Rt/(N*Tinf);
    real_type bf1 = RR*S*I;
    real_type bf2 = E/Tinc;
    real_type bf3 = I/Tinf;
    real_type dt2 = 0.5*dt;

    #if 1

    S1 = S + dt2*(-bf1);
    E1 = E + dt2*(bf1-bf2);
    I1 = I + dt2*(bf2-bf3);
    R1 = R + dt2*(bf3);

    bf1 = RR*S1*I1;
    bf2 = E1/Tinc;
    bf3 = I1/Tinf;

    S1 = S + dt*(-bf1);
    E1 = E + dt*(bf1-bf2);
    I1 = I + dt*(bf2-bf3);
    R1 = R + dt*(bf3);

    #else

    S1 = S + dt*(-bf1);
    E1 = E + dt*(bf1-bf2);
    I1 = I + dt*(bf2-bf3);
    R1 = R + dt*(bf3);

    bf1 += (Rt/(N*Tinf))*S1*I1;
    bf2 += E1/Tinc;
    bf3 += I1/Tinf;

    S1 = S + dt2*(-bf1);
    E1 = E + dt2*(bf1-bf2);
    I1 = I + dt2*(bf2-bf3);
    R1 = R + dt2*(bf3);

    #endif
  }

  extern "C"
  void
  mexFunction(
    int nlhs, mxArray       *plhs[],
    int nrhs, mxArray const *prhs[]
  ) {

    if ( nlhs != 4 || nrhs != 9 ) {
      mexErrMsgTxt(MEX_ERROR_MESSAGE);
      return;
    }

    try {

      mwSize nt, nr;
      real_type const * t         = getVectorPointer( arg_in_0, nt, "`t` expected to be a real scalar/vector");
      real_type         S0        = getScalarValue( arg_in_1, "`s0` expected to be a real scalar");
      real_type         E0        = getScalarValue( arg_in_2, "`s0` expected to be a real scalar");
      real_type         I0        = getScalarValue( arg_in_3, "`I0` expected to be a real scalar");
      real_type         R0        = getScalarValue( arg_in_4, "`R0` expected to be a real scalar");
      real_type         Tinf      = getScalarValue( arg_in_5, "`Tinf` expected to be a real scalar");
      real_type         Tinc      = getScalarValue( arg_in_6, "`Tinc` expected to be a real scalar");
      real_type const * Rt        = getVectorPointer( arg_in_7, nr, "`Rt` expected to be a real scalar/vector");
      mwSize            Rt_change = getInt( arg_in_8, "`Rt_change` expected to be a integer scalar");

      real_type * S = createMatrixValue( arg_out_0, nt, 1 );
      real_type * E = createMatrixValue( arg_out_1, nt, 1 );
      real_type * I = createMatrixValue( arg_out_2, nt, 1 );
      real_type * R = createMatrixValue( arg_out_3, nt, 1 );

      // integrate SIR model
      // initial condition
      S[0] = S0;
      E[0] = E0;
      I[0] = I0;
      R[0] = R0;

      for ( mwSize j = 1; j < nt; ++j ) {
        real_type day = t[j-1]-t[0];
        mwSize    kk  = floor(day/Rt_change);
        if ( kk >= nr ) {
          R0 = Rt[nr-1];
        } else {
          R0 = Rt[kk];
        }
        SEIR_step( S[j-1], E[j-1], I[j-1], R[j-1],
                   t[j]-t[j-1], Tinf, Tinc, R0,
                   S[j], E[j], I[j], R[j] );
      }

    } catch ( exception const & e ) {
    	mexErrMsgTxt(e.what());
    } catch (...) {
	    mexErrMsgTxt("SEIR failed\n");
    }
  }

}
