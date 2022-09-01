program TIM_1000;
type mas=array [1..10] of real;
  func=function (x:real):real;
 procedure Tabrek(masx,masy:mas;a,b,h,i:integer;f:func);
 begin
     if a<=b then
     begin
     Masx[i]:=a;
     Masy[i]:=f(a);
     writeln('x ',masx[i]:3:1, ' y ',masy[i]:3:1);
     Tabrek(masx,masy,a+h,b,h,i+1,f);
     end;
 end;
function f1(x:real):real;
begin
    result:=(x*x-2*x+1);
end;
var x,y:mas; a,b,h,i:integer;
begin
     Write('Vvedite a,b,h: ');
     read(a,b,h);
     i:=1;
     writeln('Tabulyciya: ');
     Tabrek(x,y,a,b,h,i,@f1);
readln;
readln
end.

