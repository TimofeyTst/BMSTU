unit functions;

interface
uses
  Classes, SysUtils;
type fuct=function (x:single):single;
procedure magic(f1,f2,f3:fuct;x:single);


implementation
procedure magic(f1,f2,f3:fuct;x:single;var result:single);
begin
    result:=f1(x)*sqr(x)-f2(x)*x+f3(x);
end;
end.

