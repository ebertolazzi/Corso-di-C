function SEIR_plot( d, S, E, I, R, D, Id, Rd, Dd )
  hold off;
  plot( d, I, 'Linewidth', 3, 'Color', 'blue' );
  hold on;
  plot( d, E, 'Linewidth', 3, 'Color', 'black' );
  %plot( d, R, 'Linewidth', 3, 'Color', 'green' );
  plot( d, D, 'Linewidth', 3, 'Color', 'red' );
  nn = length(Id);
  plot( d(1:nn), Id, 'o', 'MarkerSize', 6, 'MarkerEdgeColor','b', 'MarkerFaceColor','blue' );
  %plot( d(1:nn), Rd, 'o', 'MarkerSize', 6, 'MarkerEdgeColor','b', 'MarkerFaceColor','green' );
  plot( d(1:nn), Dd, 'o', 'MarkerSize', 6, 'MarkerEdgeColor','b', 'MarkerFaceColor','red' );
  hold off;
  %legend('I','E','R','D','Infected data','Recovered data', 'Dead data');
  legend('I','E','D','Infected data', 'Dead data');
  legend('Location','northwest');
end