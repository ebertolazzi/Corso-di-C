function SIR_plot( d, S, I, R, D, Id, Rd, Dd )
  plot( d, I, 'Linewidth', 3, 'Color', 'blue' );
  hold on;
  %plot( d, R, 'Linewidth', 3, 'Color', 'green' );
  plot( d, D, 'Linewidth', 3, 'Color', 'red' );
  nn = length(Id);
  plot( d(1:nn), Id,    'o', 'MarkerSize', 6, 'MarkerEdgeColor','b', 'MarkerFaceColor','blue' );
  %plot( d(1:nn), Rd, 'o', 'MarkerSize', 6, 'MarkerEdgeColor','b', 'MarkerFaceColor','green' );
  plot( d(1:nn), Dd,    'o', 'MarkerSize', 6, 'MarkerEdgeColor','b', 'MarkerFaceColor','red' );
  hold off;
  %legend('I','R','D','Infected data','Recovered data', 'Dead data');
  legend('I','D','Infected data', 'Dead data');
  legend('Location','northwest');
end