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
"FresnelCS: Integrate the SIR model\n" \
"\n" \
"USAGE:\n" \
"  [S,I,R] = SIR_integrate(t,S0,I0,R0,Tau,Rt,Rt_change);\n" \
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
  SIR_step(
    real_type   S,
    real_type   I,
    real_type   R,
    real_type   dt,
    real_type   Tau,
    real_type   Rt,
    real_type & S1,
    real_type & I1,
    real_type & R1
  ) {
    // S' = -(Rt/(N*Tau)) S*I
    // I' = (Rt/(N*Tau)) S*I - I/Tau
    // R' = I/Tau
    real_type N   = S+I+R;
    real_type bf2 = I/Tau;
    real_type bf1 = bf2*(Rt/N)*S;
    real_type dt2 = 0.5*dt;

    S1 = S + dt2*(-bf1);
    I1 = I + dt2*(bf1-bf2);
    R1 = R + dt2*(bf2);

    bf2 = I1/Tau;
    bf1 = bf2*(Rt/N)*S1;

    S1 = S + dt*(-bf1);
    I1 = I + dt*(bf1-bf2);
    R1 = R + dt*(bf2);
  }

  extern "C"
  void
  mexFunction(
    int nlhs, mxArray       *plhs[],
    int nrhs, mxArray const *prhs[]
  ) {

    if ( nlhs != 3 || nrhs != 7 ) {
      mexErrMsgTxt(MEX_ERROR_MESSAGE);
      return;
    }

    try {

      mwSize nt, nr;
      real_type const * t         = getVectorPointer( arg_in_0, nt, "`t` expected to be a real scalar/vector");
      real_type         S0        = getScalarValue( arg_in_1, "`s0` expected to be a real scalar");
      real_type         I0        = getScalarValue( arg_in_2, "`I0` expected to be a real scalar");
      real_type         R0        = getScalarValue( arg_in_3, "`R0` expected to be a real scalar");
      real_type         Tau       = getScalarValue( arg_in_4, "`Tau` expected to be a real scalar");
      real_type const * Rt        = getVectorPointer( arg_in_5, nr, "`Rt` expected to be a real scalar/vector");
      mwSize            Rt_change = getInt( arg_in_6, "`Rt_change` expected to be a integer scalar");

      real_type * S = createMatrixValue( arg_out_0, nt, 1 );
      real_type * I = createMatrixValue( arg_out_1, nt, 1 );
      real_type * R = createMatrixValue( arg_out_2, nt, 1 );

      // integrate SIR model
      // initial condition
      S[0] = S0;
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
        SIR_step( S[j-1], I[j-1], R[j-1], t[j]-t[j-1], Tau, R0, S[j], I[j], R[j] );
      }

    } catch ( exception const & e ) {
    	mexErrMsgTxt(e.what());
    } catch (...) {
	    mexErrMsgTxt("FresnelCS failed\n");
    }
  }

}
