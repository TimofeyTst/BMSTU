program example12;
var x:real;
begin
  write('x=');
  readln(x);
            If x<-1 then
            writeln('f(x)=',-1/x:20:16)
            else if x<2 then
                 writeln('f(x)=',sqr(x):20:16)
                 else writeln ('f(x)=',4);
  readln;
end.

