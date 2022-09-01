program FUNandPROC;
var t,y:integer; r:string;
  function nod(a,b:integer):string;
  begin
  while a<>b do
  begin
    if a>b then
    a:=a-b
    else b:=b-a;
    writeln(' a = ',a, ' b = ',b);
  end;
  str(a,nod);
  end;
begin
  writeln('Vvedite 2 chisla, nod kotorix bydem c4itat:');
  readln(t,y);
  r:=nod(t,y);
  writeln('Sobstvenno nod = ',r);
  if length(r)=1 then writeln (' nod sostoit iz ',length(r), ' razryda')
  else writeln (' nod sostoit iz ',length(r), ' razrydov');
  writeln('t = ',t, ' y = ',y);
  readln
end.

