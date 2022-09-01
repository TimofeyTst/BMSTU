program Experiment_21_10_2021;
type fuct=function (x:single;y:integer):single;
procedure magic(f1,f2,f3:fuct;x:single;y:integer;var result:single);
begin
    result:=f1(x,y)+f2(x,y)+f3(x,y);
end;




function f1(x:single):single;
begin
  f1:=x-5;
end;
function f2(x:single):single;
begin
  f2:=x+5;
end;
function f3(x:single):single;
begin
  f3:=x/5;
end;
var x,res1,res2:single;
begin
  x:=6;
  magic(@f1,@f2,@f3,x,res1);
  writeln('1) x = ',x:1:1,' F1=cos(x), F2=-2*cos(x), F3=x5');
  writeln('Result = ',res1:20:16);
  writeln;
  readln
end.

