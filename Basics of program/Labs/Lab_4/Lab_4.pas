program Lab_4;

var T,TR:array [1..34] of integer;
  i,max,min,n,k:integer;

begin
  randomize;
  write('n= ');
  readln(n);
  writeln('Perviy:');
  for i:=1 to n do
      begin
      T[i]:=random(n);
      write('T[',i,'] = ',T[i],' ');
      end;
  max:=t[1];
  min:=t[1];
  for i:=1 to n do
      begin
      if T[i]>max then
          max:=T[i];
      if T[i]<min then
          min:=T[i];
      end;
  k:=1;
  for i:=1 to n do
      if (T[i]<max) and (T[i]>min) then
          begin
          TR[k]:=T[i];
          k:=k+1;
          end;
  writeln;
  writeln;
  writeln('Vtoroy:');
  if (k<>1) then
  for i:=1 to k-1 do
      write('TR[',i,'] = ',TR[i],' ')
  else writeln ('Massive sodetzhit tolko max i min elemnti');
   readln
end.

