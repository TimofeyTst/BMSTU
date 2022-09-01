program Lab_5;
var T:array [1..10,1..10] of single;
  i,j,n,m,k:integer;


begin
  randomize;
  write('n = ');
  readln(n);
  write('m = ');
  readln(m);
  for i:=1 to n do
      for j:=1 to m do
          begin
            if (i mod 2 <> 0) then
            T[i,j]:=random(10)
            else T[i,j]:=T[i-1,j]*T[i-1,j];
          end;
  for i:=1 to n do
      begin
        k:=m-i+1;
        while k<>1 do
        begin
        k:=k-1;
        write('   ');
        end;
      for j:=1 to m do
          write(T[i,j]:2:0,' ');
      writeln;
      end;
readln
end.

