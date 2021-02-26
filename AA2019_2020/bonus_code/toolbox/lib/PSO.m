% Copyright (C) 2020 Enrico Bertolazzi

% PSO finds a minimum of a function of several variables using the particle swarm
% optimization (PSO) algorithm originally introduced in 1995 by Kennedy andEberhart.
% This algorithm was extended by Shi and Eberhart in 1998 through the
% introduction of inertia factors to dampen the velocities of the particles.
% In 2002, Clerc and Kennedy introduced a constriction factor in PSO, which was
% later on shown to be superior to the inertia factors. Therefore, the algorithm
% using a constriction factor was implemented here.
%
% PSO attempts to solve problems of the form:
%
%     minimize      F(X)
%   LB <= X <= UB
%
classdef PSO < EvolutionaryBase

  %% MATLAB class wrapper for the underlying C++ class
  properties (SetAccess = protected, Hidden = true)
    COGNITIVE_ACC;  %
    SOCIAL_ACC;     %
    VELOCITIES;
    CONSTRICTION_FACTOR;
    OLD_FITNESS;
  end

  methods
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    function self = PSO()
      self@EvolutionaryBase();
      self.COGNITIVE_ACC = 2.8;
      self.SOCIAL_ACC    = 1.3;
    end
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    function setAcceleration( self, C_ACC, S_ACC )
      % calculate constriction factor from acceleration coefficients
      ACC = C_ACC + S_ACC;
      if ACC <= 4
        % display message
        fprintf('Sum of Cognitive Acceleration Coefficient and\n');
        fprintf('Social Acceleration Coefficient is less then or equal to 4.\n');
        fprintf('Their values were adjusted automatically to satisfy this condition.\n');
        % the values are adjusted so that the sum is equal to 4.1,
        % keeping the ratio COGNITIVE_ACC/SOCIAL_ACC constant
        SCALE              = 4.1/ACC;
        self.COGNITIVE_ACC = SCALE * C_ACC;
        self.SOCIAL_ACC    = SCALE * S_ACC;
      else
        self.COGNITIVE_ACC = C_ACC;
        self.SOCIAL_ACC    = S_ACC;
      end
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
      for k=1:self.POP_SIZE % check the remaining members
        plot( [ self.OLD_POP(k,1),self.POP(k,1)], ...
              [ self.OLD_POP(k,2),self.POP(k,2)], ...
              '-', 'Linewidth', 2 );
      end
      plot( self.OLD_POP(:,1), self.OLD_POP(:,2), 'o', ...
            'MarkerSize',4, 'MarkerEdgeColor','b', 'MarkerFaceColor','yellow' );
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
      % calculate constriction factor
      PHI                      = self.COGNITIVE_ACC+self.SOCIAL_ACC;
      self.CONSTRICTION_FACTOR = 2/(abs(2-PHI-sqrt(PHI^2-4*PHI)));

      % Allocations
      self.VELOCITIES  = zeros(self.POP_SIZE,self.DIM);
      self.OLD_FITNESS = Inf*ones(self.POP_SIZE,1);
    end
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    function updatePopulation( self, iter )
      % update the VELOCITIES
      C_ACC      = self.COGNITIVE_ACC.*rand(self.POP_SIZE,self.DIM);
      S_ACC      = self.SOCIAL_ACC.*rand(self.POP_SIZE,self.DIM);
      GBEST_POP  = repmat(self.GBEST,self.POP_SIZE,1);
      self.VELOCITIES = self.CONSTRICTION_FACTOR.*( ...
        self.VELOCITIES + ...
           C_ACC.*(self.BEST_POP-self.OLD_POP) + ...
           S_ACC.*(GBEST_POP-self.OLD_POP) ...
        );

      % update particle positions
      self.POP = self.OLD_POP + self.VELOCITIES;
    end
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    function selectPopulation( self, iter )
      % Select which vectors are allowed to enter the new population
      IDX = find( self.OLD_FITNESS < self.FITNESS & rand(self.POP_SIZE,1) < 0.75 );
      self.POP(IDX,:)      = self.OLD_POP(IDX,:);
      self.FITNESS(IDX)    = self.OLD_FITNESS(IDX);
      self.VELOCITIES(IDX) = 0;
      self.OLD_FITNESS     = self.FITNESS;
    end
  end
end
