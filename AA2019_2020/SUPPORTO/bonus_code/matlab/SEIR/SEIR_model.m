% Copyright (C) 2020 Enrico Bertolazzi
%
%
% base class to solve problems of the form:
%
%       minimize    F(X)
%    LB <= X <= UB
%
classdef SEIR_model < handle

  %% MATLAB class wrapper for the underlying C++ class
  properties (SetAccess = protected, Hidden = true)
    N;
    dd;  % days
    Sd;  % susceptible
    Id;  % infected
    Rd;  % recovered
    Dd;  % dead
    Tinc;
    population;
    Rt_change;
  end

  methods
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    function self = SEIR_model( dd, Sd, Id, Rd, Dd, Rt_change, pop, Tinc )
      self.setup( dd, Sd, Id, Rd, Dd, Rt_change, pop, Tinc );
    end
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    function vave = smooth( self, v, nave )
      vave = v(:);
      for k=1:nave
        vave = [ 0.75*vave(1)+0.25*vave(2); ...
                 0.25*vave(1:end-2)+0.5*vave(2:end-1)+0.25*vave(3:end),
                 0.75*vave(end)+0.25*vave(end-1)];
      end
    end
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    function setup( self, dd, Sd, Id, Rd, Dd, Rt_change, pop, Tinc )
      self.dd         = dd;
      self.Sd         = Sd(:);
      self.Id         = self.smooth(Id,3);
      self.Rd         = Rd(:);
      self.Dd         = self.smooth(Dd,3);
      self.Rt_change  = Rt_change;
      self.population = pop;
      self.Tinc       = Tinc;
      self.N          = length(dd);
    end
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    function info( self )
      fprintf('dd=\n'); disp( self.dd );
      fprintf('Sd=\n'); disp( self.Sd );
      fprintf('Id=\n'); disp( self.Id );
      fprintf('Rd=\n'); disp( self.Rd );
      fprintf('Dd=\n'); disp( self.Dd );
    end
    %
    % S' = -Rt/(N*Tau) * S * I
    % I' = Rt/(N*Tau) * S * I - I / Tau
    % R' = I / Tau
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    function [Tinf, Lt, S0, E0, I0, R0, Rt ] = get_pars( self, X )
      Tinf = X(1);
      Lt   = X(2);
      E0   = X(3);
      I0   = X(4);
      R0   = X(5);
      Rt   = X(6:end);
      S0   = self.population-I0-E0-R0;
    end
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    function res = target( self, X )
      [ Tinf, Lt, S0, E0, I0, R0, Rt ] = self.get_pars( X );
      [S,E,I,R] = SEIR_integrate( self.dd, S0, E0, I0, R0, Tinf, self.Tinc, Rt, self.Rt_change );
      D = Lt*R;
      R = (1-Lt)*R;
      E1  = 1000000*max(max( self.Id-I, 0 ) );
      E2  = 1000000*max(max( self.Rd-R, 0 ) );
      E3  = 1000000*max(max( self.Dd-D, 0 ) );
      E4  = 100*sum(max( D-1.02*self.Dd-0.02*D(end), 0 ) )/max(self.Dd);
      E5  = 0.05*sum(abs(Rt(1:end-1)-Rt(2:end)));
      E6  = 0.01*sum( max( I-self.Id, 0 ) )/max(self.Id);
      res = E1+E2+E3+E4+E5+E6;
    end
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    function target_plot( self, X )
      [ Tinf, Lt, S0, E0, I0, R0, Rt ] = self.get_pars( X );
      [S,E,I,R] = SEIR_integrate( self.dd, S0, E0, I0, R0, Tinf, self.Tinc, Rt, self.Rt_change );
      D = Lt*R;
      R = (1-Lt)*R;
      SEIR_plot( self.dd, S, E, I, R, D, self.Id, self.Rd, self.Dd );
      disp(Rt.');
      fprintf( 'Tinf = %g, Lt = %g\n', Tinf, Lt );
    end
  end
end
