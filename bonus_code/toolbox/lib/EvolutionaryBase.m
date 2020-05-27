% Copyright (C) 2020 Enrico Bertolazzi
%
%
% base class to solve problems of the form:
%
%       minimize    F(X)
%    LB <= X <= UB
%
classdef EvolutionaryBase < handle

  %% MATLAB class wrapper for the underlying C++ class
  properties (SetAccess = protected, Hidden = true)
    FUN;           % String naming a function f(X) to minimize.
    LB;            % Vector of lower bounds LB(1) ... LB(DIM) of initial population.
    UB;            % Vector of upper bounds UB(1) ... UB(DIM) of initial population.
    DIM;           % Number of parameters of the objective function.

    MAX_ITER;      % Maximum number of iterations (generations).
    MAX_TIME;      %
    MAX_FUN_EVALS; %
    TOLX;          %
    TOLFUN;        %
    VERBOSE;       %

    POP_SIZE;      % Number of population members.
    OLD_POP;       % Previous population
    POP;           % population
    FITNESS;       % Fitness of the final population

    BEST_POP;      % Best population elements during iterations
    GBEST;         % Global best population element

    BEST_FITNESS;  % Fitness of the best population elements during iterations
    GBEST_FITNESS; % History of the fitness for the global best population member

    USER_PLOT;
    USER_PLOT_FUN;

    TIME;          % elapsed time for computation
  end

  methods(Abstract)
    initializeMethod( self );
    updatePopulation( self, nIter );
    selectPopulation( self, nIter );
  end

  methods
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    function self = EvolutionaryBase()
      % seed the random number generator
      rand('state',sum(100*clock));
      self.POP_SIZE      = 10;
      self.MAX_ITER      = 2500;
      self.MAX_FUN_EVALS = 10000000;
      self.TOLFUN        = 1e-6;
      self.MAX_TIME      = 2500;
      self.VERBOSE       = true;
      self.USER_PLOT     = 0;
    end
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    function setPopolation( self, POP_SIZE )
      self.POP_SIZE = POP_SIZE;
    end
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    function setMaxIter( self, MAX_ITER )
      self.MAX_ITER = MAX_ITER;
    end
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    function setMaxFunEvaluation( self, MAX_FUN_EVALS )
      self.MAX_FUN_EVALS = MAX_FUN_EVALS;
    end
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    function setTimeout( self, MAX_TIME )
      self.MAX_TIME = MAX_TIME;
    end
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    function setVerbose( self, VERBOSE )
      self.VERBOSE = VERBOSE;
    end
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    function setTolerance( self, TOLFUN )
      self.TOLFUN = TOLFUN;
    end
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    function setPlotFunction( self, Pfun, nplot )
      self.USER_PLOT     = nplot;
      self.USER_PLOT_FUN = Pfun;
    end
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    function setProblem( self, FUN, LB, UB )
      self.FUN = FUN;
      self.LB  = LB;
      self.UB  = UB;
      self.DIM = length(LB);
    end
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    function info( self )
      fprintf('Global best population element\n');
      disp( self.GBEST );
      fprintf('Best population element\n');
      disp( self.BEST_POP );
      fprintf( 'Global best fitness: %12.6g', self.GBEST_FITNESS(end) );
    end
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    function B = getBest( self )
      B = self.GBEST;
    end
    % - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    function EXITFLAG = optimize( self )
      EXITFLAG = -2;
      % ======================
      self.initializeMethod();
      % ======================

      % Allocations
      self.FITNESS      = zeros(self.POP_SIZE,1);
      self.BEST_POP     = zeros(self.POP_SIZE,self.DIM);
      self.BEST_FITNESS = zeros(self.POP_SIZE,1);
      self.GBEST        = zeros(1,self.DIM);

      % initialize swarm (each row of swarm corresponds to one particle)
      UB_POP       = repmat( self.UB, self.POP_SIZE, 1 );
      LB_POP       = repmat( self.LB, self.POP_SIZE, 1 );
      self.POP     = LB_POP + rand(self.POP_SIZE,self.DIM) .* (UB_POP - LB_POP);
      self.OLD_POP = self.POP;

      % Evaluate fitness
      for k=1:self.POP_SIZE % check the remaining members
        self.FITNESS(k) = feval(self.FUN,self.POP(k,:));
      end
      nFunEvals = self.POP_SIZE;

      [self.BEST_FITNESS,IDX] = min(self.FITNESS);
      self.BEST_POP           = self.POP(IDX(1),:);
      self.GBEST_FITNESS      = self.BEST_FITNESS;
      self.GBEST              = self.POP(IDX(1),:);

      % initialize timer
      tic

      % for each iteration....
      for nIter=1:self.MAX_ITER

        WORST_FITNESS = max(self.FITNESS);

        % give user feedback on screen if requested
        if self.VERBOSE > 0
          if mod(nIter,10) == 1
            disp('Iter #F eval   Global Best   Current Best  Current Worst');
          end
          fprintf( ...
            '%4d %6d %14.6g %14.6g %14.6g\n', nIter, nFunEvals, ...
            self.GBEST_FITNESS(end), self.BEST_FITNESS, WORST_FITNESS ...
          );
        elseif self.DIM == 2
          self.plot(nIter);
          drawnow;
        end

        if (self.USER_PLOT > 0) && ( mod( nIter-1, self.USER_PLOT) == 0 )
          feval( self.USER_PLOT_FUN, self.GBEST );
          drawnow;
        end

        self.OLD_POP = self.POP;

        % end the optimization if one of the stopping criteria is met
        %% 1. difference between best and worst function evaluation in simplex is smaller than TOLFUN
        %% 2. maximum difference between the coordinates of the vertices in simplex is less than TOLX
        %% 3. no convergence,but maximum number of iterations has been reached
        %% 4. no convergence,but maximum time has been reached

        if abs(WORST_FITNESS-self.BEST_FITNESS) < self.TOLFUN
          if self.VERBOSE
            disp('Change in the objective function value less than the specified tolerance (TOLFUN).')
          end
          EXITFLAG = 1;
          break;
        end

        if nFunEvals >= self.MAX_FUN_EVALS
          if self.VERBOSE
            disp('Maximum number of function evaluations reached.');
          end
          EXITFLAG = 0;
          break;
        end

        if toc/60 > self.MAX_TIME
          if self.VERBOSE
            disp('Exceeded maximum time.');
          end
          EXITFLAG = -1;
          break;
        end

        % =============================
        self.updatePopulation( nIter );
        % =============================

        % Boundary constraints via bounce back
        RND             = rand( self.POP_SIZE, self.DIM );

        IDX             = find( self.POP > UB_POP );
        self.POP(IDX)   = UB_POP(IDX) - RND(IDX).*(self.POP(IDX) - UB_POP(IDX));
        VELOCITIES(IDX) = self.POP(IDX)-self.OLD_POP(IDX);

        IDX             = find( self.POP < LB_POP );
        self.POP(IDX)   = LB_POP(IDX) - RND(IDX).*(self.POP(IDX) - LB_POP(IDX));
        VELOCITIES(IDX) = self.POP(IDX)-self.OLD_POP(IDX);

        IDX             = find( self.POP > UB_POP );
        self.POP(IDX)   = UB_POP(IDX);
        VELOCITIES(IDX) = self.POP(IDX)-self.OLD_POP(IDX);

        IDX             = find( self.POP < LB_POP );
        self.POP(IDX)   = LB_POP(IDX);
        VELOCITIES(IDX) = self.POP(IDX)-self.OLD_POP(IDX);

        % Evaluate fitness
        OLD_FITNESS = self.FITNESS;
        for k=1:self.POP_SIZE % check the remaining members
          self.FITNESS(k) = feval(self.FUN,self.POP(k,:));
        end
        nFunEvals = nFunEvals + self.POP_SIZE;

        % =============================
        self.selectPopulation( nIter );
        % =============================

        % set best population
        [C,IDX]           = min( self.FITNESS );
        self.BEST_POP     = self.POP(IDX,:);
        self.BEST_FITNESS = self.FITNESS(IDX);

        % set global best
        if self.GBEST_FITNESS(end) > self.BEST_FITNESS
          self.GBEST         = self.BEST_POP;
          self.GBEST_FITNESS = [ self.GBEST_FITNESS, self.BEST_FITNESS ];
        else
          self.GBEST_FITNESS = [ self.GBEST_FITNESS, self.GBEST_FITNESS(end) ];
        end
        %self.GBEST
      end
      self.TIME = toc;
    end
  end
end
