program Lab3Schet;
var n,x,y:integer;
begin
  for n:=8 to 100 do
  begin
  if n mod 3 = 0 then
     x:=0
     else if n mod 5 = 0 then
        x:=n div 5
        else if n mod 3 = 1 then
           x:=2
           else x:=1;
  y:=(n-5*x) div 3;
  writeln('Pri n = ',n,'  x= ',x, '  y= ',y);
  end;
  readln;
end.

