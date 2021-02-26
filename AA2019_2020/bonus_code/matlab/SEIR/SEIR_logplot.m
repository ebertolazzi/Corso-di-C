function SEIR_plot( d, S, E, I, R, D, Id, Rd, Dd )
  hold off;
  semilogy( d, I, 'Linewidth', 3, 'Color', 'blue' );
  hold on;
  semilogy( d, E, 'Linewidth', 3, 'Color', 'black' );
  Rscale = Rd(end)/R(end);
  semilogy( d, R*Rscale, 'Linewidth', 3, 'Color', 'green' );
  semilogy( d, D, 'Linewidth', 3, 'Color', 'red' );
  nn = length(Id);
  semilogy( d(1:nn), Id, 'o', 'MarkerSize', 6, 'MarkerEdgeColor','b', 'MarkerFaceColor','blue' );
  semilogy( d(1:nn), Rd, 'o', 'MarkerSize', 6, 'MarkerEdgeColor','b', 'MarkerFaceColor','green' );
  semilogy( d(1:nn), Dd, 'o', 'MarkerSize', 6, 'MarkerEdgeColor','b', 'MarkerFaceColor','red' );
  hold off;
  legend('I','E','R-scaled','D','Infected data','Recovered+Dead data', 'Dead data');
  legend('Location','northwest');
end