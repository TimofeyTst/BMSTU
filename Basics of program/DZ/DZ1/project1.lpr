program example2;
uses
  SysUtils;
Var
  y:real;
begin
  y:=1;
  WriteLn('Start y=',y:20:16);
  Readln;
    y:= y/6000;
  y:= exp(y);                  {y = ex}
  y:= sqrt(y);                 {Квадратный корень}
    y:= y / 14;
    y:=14*y;
  Y:= sqr(y);                  {Y = y2}
    y:=ln(y);
    y:= 6000*y;
  WriteLn('Finish y=', y:20:16);
  writeln ('Absolut pogr = ', y-1:20:16);
  writeln ('Otnosit pogr = ', (y-1)/y:20:16);
  Readln;
end.
