program Transponirovaniye;
procedure Tran(var M array of array of integer;n,q:integer);
var i,j:integer; T:array [1..3000] of integer absolute M;
begin
   for i:=1 to n-1 do
       for j:=i+1 to n do
           begin
               T[(i-1)*q+j]:=T[(i-1)*q+j]+T[(j-1)*q+i];
               T[(j-1)*q+i]:=T[(i-1)*q+j]-T[(j-1)*q+i];
               T[(i-1)*q+j]:=T[(i-1)*q+j]-T[(j-1)*q+i];
           end;
end;
const m=10;
var
  T:array [1..m,1..m] of integer;
  i,j,n:integer;
begin
  write('n = ');
  readln(n);
  randomize;
  for i:=1 to n do
      begin
      for j:=1 to n do
      begin
      T[i,j]:=random(10);
      write (T[i,j],' ');
      end;
      writeln;
      end;
  //Заполнил матрицу
  writeln;
  Tran(T,n,m);
  for i:=1 to n do
  begin
      for j:=1 to n do
      write(T[i,j],' ');
      writeln;
  end;
  readln
end.

