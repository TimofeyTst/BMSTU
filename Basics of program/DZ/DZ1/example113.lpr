program example113;
var x,y1,y2,y:extended;
begin
write('x= ');
readln(x);
y1:=sin(x);
y2:=cos(x);
y:=sqr(y1)+sqr(y2);
writeln('sin^2(x)+cos^2(x)=',y:20:16);
readln;
end.

