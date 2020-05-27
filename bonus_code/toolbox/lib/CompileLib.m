clc;
clear functions;

NAMES = { ...
  'SIR_integrate' ...
  'SEIR_integrate' ...
};

[~,mexLoaded] = inmem('-completenames');

for k=1:length(NAMES)
  N=NAMES{k};
  disp('---------------------------------------------------------');
  fprintf(1,'Compiling: %s\n',N);

  CMD = [ 'while mislocked(''' N '''); munlock(''' N '''); end;'];
  eval(CMD);

  CMD = [ 'mex -I../src_mex -output ../lib/', N ];
  CMD = [ CMD, ' -largeArrayDims ../src_mex/mex_', N, '.cc' ];
  if isunix
    if ismac
      CMD = [CMD, ' -lstdc++ CXXFLAGS="\$CXXFLAGS -Wall -O2 -g"'];
    else
      CMD = [CMD, ' -lstdc++ CXXFLAGS="\$CXXFLAGS -Wall -O2 -g"'];
    end
  elseif ispc
  end
  disp(CMD);
  eval(CMD);
end

disp('----------------------- DONE ----------------------------');
