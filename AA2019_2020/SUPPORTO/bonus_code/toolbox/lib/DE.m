% Copyright (C) 2020 Enrico Bertolazzi
%
% This code is inspired from "deopt" by Rainer Storn, Ken Price, Arnold Neumaier, Jim Van Zandt.
% Minimization of a user-supplied function using the differential evolution (DE) algorithm.
% DE works best if [LB,UB] covers the region where the global minimum is expected.
% DE is also somewhat sensitive to the choice of the step size F_WEIGHT.
% A good initial guess is to choose F_WEIGHT from interval [0.5, 1], e.g. 0.8.
% CROSS_OVER_PROB, the crossover probability constant from interval [0, 1] helps to
% maintain the diversity of the population but should be close to 1 for most.
% practical cases. Only separable problems do better with CR close to 0.
% If the parameters are correlated, high values of CROSS_OVER_PROB work better.
% The reverse is true for no correlation.
%
% The number of population members POP_SIZE is also not very critical.
% A good initial guess is 10*DIM. Depending on the difficulty of the
% problem POP_SIZE can be lower than 10*DIM or must be higher than 10*DIM
% to achieve convergence.
%
classdef DE < EvolutionaryBase

  %% MATLAB class wrapper for the underlying C++ class
  properties (SetAccess = protected, Hidden = true)
    F_WEIGHT;        % DE-stepsize F_WEIGHT from interval [0, 2].
    CROSS_OVER_PROB; % Crossover probability constant from interval [0, 1].
    DE_STRATEGY;     %
    OLD_FITNESS;
  end

  methods
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    function self = DE()
      self@EvolutionaryBase();
      self.F_WEIGHT        = [1.0, 0.8];
      self.CROSS_OVER_PROB = [0.1, 0.9, 0.2];
      self.DE_STRATEGY     = 1;
    end
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    function setWeight( self, F_WEIGHT )
      self.F_WEIGHT = F_WEIGHT;
    end
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    function setCrossOverProbability( self, CROSS_OVER_PROB )
      self.CROSS_OVER_PROB = CROSS_OVER_PROB;
    end
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    function setStrategy( self, DE_STRATEGY )
      self.DE_STRATEGY = DE_STRATEGY;
    end
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    function plot( self, iter )
      N     = 100;
      x     = linspace(self.LB(1),self.UB(1),N);
      y     = linspace(self.LB(2),self.UB(2),N);
      [X,Y] = meshgrid(x,y);
      Z     = zeros(N,N);
      for i=1:N
        for j=1:N
          Z(i,j) = feval(self.FUN,[X(i,j),Y(i,j)]);
        end
      end
      Z = log(1+(Z-min(min(Z))));
      hold off;
      contour(X,Y,Z,N/2);
      hold on;
      %for k=1:self.POP_SIZE % check the remaining members
      %  plot( [ self.OLD_POP(k,1),self.POP(k,1)], ...
      %        [ self.OLD_POP(k,2),self.POP(k,2)], ...
      %        '-', 'Linewidth', 2 );
      %end
      %plot( self.OLD_POP(:,1), self.OLD_POP(:,2), 'o', ...
      %      'MarkerSize',4, 'MarkerEdgeColor','b', 'MarkerFaceColor','yellow' );
      plot( self.POP(:,1), self.POP(:,2), 'o', ...
            'MarkerSize',8, 'MarkerEdgeColor','b', 'MarkerFaceColor','red' );
      plot( self.BEST_POP(1), self.BEST_POP(2), 'o', ...
            'MarkerSize',10, 'MarkerEdgeColor','b', 'MarkerFaceColor','blue' );
      plot( self.GBEST(1), self.GBEST(2), 'o', ...
            'MarkerSize',12, 'MarkerEdgeColor','b', 'MarkerFaceColor','green' );
      title(sprintf('iteration N.%d',iter));
    end
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    function initializeMethod( self )
      self.OLD_FITNESS = Inf*ones( self.POP_SIZE, self.DIM );
    end
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    function updatePopulation( self, iter )

      W = self.F_WEIGHT( mod(iter,length(self.F_WEIGHT)) + 1);
      P = self.CROSS_OVER_PROB( mod(iter,length(self.CROSS_OVER_PROB)) + 1);

      POP1 = self.OLD_POP(randperm(self.POP_SIZE),:);
      POP2 = self.OLD_POP(randperm(self.POP_SIZE),:);

      switch self.DE_STRATEGY
      case {3,4,5,6}
        PBEST = repmat(self.GBEST,self.POP_SIZE,1);
      end

      switch self.DE_STRATEGY
      case {2,4,6}
        POP3  = self.OLD_POP(randperm(self.POP_SIZE),:);
        POP4  = self.OLD_POP(randperm(self.POP_SIZE),:);
      end

      switch self.DE_STRATEGY
      case 1 % rand/1
        self.POP = self.OLD_POP + W*(POP1-POP2);
      case 2 % rand/2
        self.POP = self.OLD_POP + W*(POP1-POP2) + W*(POP3-POP4);
      case {3,5} % best/1, current-to-best/1
        self.POP = PBEST + W*(POP1-POP2);
      case {4,6} % best/2., current-to-best/1
        self.POP = PBEST + W*(POP1-POP2) + W*(POP3-POP4);
      end

      switch self.DE_STRATEGY
      case {1,2,3,4}
        self.POP = self.POP(randperm(self.POP_SIZE),:);
      end

      % Crossover
      POP_CR           = find( rand(self.POP_SIZE,self.DIM) > P ) ;
      self.POP(POP_CR) = self.OLD_POP(POP_CR);
    end
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    function selectPopulation( self, iter )
      % Select which vectors are allowed to enter the new population
      IDX = find( self.OLD_FITNESS < self.FITNESS );
      self.POP(IDX,:)   = self.OLD_POP(IDX,:);
      self.FITNESS(IDX) = self.OLD_FITNESS(IDX);
      self.OLD_FITNESS  = self.FITNESS;
    end
  end
end
