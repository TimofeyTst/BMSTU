program Matrica_1;


var
  A:array [1..3,1..3] of integer;
  i,j,n,m:integer;

begin
     writeln ('Matrica n*m');
     write ('n = ');
     readln(n);

     randomize;
     for i:=1 to n do
        begin
        writeln;
         for j:=1 to n do
             begin
             A[i,j]:=random(5);
             write (A[i,j],' ');
             end;
        end;
     readln
     end.
