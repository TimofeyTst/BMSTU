program Example3Okrezhnost;
   Var E,R,a,n:extended;
begin
  write('Pogreshnost= ');
  readln(E);
  write('Radius= ');
  readln(R);
  a:=R;
  n:=6;
       while (2*Pi*R-a*n)>E do
       begin
       a:=sqrt(2*sqr(R)-2*R*sqrt(sqr(R)-sqr(a)/4));
       n:=2*n;
       end;
  writeln(' Perimetr= ',a*n:20:16);
  writeln('  Dlina= ',2*Pi*r:20:16);
  writeln('   Raznica= ', 2*pi*r-a*n:20:16);
  writeln('                 Kol-vo storon ygolnika',n:10:0);
  readln;
end.

