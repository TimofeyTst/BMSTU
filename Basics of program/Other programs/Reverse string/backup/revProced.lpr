program revProced;
procedure revp(var st:shortstring; n:byte);
var A:char;
begin
     if n<=length(st) div 2 then
     begin
       A:=st[n];
       st[n]:=st[length(st)-n+1];
       st[length(st)-n+1]:=A;
       revp(st,n+1);
     end;
end;

var s:shortstring;
begin
  write('s: ');
  readln(s);
  revp(s,1);
  writeln(s);
  readln
end.

