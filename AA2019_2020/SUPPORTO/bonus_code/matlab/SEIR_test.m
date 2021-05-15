%run('./getDataCOVID_ITA.m');
addpath('SEIR')

g1  = 1;
g2  = 92; %71;

%DDD = ITA;
%DDD = DATA.PA_Trento;
%DDD = DATA.Veneto;
%DDD = DATA.Lombardia;
DDD = DATA.Emilia_Romagna;
%DDD = DATA.PA_Bolzano;

dd  = DDD.d(g1:g2);
Id  = DDD.I(g1:g2);
Rd  = DDD.R(g1:g2);
Dd  = DDD.D(g1:g2);
Sd  = DDD.pop - (Id+Rd+Dd);
pop = DDD.pop;

Rt_change = 7;
Tinc      = 5.2;

model       = SEIR_model( dd, Sd, Id, Rd, Dd, Rt_change, pop, Tinc );
target      = @(X) model.target( X );
target_plot = @(X) model.target_plot( X );

opt = DE();
%opt = PSO();
% calcolo numero di settimana arrotindate per eccesso
mm  = max(1,floor((g2-1)/Rt_change));

Rtmin = zeros(1,mm);
Rtmax = 10*ones(1,mm);

% Tinf, Lt, E(0) I(0) R(0) Rt ...
LB = [8,  0.01, 0,        0,        0,       Rtmin];
UB = [10, 1,     0.01*pop, 0.01*pop, 0.01*pop, Rtmax];
opt.setProblem( target, LB, UB );
opt.setPlotFunction( target_plot, 100 );
%opt.setStrategy( 1 );

opt.setVerbose( false ) ;
opt.setPopolation( 50 );
opt.setMaxIter( 40000 );
opt.setMaxFunEvaluation( 10000000 );

opt.optimize();
res = opt.getBest();

[Tinf,Lt,S0,E0,I0,R0,Rt] = model.get_pars( res );

ddd = 1:151;
[S,E,I,R] = SEIR_integrate( ddd, S0, E0, I0, R0, Tinf, Tinc, Rt, Rt_change );
D = Lt*R;
R = (1-Lt)*R;

figure();
SEIR_plot( ddd, S, E, I, R, D, Id, Rd, Dd );

%datetime('1-Jan-2020')+70;
for k=1:length(Rt)
  data = datetime('1-Jan-2020')+ITA.d(1)+(k-1)*Rt_change;
  data = datetime(data,'Format','yyyy-MM-dd');
  fprintf('%s settimana = %6.2f Rt = %6.3f\n', data, 1+(k-1)*Rt_change/7, Rt(k) );
end
fprintf('letality = %4.3g%%\n', 100*Lt );
fprintf('Tinf     = %4.3g\n',   Tinf );
fprintf('Tinc     = %4.3g\n',   Tinc );
fprintf('pop      = %d\n',      S0+E0+I0+R0 );
