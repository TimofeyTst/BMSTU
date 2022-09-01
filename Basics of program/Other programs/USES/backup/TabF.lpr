program Tab;
uses Tabf;
var
  masf1,masx1:array[1..10] of single;
  masf2,masx2:array[1..20] of single;
  i:integer;
function f1(x:single):single;
         begin
         F1:=sin(x);
         end;
function f2(x:single):single;
         begin
         f2:=cos(x);
         end;
begin
     writeln('Table 1:');
     TabFunc(@f1,0,2,10,masx1,masf1);
     writeln('Table 1:');
   for i:=1 to 10 do
       writeln (masx1[i]:4:1,' ', masf1[i]:4:1);
     writeln('Table 2:');
     TabFunc(@f2,0,2,10,masx2,masf2);
     writeln('Table 2:');
   for i:=1 to 20 do
       writeln (masx2[i]:4:1,' ', masf2[i]:4:1);


   readln;
end.

