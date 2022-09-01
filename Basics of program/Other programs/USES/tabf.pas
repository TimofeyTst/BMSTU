unit TabF;

interface
uses
  Classes, SysUtils;
Type func=function(x:single):single;
procedure Tabfunc(f:func;a,b:single;n:integer;var masx,masf:array of single);

implementation
procedure Tabfunc(f:func;a,b:single;n:integer;var masx,masf:array of single);
var
  i:integer;
  h:single;
begin
     h:=(a-b)/(n);
     for i:=0 to n-1 do
     begin
         Masx[i]:=a+h*i;
         masf[i]:=f(masx[i]);
     end;
end;

end.

