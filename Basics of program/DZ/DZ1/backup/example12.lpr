program example12;
var x:real;
begin
  write('x=');
  readln(x);
            If x<-1 then
            writeln('f(x)=',-1/x)
            else if x<2 then
                 writeln('f(x)=',sqr(x))
                 else writeln ('f(x)=',4);
  readln;
end.

