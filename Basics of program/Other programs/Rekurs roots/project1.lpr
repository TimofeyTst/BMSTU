program project1;
Type func=function(x:real):real;
  function f1 (x:real):real;
begin
   result:=(x+1);
end;
  function f2(x:real):real;
begin
    result:=(x+16);
end;
procedure TabP(a,b,e:real;f:func;var x:real);
var h:real;
begin
    h:=(a+b)/2;
    if abs(f(h))<e then x:=h
    else if f(h)*f(a)<0 then TabP(a,h,e,f,x)
    else Tabp(h,b,e,f,x);
end;

var a,b,e,r1,r2:real;
begin
  writeln('Vvedi a,b,e: ');
  readln(a,b,e);
  tabp(a,b,e,@f1,r1);
  tabp(a,b,e,@f2,r2);
  Writeln('Koren 1: ',r1:2:1);
  readln;
  writeln('Koren 2: ',r2:2:1);
  readln;
end.

