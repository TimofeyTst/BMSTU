program example112;
var y1,x,y:extended; y2:single;
begin
  write('x= ');
  readln(x);
  y1:=(exp(x)-exp(-x))/2;
  y2:=(exp(x)+exp(-x))/2;
  y:=sqr(y2)-sqr(y1);
  writeln ('y1= ',y1:20:16);
  writeln ('y2= ',y2:20:16);
  writeln ('y= ',y:20:16);
  if y>=1 then
  writeln ('Absolut pogr= ',y-1:20:16)
  else writeln ('Absolut pogr = ', 1-y:20:16);
  if y>=1 then
  Writeln ('otnosit pogr= ',(y-1)/y:20:16)
else writeln ('Otnosit pogr = ', (1-y)/y:20:16);
  readln;
end.

