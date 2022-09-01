program DZ2_4;
uses functions;
function f1(x:single):single;
begin
  f1:=cos(x);
end;
function f2(x:single):single;
begin
  f2:=-2*cos(x);
end;
function f3(x:single):single;
begin
  f3:=x*x*x*x*x;
end;
function f11(x:single):single;
begin
  f11:=ln(-x);
end;
function f12(x:single):single;
begin
  f12:=sin(x*x);
end;
function f13(x:single):single;
begin
  f13:=x-1;
end;
var x,res1,res2:single;
begin
  x:=1.2;
  magic(@f1,@f2,@f3,x,res1);
  writeln('1) x = ',x:1:1,' F1=cos(x), F2=-2*cos(x), F3=x5');
  writeln('Result = ',res1:20:16);
  writeln;
  x:=-0.5;
  magic(@f11,@f12,@f13,x,res2);
  writeln('2) x = ',x:1:1,' F1=cos(x), F2=-2*cos(x), F3=x5');
  writeln('Result = ',res2:20:16);
  readln
end.

