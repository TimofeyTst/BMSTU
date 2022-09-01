program Pods5et_to4nosti_1;
var
    k,a,b,i,n:integer;
     e,S2,S1,d,x:real;
begin
  k:=0;
  n:=1;
  s1:=0;
  s2:=0;
  write('a= ');
  readln(a);
  write('b= ');
  readln(b);
  write('e= ');
  readln(e);
  if (a<=0) or (b<=0) or (e<=0) then
     writeln('Error');

  d:=(b-a)/n;

  repeat

  k:=k+1;
            s1:=s2;
            d:=d/2;
            n:=2*n;
            s2:=0;
            x:=a;
            for i:=1 to n do
                begin
                     s2:=s2+(sqr(x)-1)*d;
                     x:=x+d;
                end;
  until (abs((s2-s1))<e);
  writeln('Ploshad c tornostu ',e:1:5, ' = ', S2:10:16);
  writeln('Pri atom n = ',n, ' cikl prognalsya ', k, ' raz');
  readln
end.

